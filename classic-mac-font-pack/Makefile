# $NetBSD$
#

DISTNAME=	classic-mac-font-pack-201401
CATEGORIES=	fonts

# Included fonts (or homages/reproductions) are the "city" fonts (Athens,
# Cairo, Chicago, Geneva, London, Los Angeles, Monaco, New York, San
# Francisco, Toronto, Venice), Apple Garamond, Charcoal, and Motter Tektura.
# This package will hit 1.0 when all of these, or reasonable facsimiles,
# are available gratis.

#DISTFILES+=	alexandria.zip
DISTFILES+=	Cairo%20Unicode.tgz
SITES.Cairo%20Unicode.tgz=	http://christtrekker.users.sourceforge.net/fnt/
#DISTFILES+=	Cairo_TTF.zip
#SITES.Cairo_TTF.zip=	http://www.masterstech-home.com/The_Library/Font_Samples/Font_Sample_Files/PC/C/
# File is invalid?
#DISTFILES+=	Chicago_TTF.zip
#SITES.Chicago_TTF.zip=	http://www.masterstech-home.com/The_Library/Font_Samples/Font_Sample_Files/PC/C/
#DISTFILES+=	CHICAGO.ttf
#SITES.CHICAGO.ttf=	http://www.fontyukle.com/en/
DISTFILES+=	Geneva_TTF.zip
SITES.Geneva_TTF.zip=	http://www.masterstech-home.com/The_Library/Font_Samples/Font_Sample_Files/PC/G/
DISTFILES+=	London.ttf.gz
SITES.London.ttf.gz=	http://68kmla.net/wiki/uploads/4/4a/
DISTFILES+=	CityOfAngelsTTF.zip
SITES.CityOfAngelsTTF.zip=	http://68kmla.net/wiki/uploads/0/0a/
DISTFILES+=	MONACO.TTF
SITES.MONACO.TTF=	http://www.webdevkungfu.com/files/
# Cf. http://www.gringod.com/wp-upload/software/Fonts/Monaco_5.1.ttf
# Cf. http://www.gringod.com/wp-upload/software/Fonts/Monaco_Linux.ttf
# This binhex file yields a StuffIt archive, which there is no practical way
# to extract in the general case.
#DISTFILES+=	NewYork_TT.hqx
#SITES.NewYork_TT.hqx=	http://www.masterstech-home.com/The_Library/Font_Samples/Font_Sample_Files/Mac/N/
# bmake doesn't like this filename??
#DISTFILES+=	Fernando%20Regular%20(2).ttf
#SITES.Fernando%20Regular%20(2).ttf=	http://ufonts.com/bin/
# Brampton is not yet complete.
DISTFILES+=	Brampton.tgz
SITES.Brampton.tgz=	http://christtrekker.users.sourceforge.net/fnt/
#DISTFILES+=	genoa.zip

# This next one has Apple Garamond.
# I don't think it is freely distributable though.
#DISTFILES+=	macfonts.tar.gz
#SITES.macfonts.tar.gz=	http://ubuntu-debs.googlecode.com/files/
DISTFILES+=	virtue.zip
SITES.virtue.zip=	http://www.scootergraphics.com/virtue/
#DISTFILES+=	Mottek.zip
#SITES.Mottek.zip=	http://www.searchfreefonts.com/assets/downloads/

OWNER=		christtrekker@users.sourceforge.net
HOMEPAGE=	http://68kmla.net/wiki/User:ChristTrekker/Choosing_Mac_fonts_for_the_web
COMMENT=	Outline fonts modeled after those of the vintage 68k Macintosh era
LICENSE=	generic-nonlicense
RESTRICTED=	Various.

WRKSRC=		${WRKDIR}
TTFPATH=	lib/X11/fonts/TTF
FONTS_DIRS.ttf+=	${PREFIX}/${TTFPATH}
INSTALLATION_DIRS=	${TTFPATH}
NO_CONFIGURE=	yes
NO_BUILD=	yes

# OPTIONS
PKG_OPTIONS_VAR=	PKG_OPTIONS.classic-mac-font-pack
PKG_SUPPORTED_OPTIONS=	apgar

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

PLIST_VARS+=	apgar
.if !empty(PKG_OPTIONS:Mapgar)
PLIST.apgar=	yes
.endif

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/*.[Tt][Tt][Ff] ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/brampton/Brampton.ttf ${DESTDIR}${FONTS_DIRS.ttf}
	if [ "x${PLIST.apgar}" = "xyes" ]; then \
		${INSTALL_DATA} ${WRKSRC}/macfonts/AppleGaramond*.[Tt][Tt][Ff] ${DESTDIR}${FONTS_DIRS.ttf}; \
	fi
# install doco too!

DEPENDS+=	urbanrenewal-ttf-[0-9]*:../../fonts/urbanrenewal-ttf
# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
