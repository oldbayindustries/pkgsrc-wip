# $NetBSD$

DISTNAME=		CGI-Application-Plugin-TT-1.05
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/CGI-Application-Plugin-TT/
COMMENT=		Add Template Toolkit support to CGI::Application
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-CGI-Application>=4.0:../../www/p5-CGI-Application
DEPENDS+=		p5-Template-Toolkit>=2.0:../../www/p5-Template-Toolkit
DEPENDS+=		p5-CGI-Application-Plugin-DevPopup>=0:../../wip/p5-CGI-Application-Plugin-DevPopup

PERL5_PACKLIST=		auto/CGI/Application/Plugin/TT/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
