# $NetBSD$

DISTNAME=	redis-2.8.0
PKG=		redis-py
PKGNAME=	${PYPKGPREFIX}-${PKG}-${DISTNAME:S/redis-//}
CATEGORIES=	databases
MASTER_SITES=	https://pypi.python.org/packages/source/r/redis/
#DIST_SUBDIR=	${PKG}-${DISTNAME}
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/andymccurdy/redis-py/
COMMENT=	Redis Python client
LICENSE=	mit

DEPENDS+=	redis-[0-9]*:../../databases/redis

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
