$NetBSD$

--- base/process_util_netbsd.cc.orig	2011-04-26 05:17:12.000000000 +0000
+++ base/process_util_netbsd.cc
@@ -0,0 +1,358 @@
+// Copyright (c) 2009 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "base/process_util.h"
+
+#include <ctype.h>
+#include <dirent.h>
+#include <dlfcn.h>
+#include <errno.h>
+#include <fcntl.h>
+#include <sys/time.h>
+#include <sys/types.h>
+#include <sys/wait.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#include <time.h>
+#include <unistd.h>
+
+#include "base/file_util.h"
+#include "base/logging.h"
+#include "base/string_number_conversions.h"
+#include "base/string_split.h"
+#include "base/string_tokenizer.h"
+#include "base/string_util.h"
+#include "base/sys_info.h"
+#include "base/threading/thread_restrictions.h"
+
+namespace base {
+
+ProcessId GetParentProcessId(ProcessHandle process) {
+  struct kinfo_proc2 info;
+  int mib[6];
+  size_t info_size = sizeof(info);
+
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_PROC;
+  mib[2] = KERN_PROC_PID;
+  mib[3] = process;
+  mib[4] = info_size;
+  mib[5] = 400; /* XXX */
+
+  if (sysctl(mib, 6, &info, &info_size, NULL, 0) < 0)
+    return -1;
+
+  return info.p_ppid;
+}
+
+FilePath GetProcessExecutablePath(ProcessHandle process) {
+  printf("%s\n", __PRETTY_FUNCTION__);
+
+  FilePath stat_file("/proc");
+  stat_file = stat_file.Append(base::IntToString(process));
+  stat_file = stat_file.Append("exe");
+  FilePath exe_name;
+  if (!file_util::ReadSymbolicLink(stat_file, &exe_name)) {
+    // No such process.  Happens frequently in e.g. TerminateAllChromeProcesses
+    return FilePath();
+  }
+  return exe_name;
+}
+
+ProcessIterator::ProcessIterator(const ProcessFilter* filter)
+  : index_of_kinfo_proc_(),
+  filter_(filter) {
+
+  int mib[6];
+
+  printf("%s\n", __PRETTY_FUNCTION__);
+
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_PROC;
+  mib[2] = KERN_PROC_UID;
+  mib[3] = getuid();
+  mib[4] = sizeof(struct kinfo_proc2);
+  mib[5] = 0;
+
+  bool done = false;
+  int try_num = 1;
+  const int max_tries = 10;
+
+  do {
+    size_t len = 0;
+    if (sysctl(mib, 6, NULL, &len, NULL, 0) <0 ){
+      LOG(ERROR) << "failed to get the size needed for the process list";
+      kinfo_procs_.resize(0);
+      done = true;
+    } else {
+      size_t num_of_kinfo_proc = len / sizeof(struct kinfo_proc2);
+      // Leave some spare room for process table growth (more could show up
+      // between when we check and now)
+      num_of_kinfo_proc += 16;
+      kinfo_procs_.resize(num_of_kinfo_proc);
+      len = num_of_kinfo_proc * sizeof(struct kinfo_proc2);
+      if (sysctl(mib, 6, &kinfo_procs_[0], &len, NULL, 0) <0) {
+        // If we get a mem error, it just means we need a bigger buffer, so
+        // loop around again.  Anything else is a real error and give up.
+        if (errno != ENOMEM) {
+          LOG(ERROR) << "failed to get the process list";
+          kinfo_procs_.resize(0);
+          done = true;
+        }
+      } else {
+        // Got the list, just make sure we're sized exactly right
+        size_t num_of_kinfo_proc = len / sizeof(struct kinfo_proc2);
+        kinfo_procs_.resize(num_of_kinfo_proc);
+        done = true;
+      }
+    }
+  } while (!done && (try_num++ < max_tries));
+
+  if (!done) {
+    LOG(ERROR) << "failed to collect the process list in a few tries";
+    kinfo_procs_.resize(0);
+  }
+}
+
+ProcessIterator::~ProcessIterator() {
+}
+
+bool ProcessIterator::CheckForNextProcess() {
+  std::string data;
+
+  printf("%s\n", __PRETTY_FUNCTION__);
+
+  for (; index_of_kinfo_proc_ < kinfo_procs_.size(); ++ index_of_kinfo_proc_) {
+    int mib[3];
+    size_t len;
+    struct kinfo_proc2 kinfo = kinfo_procs_[index_of_kinfo_proc_];
+
+    if ((kinfo.p_pid > 0) && (kinfo.p_stat == SZOMB))
+      continue;
+
+    mib[0] = CTL_KERN;
+    mib[1] = KERN_PROC_ARGS;
+    mib[2] = kinfo.p_pid;
+
+    len = 0;
+    if (sysctl(mib, 3, NULL, &len, NULL, 0) < 0) {
+      LOG(ERROR) << "failed to figure out the buffer size for a command line";
+      continue;
+    }
+
+    data.resize(len);
+
+    if (sysctl(mib, 3, &data[0], &len, NULL, 0) < 0) {
+      LOG(ERROR) << "failed to fetch a commandline";
+      continue;
+    }
+
+    std::string delimiters;
+    delimiters.push_back('\0');
+    Tokenize(data, delimiters, &entry_.cmd_line_args_);
+
+    size_t exec_name_end = data.find('\0');
+    if (exec_name_end == std::string::npos) {
+      LOG(ERROR) << "command line data didn't match expected format";
+      continue;
+    }
+
+    entry_.pid_ = kinfo.p_pid;
+    entry_.ppid_ = kinfo.p_ppid;
+    entry_.gid_ = kinfo.p__pgid;
+
+    size_t last_slash = data.rfind('/', exec_name_end);
+    if (last_slash == std::string::npos)
+      entry_.exe_file_.assign(data, 0, exec_name_end);
+    else
+      entry_.exe_file_.assign(data, last_slash + 1,
+                              exec_name_end - last_slash - 1);
+
+    // Start w/ the next entry next time through
+    ++index_of_kinfo_proc_;
+
+    return true;
+  }
+  return false;
+}
+
+bool NamedProcessIterator::IncludeEntry() {
+  return (executable_name_ == entry().exe_file() &&
+		            ProcessIterator::IncludeEntry());
+}
+
+
+ProcessMetrics::ProcessMetrics(ProcessHandle process)
+    : process_(process),
+      last_time_(0),
+      last_system_time_(0),
+      last_cpu_(0) {
+
+  processor_count_ = base::SysInfo::NumberOfProcessors();
+}
+
+// static
+ProcessMetrics* ProcessMetrics::CreateProcessMetrics(ProcessHandle process) {
+  return new ProcessMetrics(process);
+}
+
+size_t ProcessMetrics::GetPagefileUsage() const {
+  struct kinfo_proc2 info;
+  int mib[6];
+  size_t info_size = sizeof(info);
+
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_PROC;
+  mib[2] = KERN_PROC_PID;
+  mib[3] = process_;
+  mib[4] = info_size;
+  mib[5] = 400; /* XXX */
+
+  if (sysctl(mib, 6, &info, &info_size, NULL, 0) < 0)
+    return 0;
+
+  return (info.p_vm_tsize + info.p_vm_dsize + info.p_vm_ssize);
+}
+
+size_t ProcessMetrics::GetPeakPagefileUsage() const {
+	printf("%s\n", __PRETTY_FUNCTION__);
+
+  return 0;
+}
+
+size_t ProcessMetrics::GetWorkingSetSize() const {
+  struct kinfo_proc2 info;
+  int mib[6];
+  size_t info_size = sizeof(info);
+
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_PROC;
+  mib[2] = KERN_PROC_PID;
+  mib[3] = process_;
+  mib[4] = info_size;
+  mib[5] = 400; /* XXX */
+
+  if (sysctl(mib, 6, &info, &info_size, NULL, 0) < 0)
+    return 0;
+
+  return info.p_vm_rssize * getpagesize();
+}
+
+size_t ProcessMetrics::GetPeakWorkingSetSize() const {
+	printf("%s\n", __PRETTY_FUNCTION__);
+
+  return 0;
+}
+
+bool ProcessMetrics::GetMemoryBytes(size_t* private_bytes,
+                                    size_t* shared_bytes) {
+  WorkingSetKBytes ws_usage;
+
+  if (!GetWorkingSetKBytes(&ws_usage))
+    return false;
+
+  if (private_bytes)
+    *private_bytes = ws_usage.priv << 10;
+
+  if (shared_bytes)
+    *shared_bytes = ws_usage.shared * 1024;
+
+  return true;
+}
+
+bool ProcessMetrics::GetWorkingSetKBytes(WorkingSetKBytes* ws_usage) const {
+// TODO(bapt) be sure we can't be precise
+  size_t priv = GetWorkingSetSize();
+  if (!priv)
+    return false;
+  ws_usage->priv = priv / 1024;
+  ws_usage->shareable = 0;
+  ws_usage->shared = 0;
+
+  return true;
+}
+
+bool ProcessMetrics::GetIOCounters(IoCounters* io_counters) const {
+  return false;
+}
+
+static int GetProcessCPU(pid_t pid) {
+  struct kinfo_proc2 info;
+  int mib[6];
+  size_t info_size = sizeof(info);
+
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_PROC;
+  mib[2] = KERN_PROC_PID;
+  mib[3] = pid;
+  mib[4] = info_size;
+  mib[5] = 400; /* XXX */
+
+  if (sysctl(mib, 6, &info, &info_size, NULL, 0) < 0)
+    return 0;
+
+  return info.p_pctcpu;
+}
+
+double ProcessMetrics::GetCPUUsage() {
+  struct timeval now;
+
+  int retval = gettimeofday(&now, NULL);
+  if (retval)
+    return 0;
+
+  int64 time = TimeValToMicroseconds(now);
+
+  if (last_time_ == 0) {
+    // First call, just set the last values.
+    last_time_ = time;
+    last_cpu_ = GetProcessCPU(process_);
+    return 0;
+  }
+
+  int64 time_delta = time - last_time_;
+  DCHECK_NE(time_delta, 0);
+
+  if (time_delta == 0)
+    return 0;
+
+  int cpu = GetProcessCPU(process_);
+
+  last_time_ = time;
+  last_cpu_ = cpu;
+
+  double percentage = static_cast<double>((cpu * 100.0) / FSCALE);
+
+  return percentage;
+}
+
+size_t GetSystemCommitCharge() {
+  int mib[2], pagesize;
+  struct vmtotal vmtotal;
+  unsigned long mem_total, mem_free, mem_inactive;
+  size_t len = sizeof(vmtotal);
+
+  printf("%s\n", __PRETTY_FUNCTION__);
+
+  mib[0] = CTL_VM;
+  mib[1] = VM_METER;
+
+  if (sysctl(mib, 2, &vmtotal, &len, NULL, 0) < 0)
+    return 0;
+
+  mem_total = vmtotal.t_vm;
+  mem_free = vmtotal.t_free;
+  mem_inactive = vmtotal.t_vm - vmtotal.t_avm;
+
+  pagesize = getpagesize();
+
+  return mem_total - (mem_free*pagesize) - (mem_inactive*pagesize);
+}
+
+void EnableTerminationOnOutOfMemory() {
+  NOTIMPLEMENTED();
+  return;
+}
+}
