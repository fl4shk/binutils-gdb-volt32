/* volt32-opc.c -- Definitions for volt32 opcodes.
   Copyright (C) 2022 Free Software Foundation, Inc.
   Written by Andrew Clark (FL4SHK).

   This file is part of the GNU opcodes library.

   This library is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   It is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with this file; see the file COPYING.  If not, write to the
   Free Software Foundation, 51 Franklin Street - Fifth Floor, Boston,
   MA 02110-1301, USA.  */

#include "sysdep.h"
#include "opcode/volt32.h"

#define LMP_ANY {.i=VOLT32_LM_ANY, .d=VOLT32_LM_ANY}
#define LMP_MANI_AUTOD {.i=VOLT32_LM_MAN, .d=VOLT32_LM_AUTO}
#define LMP_MANI_ANYD {.i=VOLT32_LM_MAN, .d=VOLT32_LM_ANY}
#define LMP_ANYI_MAND {.i=VOLT32_LM_ANY, .d=VOLT32_LM_MAN}
#define LMP_BAD {.i=VOLT32_LM_BAD, .d=VOLT32_LM_BAD}
#define LMP_AUTOI_ANYD {.i=VOLT32_LM_AUTO, .d=VOLT32_LM_ANY}
#define LMP_ANYI_AUTOD {.i=VOLT32_LM_ANY, .d=VOLT32_LM_AUTO}
/* -------- */
const volt32_opc_info_t volt32_g0_opc_info[VOLT32_OI_G0_DIM] =
{
  /* -------- */
  {0x0, LMP_ANY, VOLT32_AF_D3, {"add.s", "add.v"}},
  {0x1, LMP_ANY, VOLT32_AF_D3, {"sub.s", "sub.v"}},
  {0x2, LMP_ANY, VOLT32_AF_D3, {"slt.s", "slt.v"}},
  {0x3, LMP_ANY, VOLT32_AF_D3, {"mul.s", "mul.v"}},

  {0x4, LMP_ANY, VOLT32_AF_D3, {"and.s", "and.v"}},
  {0x5, LMP_ANY, VOLT32_AF_D3, {"or.s", "or.v"}},
  {0x6, LMP_ANY, VOLT32_AF_D3, {"xor.s", "xor.v"}},
  {0x7, LMP_ANY, VOLT32_AF_D3, {"shl.s", "shl.v"}},
  /* -------- */
  {0x8, LMP_ANY, VOLT32_AF_D3, {"shr.s", "shr.v"}},
  {0x9, LMP_ANY, VOLT32_AF_D3, {"rol.s", "rol.v"}},
  {0xa, LMP_ANY, VOLT32_AF_D3, {"ror.s", "ror.v"}},
  {0xb, LMP_ANY, VOLT32_AF_DA_DBA_DC, {"add.s", "add.v"}},

  {0xc, LMP_ANY, VOLT32_AF_DA_IBA_DC, {"add.s", "add.v"}},
  {0xd, LMP_ANY, VOLT32_AF_DA_DBA_DC, {"shl.s", "shl.v"}},
  {0xe, LMP_ANY, VOLT32_AF_D4, {"div.s", ""}},
  {0xf, LMP_ANY, VOLT32_AF_D4, {"div.v", ""}},
  /* -------- */
};
const volt32_opc_info_t volt32_g1_opc_info[VOLT32_OI_G1_DIM] =
{
  /* -------- */
  {0x0, LMP_ANY, VOLT32_AF_D2, {"add.r", ""}},
  {0x1, LMP_ANY, VOLT32_AF_D2, {"mul.r", ""}},
  {0x2, LMP_ANY, VOLT32_AF_D2, {"max.r", ""}},
  {0x3, LMP_ANY, VOLT32_AF_D2, {"min.r", ""}},

  {0x4, LMP_ANY, VOLT32_AF_D2, {"and.r", ""}},
  {0x5, LMP_ANY, VOLT32_AF_D2, {"or.r", ""}},
  {0x6, LMP_ANY, VOLT32_AF_D2, {"xor.r", ""}},
  {0x7, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  /* -------- */
};
const volt32_opc_info_t volt32_g2_opc_info[VOLT32_OI_G2_DIM] =
{
  /* -------- */
  {0x0, LMP_ANYI_MAND, VOLT32_AF_D2_SIMM12, {"ldu8i", ""}},
  {0x1, LMP_ANYI_MAND, VOLT32_AF_D2_SIMM12, {"lds8i", ""}},
  {0x2, LMP_ANYI_MAND, VOLT32_AF_D2_SIMM12, {"ldu16i", ""}},
  {0x3, LMP_ANYI_MAND, VOLT32_AF_D2_SIMM12, {"lds16i", ""}},

  {0x4, LMP_ANYI_MAND, VOLT32_AF_D2_SIMM12, {"ldu32i", ""}},
  {0x5, LMP_ANYI_MAND, VOLT32_AF_D2_SIMM12, {"lds32i", ""}},
  {0x6, LMP_ANYI_MAND, VOLT32_AF_D2_SIMM12, {"ldu64i", ""}},
  {0x7, LMP_ANYI_MAND, VOLT32_AF_D2_SIMM12, {"lds64i", ""}},
  /* -------- */
  {0x8, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x9, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xa, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xb, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},

  {0xc, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xd, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xe, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xf, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  /* -------- */
};
const volt32_opc_info_t volt32_g3_opc_info[VOLT32_OI_G3_DIM] =
{
  /* -------- */
  {0x0, LMP_ANYI_MAND, VOLT32_AF_DA_DBA_SIMM12, {"ldu8i", ""}},
  {0x1, LMP_ANYI_MAND, VOLT32_AF_DA_DBA_SIMM12, {"lds8i", ""}},
  {0x2, LMP_ANYI_MAND, VOLT32_AF_DA_DBA_SIMM12, {"ldu16i", ""}},
  {0x3, LMP_ANYI_MAND, VOLT32_AF_DA_DBA_SIMM12, {"lds16i", ""}},

  {0x4, LMP_ANYI_MAND, VOLT32_AF_DA_DBA_SIMM12, {"ldu32i", ""}},
  {0x5, LMP_ANYI_MAND, VOLT32_AF_DA_DBA_SIMM12, {"lds32i", ""}},
  {0x6, LMP_ANYI_MAND, VOLT32_AF_DA_DBA_SIMM12, {"ldu64i", ""}},
  {0x7, LMP_ANYI_MAND, VOLT32_AF_DA_DBA_SIMM12, {"lds64i", ""}},
  /* -------- */
  {0x8, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x9, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xa, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xb, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},

  {0xc, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xd, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xe, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xf, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  /* -------- */
};
const volt32_opc_info_t volt32_g4_opc_info[VOLT32_OI_G4_DIM] =
{
  /* -------- */
  {0x0, LMP_ANYI_MAND, VOLT32_AF_D3, {"ldu8", ""}},
  {0x1, LMP_ANYI_MAND, VOLT32_AF_D3, {"lds8", ""}},
  {0x2, LMP_ANYI_MAND, VOLT32_AF_D3, {"ldu16", ""}},
  {0x3, LMP_ANYI_MAND, VOLT32_AF_D3, {"lds16", ""}},

  {0x4, LMP_ANYI_MAND, VOLT32_AF_D3, {"ldu32", ""}},
  {0x5, LMP_ANYI_MAND, VOLT32_AF_D3, {"lds32", ""}},
  {0x6, LMP_ANYI_MAND, VOLT32_AF_D3, {"ldu64", ""}},
  {0x7, LMP_ANYI_MAND, VOLT32_AF_D3, {"lds64", ""}},
  /* -------- */
  {0x8, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x9, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xa, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xb, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},

  {0xc, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xd, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xe, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xf, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  /* -------- */
};
const volt32_opc_info_t volt32_g5_opc_info[VOLT32_OI_G5_DIM] =
{
  /* -------- */
  {0x0, LMP_ANYI_MAND, VOLT32_AF_D2_SIMM12, {"stu8i", ""}},
  {0x1, LMP_ANYI_MAND, VOLT32_AF_D2_SIMM12, {"sts8i", ""}},
  {0x2, LMP_ANYI_MAND, VOLT32_AF_D2_SIMM12, {"stu16i", ""}},
  {0x3, LMP_ANYI_MAND, VOLT32_AF_D2_SIMM12, {"sts16i", ""}},

  {0x4, LMP_ANYI_MAND, VOLT32_AF_D2_SIMM12, {"stu32i", ""}},
  {0x5, LMP_ANYI_MAND, VOLT32_AF_D2_SIMM12, {"sts32i", ""}},
  {0x6, LMP_ANYI_MAND, VOLT32_AF_D2_SIMM12, {"stu64i", ""}},
  {0x7, LMP_ANYI_MAND, VOLT32_AF_D2_SIMM12, {"sts64i", ""}},
  /* -------- */
  {0x8, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x9, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xa, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xb, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},

  {0xc, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xd, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xe, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xf, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  /* -------- */
};
const volt32_opc_info_t volt32_g6_opc_info[VOLT32_OI_G6_DIM] =
{
  /* -------- */
  {0x0, LMP_ANY, VOLT32_AF_D2, {"dpu8", ""}},
  {0x1, LMP_ANY, VOLT32_AF_D2, {"dps8", ""}},
  {0x2, LMP_ANY, VOLT32_AF_D2, {"dpu16", ""}},
  {0x3, LMP_ANY, VOLT32_AF_D2, {"dps16", ""}},

  {0x4, LMP_ANY, VOLT32_AF_D2, {"dpu32", ""}},
  {0x5, LMP_ANY, VOLT32_AF_D2, {"dps32", ""}},
  {0x6, LMP_ANY, VOLT32_AF_D2, {"dpu64", ""}},
  {0x7, LMP_ANY, VOLT32_AF_D2, {"dps64", ""}},
  /* -------- */
  {0x8, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x9, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xa, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xb, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},

  {0xc, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xd, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xe, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xf, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  /* -------- */
};
const volt32_opc_info_t volt32_g7_opc_info[VOLT32_OI_G7_DIM] =
{
  /* -------- */
  {0x0, LMP_MANI_ANYD, VOLT32_AF_IA_IB_DC_JIMM4, {"fetch", ""}},
  {0x1, LMP_MANI_ANYD, VOLT32_AF_IA_IB_ISIMM11_JIMM4, {"fetchi", ""}},
  /* -------- */
};
const volt32_opc_info_t volt32_g8_opc_info[VOLT32_OI_G8_DIM] =
{
  /* -------- */
  {0x0, LMP_MANI_ANYD, VOLT32_AF_DA_IB_IIMM5_JIMM5, {"sel.s", "sel.v"}},
  {0x1, LMP_MANI_ANYD, VOLT32_AF_DA_IB_IIMM5, {"jz.s", "jz.v"}},
  {0x2, LMP_MANI_ANYD, VOLT32_AF_DA_IB_IIMM5, {"jnz.s", "jnz.v"}},
  {0x3, LMP_ANY, VOLT32_AF_D1, {"reti.s", "reti.v"}},

  {0x4, LMP_ANY, VOLT32_AF_D1, {"retx.s", "retx.v"}},
  {0x5, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x6, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x7, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  /* -------- */
  {0x8, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x9, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xa, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xb, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},

  {0xc, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xd, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xe, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xf, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  /* -------- */
};
const volt32_opc_info_t volt32_g9_opc_info[VOLT32_OI_G9_DIM] =
{
  /* -------- */
  {0x0, LMP_ANYI_MAND, VOLT32_AF_D2_IMM6, {"getaddrs.U", "getaddrs.S"}},
  {0x1, LMP_ANYI_MAND, VOLT32_AF_DA_IB_IMM6, {"getaddrs.U", "getaddrs.S"}},
  {0x2, LMP_ANYI_MAND, VOLT32_AF_D2_IMM6, {"gettypes.U", "gettypes.S"}},
  {0x3, LMP_ANYI_MAND, VOLT32_AF_D3_IMM6, {"ldm.U", "ldm.S"}},

  {0x4, LMP_ANYI_MAND, VOLT32_AF_IA_DB_IMM6, {"fetchm.U", "fetchm.S"}},
  {0x5, LMP_ANYI_MAND, VOLT32_AF_D1_IMM6, {"reload.U", "reload.S"}},
  {0x6, LMP_ANYI_MAND, VOLT32_AF_IA_IMM6, {"reload.U", "reload.S"}},
  {0x7, LMP_ANYI_MAND, VOLT32_AF_D1_IMM6, {"flush.U", "flush.S"}},
  /* -------- */
};
const volt32_opc_info_t volt32_g10_opc_info[VOLT32_OI_G10_DIM] =
{
  /* -------- */
  {0x0, LMP_ANY, VOLT32_AF_DA_INTEN, {"cpy.s", ""}},
  {0x1, LMP_ANY, VOLT32_AF_INTEN_DA, {"cpy.s", ""}},
  {0x2, LMP_ANY, VOLT32_AF_DA_XCT, {"cpy.s", ""}},
  {0x3, LMP_ANY, VOLT32_AF_XCT_DA, {"cpy.s", ""}},

  {0x4, LMP_ANY, VOLT32_AF_DA_SWIARG0, {"cpy.v", ""}},
  {0x5, LMP_ANY, VOLT32_AF_SWIARG0_DA, {"cpy.v", ""}},
  {0x6, LMP_ANY, VOLT32_AF_DA_SWIARG1, {"cpy.v", ""}},
  {0x7, LMP_ANY, VOLT32_AF_SWIARG1_DA, {"cpy.v", ""}},
  /* -------- */
  {0x8, LMP_ANY, VOLT32_AF_DA_SWIARG2, {"cpy.v", ""}},
  {0x9, LMP_ANY, VOLT32_AF_SWIARG2_DA, {"cpy.v", ""}},
  {0xa, LMP_ANY, VOLT32_AF_DA_SWIARG3, {"cpy.v", ""}},
  {0xb, LMP_ANY, VOLT32_AF_SWIARG3_DA, {"cpy.v", ""}},

  {0xc, LMP_ANY, VOLT32_AF_D4, {"swi", ""}},
  {0xd, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xe, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xf, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  /* -------- */
};
const volt32_opc_info_t volt32_g11_opc_info[VOLT32_OI_G11_DIM] =
{
  /* -------- */
  {0x0, LMP_ANY, VOLT32_AF_D3, {"inu8.s", "inu8.v"}},
  {0x1, LMP_ANY, VOLT32_AF_D3, {"ins8.s", "ins8.v"}},
  {0x2, LMP_ANY, VOLT32_AF_D3, {"inu16.s", "inu16.v"}},
  {0x3, LMP_ANY, VOLT32_AF_D3, {"ins16.s", "ins16.v"}},

  {0x4, LMP_ANY, VOLT32_AF_D3, {"inu32.s", "inu32.v"}},
  {0x5, LMP_ANY, VOLT32_AF_D3, {"ins32.s", "ins32.v"}},
  {0x6, LMP_ANY, VOLT32_AF_D3, {"inu64.s", "inu64.v"}},
  {0x7, LMP_ANY, VOLT32_AF_D3, {"ins64.s", "ins64.v"}},
  /* -------- */
  {0x8, LMP_ANY, VOLT32_AF_BAD, {"bad", ""}},
  {0x9, LMP_ANY, VOLT32_AF_BAD, {"bad", ""}},
  {0xa, LMP_ANY, VOLT32_AF_BAD, {"bad", ""}},
  {0xb, LMP_ANY, VOLT32_AF_BAD, {"bad", ""}},

  {0xc, LMP_ANY, VOLT32_AF_BAD, {"bad", ""}},
  {0xd, LMP_ANY, VOLT32_AF_BAD, {"bad", ""}},
  {0xe, LMP_ANY, VOLT32_AF_BAD, {"bad", ""}},
  {0xf, LMP_ANY, VOLT32_AF_BAD, {"bad", ""}},
  /* -------- */
  {0x10, LMP_ANY, VOLT32_AF_D3, {"outu8.s", "outu8.v"}},
  {0x11, LMP_ANY, VOLT32_AF_D3, {"outs8.s", "outs8.v"}},
  {0x12, LMP_ANY, VOLT32_AF_D3, {"outu16.s", "outu16.v"}},
  {0x13, LMP_ANY, VOLT32_AF_D3, {"outs16.s", "outs16.v"}},

  {0x14, LMP_ANY, VOLT32_AF_D3, {"outu32.s", "outu32.v"}},
  {0x15, LMP_ANY, VOLT32_AF_D3, {"outs32.s", "outs32.v"}},
  {0x16, LMP_ANY, VOLT32_AF_D3, {"outu64.s", "outu64.v"}},
  {0x17, LMP_ANY, VOLT32_AF_D3, {"outs64.s", "outs64.v"}},
  /* -------- */
  {0x18, LMP_ANY, VOLT32_AF_BAD, {"bad", ""}},
  {0x19, LMP_ANY, VOLT32_AF_BAD, {"bad", ""}},
  {0x1a, LMP_ANY, VOLT32_AF_BAD, {"bad", ""}},
  {0x1b, LMP_ANY, VOLT32_AF_BAD, {"bad", ""}},

  {0x1c, LMP_ANY, VOLT32_AF_BAD, {"bad", ""}},
  {0x1d, LMP_ANY, VOLT32_AF_BAD, {"bad", ""}},
  {0x1e, LMP_ANY, VOLT32_AF_BAD, {"bad", ""}},
  {0x1f, LMP_ANY, VOLT32_AF_BAD, {"bad", ""}},
  /* -------- */
};
const volt32_opc_info_t volt32_g12_opc_info[VOLT32_OI_G12_DIM] =
{
  /* -------- */
  {0x0, LMP_ANY, VOLT32_AF_D1_SIMM21, {"cpyi.s", ""}},
  {0x1, LMP_ANY, VOLT32_AF_D1_IPCA_SIMM21, {"addi.s", ""}},
  /* -------- */
};
/* -------- */
const volt32_opc_info_t volt32_ps_opc_info[VOLT32_OI_PS_DIM] =
{
  /* -------- */
  {0x0, LMP_AUTOI_ANYD, VOLT32_OIAFPS_D2_SIMM11, {"jdz.s", "jdz.v"}},
  {0x1, LMP_AUTOI_ANYD, VOLT32_OIAFPS_D2_SIMM11, {"jdnz.s", "jdnz.v"}},
  {0x2, LMP_AUTOI_ANYD, VOLT32_OIAFPS_BRANCH_SIMM21, {"bz.s", "bz.v"}},
  {0x3, LMP_AUTOI_ANYD, VOLT32_OIAFPS_BRANCH_SIMM21, {"bnz.s", "bnz.v"}},

  {0x4, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x5, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x6, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x7, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  /* -------- */
  {0x8, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x9, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xa, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xb, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},

  {0xc, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xd, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xe, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0xf, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  /* -------- */
  {0x10, LMP_ANYI_AUTOD, VOLT32_AF_D2_SIMM12, {"ldu8i.s", "ldu8i.v"}},
  {0x11, LMP_ANYI_AUTOD, VOLT32_AF_D2_SIMM12, {"lds8i.s", "lds8i.v"}},
  {0x12, LMP_ANYI_AUTOD, VOLT32_AF_D2_SIMM12, {"ldu16i.s", "ldu16i.v"}},
  {0x13, LMP_ANYI_AUTOD, VOLT32_AF_D2_SIMM12, {"lds16i.s", "lds16i.v"}},

  {0x14, LMP_ANYI_AUTOD, VOLT32_AF_D2_SIMM12, {"ldu32i.s", "ldu32i.v"}},
  {0x15, LMP_ANYI_AUTOD, VOLT32_AF_D2_SIMM12, {"lds32i.s", "lds32i.v"}},
  {0x16, LMP_ANYI_AUTOD, VOLT32_AF_D2_SIMM12, {"ldu64i.s", "ldu64i.v"}},
  {0x17, LMP_ANYI_AUTOD, VOLT32_AF_D2_SIMM12, {"lds64i.s", "lds64i.v"}},
  /* -------- */
  /* Reserved for future load type tags */
  {0x18, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x19, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x1a, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x1b, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},

  {0x1c, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x1d, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x1e, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x1f, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  /* -------- */
  {0x20, LMP_ANYI_AUTOD, VOLT32_AF_D3, {"ldu8.s", "ldu8.v"}},
  {0x21, LMP_ANYI_AUTOD, VOLT32_AF_D3, {"lds8.s", "lds8.v"}},
  {0x22, LMP_ANYI_AUTOD, VOLT32_AF_D3, {"ldu16.s", "ldu16.v"}},
  {0x23, LMP_ANYI_AUTOD, VOLT32_AF_D3, {"lds16.s", "lds16.v"}},

  {0x24, LMP_ANYI_AUTOD, VOLT32_AF_D3, {"ldu32.s", "ldu32.v"}},
  {0x25, LMP_ANYI_AUTOD, VOLT32_AF_D3, {"lds32.s", "lds32.v"}},
  {0x26, LMP_ANYI_AUTOD, VOLT32_AF_D3, {"ldu64.s", "ldu64.v"}},
  {0x27, LMP_ANYI_AUTOD, VOLT32_AF_D3, {"lds64.s", "lds64.v"}},
  /* -------- */
  /* Reserved for future load type tags */
  {0x28, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x29, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x2a, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x2b, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},

  {0x2c, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x2d, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x2e, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x2f, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  /* -------- */
  {0x30, LMP_ANYI_AUTOD, VOLT32_AF_D2_SIMM12, {"stu8i.s", "stu8i.v"}},
  {0x31, LMP_ANYI_AUTOD, VOLT32_AF_D2_SIMM12, {"sts8i.s", "sts8i.v"}},
  {0x32, LMP_ANYI_AUTOD, VOLT32_AF_D2_SIMM12, {"stu16i.s", "stu16i.v"}},
  {0x33, LMP_ANYI_AUTOD, VOLT32_AF_D2_SIMM12, {"sts16i.s", "sts16i.v"}},

  {0x34, LMP_ANYI_AUTOD, VOLT32_AF_D2_SIMM12, {"stu32i.s", "stu32i.v"}},
  {0x35, LMP_ANYI_AUTOD, VOLT32_AF_D2_SIMM12, {"sts32i.s", "sts32i.v"}},
  {0x36, LMP_ANYI_AUTOD, VOLT32_AF_D2_SIMM12, {"stu64i.s", "stu64i.v"}},
  {0x37, LMP_ANYI_AUTOD, VOLT32_AF_D2_SIMM12, {"sts64i.s", "sts64i.v"}},
  /* -------- */
  /* Reserved for future store type tags */
  {0x38, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x39, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x3a, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x3b, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},

  {0x3c, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x3d, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x3e, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x3f, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  /* -------- */
  {0x40, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x41, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x42, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x43, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},

  {0x44, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x45, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x46, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x47, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  /* -------- */
  {0x48, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x49, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x4a, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x4b, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},

  {0x4c, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x4d, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x4e, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  {0x4f, LMP_BAD, VOLT32_AF_BAD, {"bad", ""}},
  /* -------- */
};
/* -------- */
const volt32_opc_info_t **volt32_raw_opc_info_arr[VOLT32_NUM_OI_GRPS] =
{
  /* -------- */
  (const volt32_opc_info_t **)&volt32_g0_opc_info,
  (const volt32_opc_info_t **)&volt32_g1_opc_info,
  (const volt32_opc_info_t **)&volt32_g2_opc_info,
  (const volt32_opc_info_t **)&volt32_g3_opc_info,
  (const volt32_opc_info_t **)&volt32_g4_opc_info,
  (const volt32_opc_info_t **)&volt32_g5_opc_info,
  (const volt32_opc_info_t **)&volt32_g6_opc_info,
  (const volt32_opc_info_t **)&volt32_g7_opc_info,
  (const volt32_opc_info_t **)&volt32_g8_opc_info,
  (const volt32_opc_info_t **)&volt32_g9_opc_info,
  (const volt32_opc_info_t **)&volt32_g10_opc_info,
  (const volt32_opc_info_t **)&volt32_g11_opc_info,
  (const volt32_opc_info_t **)&volt32_g12_opc_info,
  /* -------- */
};
/* -------- */
