# $NetBSD: Makefile,v 1.21 2011/05/09 03:12:07 dbj Exp $

DISTNAME=		fftw-2.1.5
PKGNAME=		fftw2-openmpi-2.1.5
CATEGORIES=		math
MASTER_SITES=		ftp://ftp.fftw.org/pub/fftw/ \
			http://www.fftw.org/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.fftw.org/
COMMENT=		Collection of fast C routines to compute DFTs
LICENSE=		gnu-gpl-v1

PKG_INSTALLATION_TYPES=	overwrite pkgviews

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared \
			--enable-mpi \
			--prefix=${MPI_PREFIX:Q}
USE_LANGUAGES=		c fortran77
USE_TOOLS+=		gmake makeinfo
# INFO_FILES=		# PLIST

# USE_LIBTOOL=		yes

.include "../../mk/bsd.prefs.mk"
.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-i386-hacks
.endif

.include "../../wip/openmpi163/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
