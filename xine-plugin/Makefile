# $NetBSD$
#

DISTNAME=	xine-plugin-1.0.2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xine/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xine-project.org/
COMMENT=	Plugin for www/firefox for using multimedia/xine-lib
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--with-plugindir=${PREFIX}/lib/firefox/plugins

.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
