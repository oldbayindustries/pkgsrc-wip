# $NetBSD$
#

DISTNAME=	ccrypt-1.9
CATEGORIES=	security
MASTER_SITES=	http://www.mathstat.dal.ca/~selinger/ccrypt/download/

MAINTAINER=	poff@sixbit.org
HOMEPAGE=	http://www.mathstat.dal.ca/~selinger/ccrypt/
COMMENT=	Encrypts/decrypts files using Rijndael block cipher
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS=		perl intltool
USE_PKGLOCALEDIR=	yes
CONFIGURE_ENV=		EMACS=:	# don't require Emacs

.include "../../mk/bsd.pkg.mk"
