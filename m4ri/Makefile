# $NetBSD$
#

DISTNAME=	m4ri-20111203
CATEGORIES=	math
MASTER_SITES=	http://m4ri.sagemath.org/downloads/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://m4ri.sagemath.org/
COMMENT=	M4RI is a library for fast arithmetic with dense matrices over F2
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	m4ri.pc.in

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
