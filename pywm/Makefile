# $NetBSD$

DISTNAME=		pywm-0.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		wm
MASTER_SITES=		http://www.freenet.org.nz/python/pywm/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.freenet.org.nz/python/pywm/
COMMENT=		Window manager in Python

BUILD_DEPENDS=		${PYPKGPREFIX}-pyrex>=0.8.1:../../lang/py-pyrex

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-pyrex

.include "../../lang/python/extension.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
