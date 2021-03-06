# $NetBSD: Makefile,v 1.10 2013/09/09 14:07:59 wiz Exp $

DISTNAME=	bup-0.25
CATEGORIES=	sysutils
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/bup/bup
COMMENT=	Highly efficient file backup system based on the git packfile format
LICENSE=	gnu-gpl-v2

DEPENDS+=	par2-[0-9]*:../../archivers/par2
DEPENDS+=	${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline
DEPENDS+=	${PYPKGPREFIX}-tornado-[0-9]*:../../www/py-tornado
DEPENDS+=	git-base-[0-9]*:../../devel/git-base

# actually a TEST_DEPENDS
BUILD_DEPENDS+=	rsync>=3.0:../../net/rsync
BUILD_DEPENDS+=	rdiff-backup-[0-9]*:../../sysutils/rdiff-backup

PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-fuse-bindings

GIT_REPOSITORIES=	bup
GIT_REPO.bup=		git://github.com/bup/bup.git

WRKSRC=                 ${WRKDIR}/bup

TEST_TARGET=	test

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	PYTHON=${PYTHONBIN}
MAKE_FLAGS+=	MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}

USE_TOOLS+=		bash gmake perl
REPLACE_PERL=		format-subst.pl wvtestrun
REPLACE_PYTHON+=	cmd/bloom-cmd.py
REPLACE_PYTHON+=	cmd/cat-file-cmd.py
REPLACE_PYTHON+=	cmd/daemon-cmd.py
REPLACE_PYTHON+=	cmd/damage-cmd.py
REPLACE_PYTHON+=	cmd/drecurse-cmd.py
REPLACE_PYTHON+=	cmd/fsck-cmd.py
REPLACE_PYTHON+=	cmd/ftp-cmd.py
REPLACE_PYTHON+=	cmd/fuse-cmd.py
REPLACE_PYTHON+=	cmd/help-cmd.py
REPLACE_PYTHON+=	cmd/index-cmd.py
REPLACE_PYTHON+=	cmd/init-cmd.py
REPLACE_PYTHON+=	cmd/join-cmd.py
REPLACE_PYTHON+=	cmd/list-idx-cmd.py
REPLACE_PYTHON+=	cmd/ls-cmd.py
REPLACE_PYTHON+=	cmd/margin-cmd.py
REPLACE_PYTHON+=	cmd/memtest-cmd.py
REPLACE_PYTHON+=	cmd/meta-cmd.py
REPLACE_PYTHON+=	cmd/midx-cmd.py
REPLACE_PYTHON+=	cmd/mux-cmd.py
REPLACE_PYTHON+=	cmd/newliner-cmd.py
REPLACE_PYTHON+=	cmd/on--server-cmd.py
REPLACE_PYTHON+=	cmd/on-cmd.py
REPLACE_PYTHON+=	cmd/random-cmd.py
REPLACE_PYTHON+=	cmd/restore-cmd.py
REPLACE_PYTHON+=	cmd/save-cmd.py
REPLACE_PYTHON+=	cmd/server-cmd.py
REPLACE_PYTHON+=	cmd/split-cmd.py
REPLACE_PYTHON+=	cmd/tag-cmd.py
REPLACE_PYTHON+=	cmd/tick-cmd.py
REPLACE_PYTHON+=	cmd/version-cmd.py
REPLACE_PYTHON+=	cmd/web-cmd.py
REPLACE_PYTHON+=	cmd/xstat-cmd.py
REPLACE_PYTHON+=	main.py
REPLACE_PYTHON+=	wvtest.py

REPLACE_PYTHON+=	t/hardlink-sets
REPLACE_PYTHON+=	t/id-other-than
REPLACE_PYTHON+=	t/mksock
REPLACE_PYTHON+=	t/ns-timestamp-resolutions
REPLACE_PYTHON+=	t/root-status
REPLACE_PYTHON+=	t/unknown-owner

SUBST_CLASSES+=		python-c
SUBST_SED.python-c+=	-e 's,python -c,${PYTHONBIN} -c,'
SUBST_STAGE.python-c=	pre-configure
SUBST_FILES.python-c+=	t/lib.sh
SUBST_FILES.python-c+=	t/test-meta.sh
SUBST_MESSAGE.python-c=	Fixing python executable in tests.

REPLACE_BASH+=		cmd/import-rdiff-backup-cmd.sh
REPLACE_BASH+=		t/compare-trees
REPLACE_BASH+=		t/configure-sampledata
REPLACE_BASH+=		t/force-delete
REPLACE_BASH+=		t/subtree-hash
REPLACE_BASH+=		t/test-cat-file.sh
REPLACE_BASH+=		t/test-command-without-init-fails.sh
REPLACE_BASH+=		t/test-index-check-device.sh
REPLACE_BASH+=		t/test-meta.sh
REPLACE_BASH+=		t/test-redundant-saves.sh
REPLACE_BASH+=		t/test-restore-single-file.sh
REPLACE_BASH+=		t/test-rm-between-index-and-save.sh
REPLACE_BASH+=		t/test-save-creates-no-unrefs.sh
REPLACE_BASH+=		t/test.sh
REPLACE_BASH+=		wvtest-bup.sh

post-install:
#	${INSTALL_DATA} ${DOCDIR}/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/DESIGN ${DESTDIR}${PREFIX}/share/doc/bup
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/bup

.include "../../filesystems/py-fuse-bindings/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
