# $NetBSD$
#

DISTNAME=	rpki-svn
PKGNAME=	rpki-svn-
CATEGORIES=	net security
MASTER_SITES=	# not defined

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://rpki.net/
COMMENT=	RPKI package collection
LICENSE=	original-bsd

SVN_REPOSITORIES=	rpki
SVN_ROOT.rpki=		http://subvert-rpki.hactrn.net/
SVN_MODULE.rpki=	rpki
NO_CHECKSUM=		yes

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

USE_TOOLS+=	perl python

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
#CONFIGURE_ARGS+=	--disable-django
#CONFIGURE_ARGS+=	--disable-system-openssl

WRKSRC=			${WRKDIR}/rpki

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

INSTALLATION_DIRS=	bin

.include "../../lang/perl5/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
