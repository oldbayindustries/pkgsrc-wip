# $NetBSD$

BUILDLINK_TREE+=	hs-hashmap

.if !defined(HS_HASHMAP_BUILDLINK3_MK)
HS_HASHMAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hashmap+=	hs-hashmap>=1.2.0
BUILDLINK_PKGSRCDIR.hs-hashmap?=	../../wip/hs-hashmap

.include "../../wip/hs-hashable/buildlink3.mk"
.endif	# HS_HASHMAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hashmap
