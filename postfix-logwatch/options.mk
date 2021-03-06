# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.postfix-logwatch
PKG_SUPPORTED_OPTIONS+=	logwatch

PKG_SUGGESTED_OPTIONS+=	logwatch

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlogwatch)
.include "../../wip/postfix-logwatch/Makefile.logwatch"
.else
.include "../../wip/postfix-logwatch/Makefile.standalone"
.endif
