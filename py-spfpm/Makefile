# $NetBSD$
#

DISTNAME=	spfpm-0.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyfixedpoint/}
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pyfixedpoint.sourceforge.net/
COMMENT=	Tools for arithmetic on fixed-point (binary) numbers
LICENSE=	python-software-foundation

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} testFixedPoint.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
