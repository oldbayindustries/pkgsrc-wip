# $NetBSD$

DISTNAME=	gwsmhg-0.8.1
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gwsmhg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gwsmhg.sourceforge.net/
COMMENT=	Mercurial PyGtk GUI client
LICENSE=	gnu-gpl-v2

DEPENDS+=	mercurial>=1.3.1:../../devel/mercurial
DEPENDS+=	${PYPKGPREFIX}-gobject>=2.18.0:../../devel/py-gobject
DEPENDS+=	${PYPKGPREFIX}-gtksourceview>=2.6.0:../../x11/gtksourceview
DEPENDS+=	${PYPKGPREFIX}-gtk2>=1.99.12:../../x11/py-gtk2

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes
PYTHON_VERSIONED_DEPENDENCIES=	cairo
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-gtk2, py-gobject

.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
