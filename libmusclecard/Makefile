# $NetBSD$

DISTNAME=		libmusclecard-1.3.3
CATEGORIES=		security
MASTER_SITES=		http://alioth.debian.org/download.php/1579/

MAINTAINER=		evaldo@gardenali.biz
HOMEPAGE=		http://www.musclecard.com/
COMMENT=		MUSCLE SmartCard framework support library

PKG_DESTDIR_SUPPORT=	none

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	--enable-muscledropdir=${PREFIX}/lib/pcsc-lite/drivers
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

.include "../../security/pcsc-lite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
