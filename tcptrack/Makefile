# $NetBSD$

DISTNAME=	tcptrack-1.4.0
CATEGORIES=	net
MASTER_SITES=	http://www.rhythm.cx/~steve/devel/tcptrack/release/${PKGVERSION_NOREV}/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rhythm.cx/~steve/devel/tcptrack/
COMMENT=	Watch TCP connections
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../devel/ncurses/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
