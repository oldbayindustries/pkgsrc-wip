$NetBSD$

Prototype for exit(3).

--- libc/error.c.orig	1988-12-30 09:50:06.000000000 +0000
+++ libc/error.c
@@ -3,6 +3,7 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 
 extern void warning();
 
