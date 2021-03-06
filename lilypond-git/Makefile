# $NetBSD: Makefile,v 1.86 2012/12/15 10:01:20 marino Exp $

DISTNAME=	lilypond-2.19.2
CATEGORIES=	print
MASTER_SITES=	http://download.linuxaudio.org/lilypond/sources/v2.19/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lilypond.org/
COMMENT=	GNU Music Typesetter
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	tex-metafont-[0-9]*:../../fonts/tex-metafont
BUILD_DEPENDS+=	tex-metapost-[0-9]*:../../graphics/tex-metapost
BUILD_DEPENDS+=	urw-fonts-[0-9]*:../../fonts/urw-fonts
BUILD_DEPENDS+=	intlfonts-[0-9]*:../../fonts/intlfonts
BUILD_DEPENDS+=	font-cronyx-cyrillic-[0-9]*:../../fonts/font-cronyx-cyrillic
BUILD_DEPENDS+=	kochi-ttf-[0-9]*:../../fonts/kochi-ttf
BUILD_DEPENDS+=	fontforge>=20060125:../../fonts/fontforge
BUILD_DEPENDS+=	t1utils>=1.33:../../fonts/t1utils
BUILD_DEPENDS+=	dblatex-[0-9]*:../../textproc/dblatex
BUILD_DEPENDS+=	rsync-[0-9]*:../../net/rsync
# pngtopnm
BUILD_DEPENDS+=	netpbm-[0-9]*:../../graphics/netpbm
# convert
BUILD_DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

DEPENDS+=	tex-cyrillic-[0-9]*:../../print/tex-cyrillic
DEPENDS+=	tex-psnfss-[0-9]*:../../fonts/tex-psnfss
DEPENDS+=	tex-epsf-[0-9]*:../../print/tex-epsf
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
# 1.7 coredumps when generating eps files
DEPENDS+=	potrace>=1.8:../../graphics/potrace

GIT_REPOSITORIES=	lilypond
GIT_REPO.lilypond=	git://git.savannah.gnu.org/lilypond.git

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_LANGUAGES=		c c++
USE_TOOLS+=		autoconf automake autoreconf bison flex gmake gs:run makeinfo perl pkg-config msgfmt
USE_TOOLS+=		texi2html zip
MAKE_FILE=		GNUmakefile

WRKSRC=			${WRKDIR}/lilypond

.include "../../mk/bsd.prefs.mk"

TEXINFO_REQD=		4.11
GCC_REQD+=		3.0.5

GNU_CONFIGURE_INFODIR=	${PREFIX}/${PKGINFODIR}
INFO_DIR=		${GNU_CONFIGURE_INFODIR}
INFO_FILES=		YES

CONFIGURE_ARGS+=	--disable-optimising
CONFIGURE_ARGS+=	--with-ncsb-dir=${PREFIX}/share/fonts/urw
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

REPLACE_PYTHON+= scripts/build/yyout2grammar.py
PLIST_SUBST+=	PKGVERSION=${PKGVERSION:S/nb${PKGREVISION}//}
PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 2014/01/28

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

# needs FlexLexer.h
.include "../../devel/flex/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
