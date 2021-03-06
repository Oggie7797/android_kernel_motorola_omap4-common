 /*
  * OMAP4XXX L3 Interconnect  error handling driver header
  *
  * Copyright (C) 2011 Texas Corporation
  *	Santosh Shilimkar <santosh.shilimkar@ti.com>
  *	sricharan <r.sricharan@ti.com>
  *
  * This program is free software; you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation; either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program; if not, write to the Free Software
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
  * USA
  */
#ifndef __ARCH_ARM_MACH_OMAP2_L3_INTERCONNECT_3XXX_H
#define __ARCH_ARM_MACH_OMAP2_L3_INTERCONNECT_3XXX_H

/*
 * L3 register offsets
 */
#define L3_MODULES			3
#define CLEAR_STDERR_LOG		(1 << 31)
#define CUSTOM_ERROR			0x2
#define STANDARD_ERROR			0x0
#define INBAND_ERROR			0x0
#define EMIF_KERRLOG_OFFSET		0x10
#define L3_SLAVE_ADDRESS_OFFSET		0x14
#define LOGICAL_ADDR_ERRORLOG		0x4
#define L3_APPLICATION_ERROR		0x0
#define L3_DEBUG_ERROR			0x1

#define L3_COREREG			0x00
#define L3_VERSIONREG			0x04
#define L3_MAINCTLREG			0x08
#define L3_NTTPADDR_0			0x10
#define L3_SVRTSTDLVL			0x40
#define L3_SVRTCUSTOMLVL		0x44
#define L3_MAIN				0x48
#define L3_HDR				0x4C
#define L3_MSTADDR			0x50
#define L3_SLVADDR			0x54
#define L3_INFO				0x58
#define L3_SLVOFSLSB			0x5C
#define L3_SLVOFSMSB			0x60
#define L3_CUSTOMINFO_INFO		0x64
#define L3_CUSTOMINFO_MSTADDR		0x68
#define L3_CUSTOMINFO_OPCODE		0x6C
#define L3_ADDRSPACESIZELOG		0x80

u32 l3_flagmux[L3_MODULES] = {
	0x50C,
	0x100C,
	0X020C
};

/*
 * L3 Target standard Error register offsets
 */
u32 l3_targ_stderrlog_main_clk1[] = {
	0x148, /* DMM1 */
	0x248, /* DMM2 */
	0x348, /* ABE */
	0x448, /* L4CFG */
	0x648  /* CLK2 PWR DISC */
};

u32 l3_targ_stderrlog_main_clk2[] = {
	0x548,		/* CORTEX M3 */
	0x348,		/* DSS */
	0x148,		/* GPMC */
	0x448,		/* ISS */
	0x748,		/* IVAHD */
	0xD48,		/* missing in TRM  corresponds to AES1*/
	0x948,		/* L4 PER0*/
	0x248,		/* OCMRAM */
	0x148,		/* missing in TRM corresponds to GPMC sERROR*/
	0x648,		/* SGX */
	0x848,		/* SL2 */
	0x1648,		/* C2C */
	0x1148,		/* missing in TRM corresponds PWR DISC CLK1*/
	0xF48,		/* missing in TRM corrsponds to SHA1*/
	0xE48,		/* missing in TRM corresponds to AES2*/
	0xC48,		/* L4 PER3 */
	0xA48,		/* L4 PER1*/
	0xB48		/* L4 PER2*/
};

u32 l3_targ_stderrlog_main_clk3[] = {
	0x0148	/* EMUSS */
};

struct l3_masters_data {
	u32 id;
	char name[15];
};

struct l3_masters_data l3_masters[] = {
	 { 0x0 , "MPU"},
	 { 0x10, "CS_ADP"},
	 { 0x14, "Unknown"},
	 { 0x20, "DSP"},
	 { 0x30, "IVAHD"},
	 { 0x40, "ISS"},
	 { 0x44, "DucatiM3"},
	 { 0x48, "FaceDetect"},
	 { 0x50, "SDMA_Rd"},
	 { 0x54, "SDMA_Wr"},
	 { 0x58, "Unknown"},
	 { 0x5C, "Unknown"},
	 { 0x60, "SGX"},
	 { 0x70, "DSS"},
	 { 0x80, "C2C"},
	 { 0x88, "Unknown"},
	 { 0x8C, "Unknown"},
	 { 0x90, "HSI"},
	 { 0xA0, "MMC1"},
	 { 0xA4, "MMC2"},
};

char *l3_targ_stderrlog_main_name[L3_MODULES][18] = {
	{
	"DMM1",
	"DMM2",
	"ABE",
	"L4CFG",
	"CLK2 PWR DISC",
	},
	{
	"CORTEX M3" ,
	"DSS ",
	"GPMC ",
	"ISS ",
	"IVAHD ",
	"AES1",
	"L4 PER0",
	"OCMRAM ",
	"GPMC sERROR",
	"SGX ",
	"SL2 ",
	"C2C ",
	"PWR DISC CLK1",
	"SHA1",
	"AES2",
	"L4 PER3",
	"L4 PER1",
	"L4 PER2",
	},
	{
	"EMUSS",
	},
};

u32 targ_reg_offset[L3_MODULES][18] = {
	{
	0x100,
	0x200,
	0x300,
	0x400,
	0x0,
	},
	{
	0x500,
	0x300,
	0x100,
	0x400,
	0x700,
	0x000,
	0x000,
	0x000,
	0x000,
	0x600,
	0x800,
	0x000,
	0x000,
	0x000,
	0x000,
	0x100,
	0xA00,
	0xB00,
	},
	{
	0x000000
	},
};

u32 *l3_targ[L3_MODULES] = {
	l3_targ_stderrlog_main_clk1,
	l3_targ_stderrlog_main_clk2,
	l3_targ_stderrlog_main_clk3,
};

struct omap4_l3 {
	struct device	*dev;
	struct clk	*ick;

	/* memory base */
	void __iomem *l3_base[4];

	int		debug_irq;
	int		app_irq;
};

#endif
