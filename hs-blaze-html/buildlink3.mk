# $NetBSD$

BUILDLINK_TREE+=	hs-blaze-html

.if !defined(HS_BLAZE_HTML_BUILDLINK3_MK)
HS_BLAZE_HTML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-blaze-html+=	hs-blaze-html>=0.6.1
BUILDLINK_PKGSRCDIR.hs-blaze-html?=	../../wip/hs-blaze-html

.include "../../wip/hs-blaze-builder/buildlink3.mk"
.include "../../wip/hs-blaze-markup/buildlink3.mk"
.include "../../wip/hs-text/buildlink3.mk"
.endif	# HS_BLAZE_HTML_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-blaze-html
