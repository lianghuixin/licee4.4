/*
 * drivers/soc/sunxi/pm/resource/mem_tmr.h
 * (C) Copyright 2010-2016
 * Allwinner Technology Co., Ltd. <www.allwinnertech.com>
 * Yanggq <yanggq@allwinnertech.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */

#ifndef __MEM_TMR_H__
#define __MEM_TMR_H__

struct __mem_tmr_reg_t {
	/*  offset:0x00 */
	volatile __u32 IntCtl;
	volatile __u32 IntSta;
	volatile __u32 reserved0[2];
	/*  offset:0x10 */
	volatile __u32 Tmr0Ctl;
	volatile __u32 Tmr0IntVal;
	volatile __u32 Tmr0CntVal;
	volatile __u32 reserved1;
	/*  offset:0x20 */
	volatile __u32 Tmr1Ctl;
	volatile __u32 Tmr1IntVal;
	volatile __u32 Tmr1CntVal;
	volatile __u32 reserved2;
	/*  offset:0x30 */
	volatile __u32 Tmr2Ctl;
	volatile __u32 Tmr2IntVal;
	volatile __u32 Tmr2CntVal;
	volatile __u32 reserved3;
	/*  offset:0x40 */
	volatile __u32 Tmr3Ctl;
	volatile __u32 Tmr3IntVal;
	volatile __u32 reserved4[2];
	/*  offset:0x50 */
	volatile __u32 Tmr4Ctl;
	volatile __u32 Tmr4IntVal;
	volatile __u32 Tmr4CntVal;
	volatile __u32 reserved5;
	/*  offset:0x60 */
	volatile __u32 Tmr5Ctl;
	volatile __u32 Tmr5IntVal;
	volatile __u32 Tmr5CntVal;
	volatile __u32 reserved6[5];

#ifdef CONFIG_ARCH_SUN8IW11P1
	/*  offset:0x80 */
	volatile __u32 AvsCtl;
	volatile __u32 Avs0Cnt;
	volatile __u32 Avs1Cnt;
	volatile __u32 AvsDiv;
	/*  offset:0x90 */
	volatile __u32 WDog1_Ctrl_Reg;
	volatile __u32 WDog1_Mode_Reg;
#else
	/*  offset:0x80: reserved */
	volatile __u32 reserved7[4];
	/*  offset:0x90: reserved */
	volatile __u32 TmrVerion;
	volatile __u32 reserved8[3];
	/*  offset:0xa0 */
	volatile __u32 WDog1_Irq_En;
	volatile __u32 WDog1_Irq_Sta;
	volatile __u32 reserved9[2];
	/*  offset:0xb0 */
	volatile __u32 WDog1_Ctrl_Reg;
	volatile __u32 WDog1_Cfg_Reg;
	volatile __u32 WDog1_Mode_Reg;
	volatile __u32 reserved10;
	/*  offset:0xc0 */
	volatile __u32 AvsCtl;
	volatile __u32 Avs0Cnt;
	volatile __u32 Avs1Cnt;
	volatile __u32 AvsDiv;
#endif
};

/* for super standby; */
__s32 mem_tmr_save(struct __mem_tmr_reg_t *ptmr_state);
__s32 mem_tmr_restore(struct __mem_tmr_reg_t *ptmr_state);
/* for normal standby; */
__s32 mem_tmr_init(void);
void mem_tmr_enable_watchdog(void);
void mem_tmr_disable_watchdog(void);
__s32 mem_tmr_set(__u32 timeout_ms);

#endif /* __MEM_TMR_H__ */
