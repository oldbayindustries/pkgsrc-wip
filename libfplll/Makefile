# $NetBSD$
#

DISTNAME=	libfplll-3.0.12
CATEGORIES=	math
MASTER_SITES=	http://perso.ens-lyon.fr/damien.stehle/downloads/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://perso.ens-lyon.fr/damien.stehle/#software
COMMENT=	Library for LLL-reduction of Euclidean lattices
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../devel/gmp/buildlink3.mk"
BUILDLINK_API_DEPENDS.mpfr+=	mpfr>=2.0.3
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
