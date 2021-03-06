/**************************************************************************
 *                                                                        *
 *         Copyright (c) 2010 by Generalplus Technology Co., Ltd.         *
 *                                                                        *
 *  This software is copyrighted by and is the property of Generalplus    *
 *  Technology Co., Ltd. All rights are reserved by Generalplus Technology*
 *  Co., Ltd. This software may only be used in accordance with the       *
 *  corresponding license agreement. Any unauthorized use, duplication,   *
 *  distribution, or disclosure of this software is expressly forbidden.  *
 *                                                                        *
 *  This Copyright notice MUST not be removed or modified without prior   *
 *  written consent of Generalplus Technology Co., Ltd.                   *
 *                                                                        *
 *  Generalplus Technology Co., Ltd. reserves the right to modify this    *
 *  software without notice.                                              *
 *                                                                        *
 *  Generalplus Technology Co., Ltd.                                      *
 *  19, Innovation First Road, Science-Based Industrial Park,             *
 *  Hsin-Chu, Taiwan, R.O.C.                                              *
 *                                                                        *
 **************************************************************************/
#ifndef _REG_DISP1_H_
#define _REG_DISP1_H_

#include <mach/hardware.h>
#include <mach/typedef.h>

#define	LOGI_ADDR_DISP1_REG		(IO3_BASE + 0x20140)
/**************************************************************************
 *                          D A T A    T Y P E S                          *
 **************************************************************************/
typedef struct disp1Reg_s {
	volatile UINT32 disp1Ctrl;			/* 0x0140 ~ 0x0143 */
	volatile UINT32 disp1V_Period;		/* 0x0144 ~ 0x0147 */
	volatile UINT32 disp1VS_Width;		/* 0x0148 ~ 0x014b */
	volatile UINT32 disp1V_Start;		/* 0x014c ~ 0x014f */
	volatile UINT32 disp1V_End;			/* 0x0150 ~ 0x0153 */
	volatile UINT32 disp1H_Period;		/* 0x0154 ~ 0x0157 */
	volatile UINT32 disp1HS_Width;		/* 0x0158 ~ 0x015b */
	volatile UINT32 disp1H_Start;		/* 0x015c ~ 0x015f */
	volatile UINT32 disp1H_End;			/* 0x0160 ~ 0x0163 */
	volatile UINT32 disp1LineRGBOrder;	/* 0x0164 ~ 0x0167 */
	volatile UINT32 disp1Status;		/* 0x0168 ~ 0x016b */
	volatile UINT32 disp1MemBuffWR;		/* 0x016c ~ 0x016f */
	volatile UINT32 disp1MemBuffRD;		/* 0x0170 ~ 0x0173 */
	volatile UINT32 rsv174[3];			/* 0x0174 ~ 0x017f */
	volatile UINT32 disp1TE_Ctrl;		/* 0x0180 ~ 0x0183 */
	volatile UINT32 disp1TE_HsyncCNT;	/* 0x0184 ~ 0x0187 */
	volatile UINT32 disp1IntEN;			/* 0x0188 ~ 0x018b */
	volatile UINT32 disp1IntCLR;		/* 0x018c ~ 0x018f */
	volatile UINT32 rsv190[4];			/* 0x0190 ~ 0x019f */
	volatile UINT32 rsv1a0[4];			/* 0x01a0 ~ 0x01af */
	volatile UINT32 disp1VS_Start;		/* 0x01b0 ~ 0x01b3 */
	volatile UINT32 disp1VS_End;		/* 0x01b4 ~ 0x01b7 */
	volatile UINT32 disp1HS_Start;		/* 0x01b8 ~ 0x01bb */
	volatile UINT32 disp1HS_End;		/* 0x01bc ~ 0x01bf */
	volatile UINT32 rsv1c0[4];			/* 0x01c0 ~ 0x01cf */
	volatile UINT32 rsv1d0[4];			/* 0x01d0 ~ 0x01df */
	volatile UINT32 rsv1e0[4];			/* 0x01e0 ~ 0x01ef */
	volatile UINT32 rsv1f0[4];			/* 0x01f0 ~ 0x01ff */
	volatile UINT32 rsv200[64];			/* 0x0200 ~ 0x02ff */
	volatile UINT32 rsv300[44];			/* 0x0300 ~ 0x03af */
	volatile UINT32 disp1ClipV_Start;	/* 0x03b0 ~ 0x03b3 */
	volatile UINT32 disp1ClipV_End;		/* 0x03b4 ~ 0x03b7 */
	volatile UINT32 disp1ClipH_Start;	/* 0x03b8 ~ 0x03bb */
	volatile UINT32 disp1ClipH_End;		/* 0x03bc ~ 0x03bf */
	volatile UINT32 disp1TS_CKV;		/* 0x03c0 ~ 0x03c3 */
	volatile UINT32 disp1TW_CKV;		/* 0x03c4 ~ 0x03c7 */
	volatile UINT32 disp1TS_MISC;		/* 0x03c8 ~ 0x03cb */
	volatile UINT32 disp1TS_POL;		/* 0x03ca ~ 0x03cf */
	volatile UINT32 disp1TS_STV;		/* 0x03d0 ~ 0x03d3 */
	volatile UINT32 disp1TW_STV;		/* 0x03d4 ~ 0x03d7 */
	volatile UINT32 disp1TS_STH;		/* 0x03d8 ~ 0x03db */
	volatile UINT32 disp1TW_STH;		/* 0x03dc ~ 0x03df */
	volatile UINT32 disp1TS_OEV;		/* 0x03e0 ~ 0x03e3 */
	volatile UINT32 disp1TW_OEV;		/* 0x03e4 ~ 0x03e7 */
	volatile UINT32 disp1TS_LD;			/* 0x03e8 ~ 0x03eb */
	volatile UINT32 disp1TW_LD;			/* 0x03ec ~ 0x03ef */
	volatile UINT32 disp1TAB0;			/* 0x03f0 ~ 0x03f3 */
	volatile UINT32 disp1TAB1;			/* 0x03f4 ~ 0x03f7 */
	volatile UINT32 disp1TAB2;			/* 0x03f8 ~ 0x03fb */
	volatile UINT32 disp1TAB3;			/* 0x03fc ~ 0x03ff */			
} disp1Reg_t;

#endif /* _REG_DISP1_H_ */
