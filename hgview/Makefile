# $NetBSD$

DISTNAME=	hgview-0.9.${HGVIEW_VER}
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.logilab.org/project/eid/3426
COMMENT=	GTK based replacement for hgview

PKG_DESTDIR_SUPPORT=	none

NO_CHECKSUM=		yes
PYDISTUTILSPKG=		yes
WRKSRC=			${WRKDIR}/hgview
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-gtk2

HG_REPOSITORIES=	hgview
HG_REPO.hgview=		http://www.logilab.org/hg/hgview

SUBST_CLASSES+=			installpath
SUBST_SED.installpath=		-e "s,share/man/man1,${PKGMANDIR}/man1,"
SUBST_FILES.installpath=	hgview/__pkginfo__.py
SUBST_STAGE.installpath=	post-extract
SUBST_MESSAGE.installpath=	Fix man page installation path.

.include "../../mk/bsd.prefs.mk"

HGVIEW_VER!=	${DATE} +%Y%m%d

.include "../../lang/python/extension.mk"
.include "../../wip/mk/hg-package.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
