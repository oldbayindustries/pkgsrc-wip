# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/08/01 22:38:44 minskim Exp $

BUILDLINK_TREE+=	ETL

.if !defined(ETL_BUILDLINK3_MK)
ETL_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.ETL?=	build
BUILDLINK_API_DEPENDS.ETL+=	ETL>=0.04.13
BUILDLINK_PKGSRCDIR.ETL?=	../../wip/ETL
.endif # ETL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ETL
