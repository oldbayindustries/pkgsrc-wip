# $NetBSD$
#

DISTNAME=	PEAK-Rules-0.5a1.dev-r2707
EGG_NAME=	PEAK_Rules-0.5a1.dev_r2707
PKGNAME=	${PYPKGPREFIX}-peak-rules-0.5a1
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://peak.telecommunity.com/snapshots/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://peak.telecommunity.com/snapshots/
COMMENT=	Generic functions and business rules support systems

DEPENDS+=	${PYPKGPREFIX}-addons>=0.7:../../wip/py-addons
DEPENDS+=	${PYPKGPREFIX}-bytecodeassembler>=0.5.1:../../wip/py-bytecodeassembler
DEPENDS+=	${PYPKGPREFIX}-decoratortools>=1.8:../../wip/py-decoratortools
DEPENDS+=	${PYPKGPREFIX}-extremes>=1.1.1:../../wip/py-extremes

USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	share/doc/py-peak-rules

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} test_rules.py

post-install:
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DESTDIR}${PREFIX}/share/doc/py-peak-rules

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
