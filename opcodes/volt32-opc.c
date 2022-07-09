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
  {0x0, LMP_ANY, VOLT32_AF_D2_SIMM12, {"stu8i", ""}},
  {0x1, LMP_ANY, VOLT32_AF_D2_SIMM12, {"sts8i", ""}},
  {0x2, LMP_ANY, VOLT32_AF_D2_SIMM12, {"stu16i", ""}},
  {0x3, LMP_ANY, VOLT32_AF_D2_SIMM12, {"sts16i", ""}},

  {0x4, LMP_ANY, VOLT32_AF_D2_SIMM12, {"stu32i", ""}},
  {0x5, LMP_ANY, VOLT32_AF_D2_SIMM12, {"sts32i", ""}},
  {0x6, LMP_ANY, VOLT32_AF_D2_SIMM12, {"stu64i", ""}},
  {0x7, LMP_ANY, VOLT32_AF_D2_SIMM12, {"sts64i", ""}},
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
  {0x0, LMP_ANY, VOLT32_AF_DA_INTEN, "cpy.s", VOLT32_NULL_PAIR},
  {0x1, LMP_ANY, VOLT32_AF_INTEN_DA, "cpy.s", VOLT32_NULL_PAIR},
  {0x2, LMP_ANY, VOLT32_AF_DA_XCT, "cpy.s", VOLT32_NULL_PAIR},
  {0x3, LMP_ANY, VOLT32_AF_XCT_DA, "cpy.s", VOLT32_NULL_PAIR},

  {0x4, LMP_ANY, VOLT32_AF_DA_SWIARG0, "cpy.v", VOLT32_NULL_PAIR},
  {0x5, LMP_ANY, VOLT32_AF_SWIARG0_DA, "cpy.v", VOLT32_NULL_PAIR},
  {0x6, LMP_ANY, VOLT32_AF_DA_SWIARG1, "cpy.v", VOLT32_NULL_PAIR},
  {0x7, LMP_ANY, VOLT32_AF_SWIARG1_DA, "cpy.v", VOLT32_NULL_PAIR},
  /* -------- */
  {0x8, LMP_ANY, VOLT32_AF_DA_SWIARG2, "cpy.v", VOLT32_NULL_PAIR},
  {0x9, LMP_ANY, VOLT32_AF_SWIARG2_DA, "cpy.v", VOLT32_NULL_PAIR},
  {0xa, LMP_ANY, VOLT32_AF_DA_SWIARG3, "cpy.v", VOLT32_NULL_PAIR},
  {0xb, LMP_ANY, VOLT32_AF_SWIARG3_DA, "cpy.v", VOLT32_NULL_PAIR},

  {0xc, LMP_ANY, VOLT32_AF_D4, "swi", VOLT32_NULL_PAIR},
  {0xd, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0xe, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0xf, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  /* -------- */
};
const volt32_opc_info_t volt32_g11_opc_info[VOLT32_OI_G11_DIM] =
{
  /* -------- */
  {0x0, LMP_ANY, VOLT32_AF_D3, "inu8", {'s', 'v'}},
  {0x1, LMP_ANY, VOLT32_AF_D3, "ins8", {'s', 'v'}},
  {0x2, LMP_ANY, VOLT32_AF_D3, "inu16", {'s', 'v'}},
  {0x3, LMP_ANY, VOLT32_AF_D3, "ins16", {'s', 'v'}},

  {0x4, LMP_ANY, VOLT32_AF_D3, "inu32", {'s', 'v'}},
  {0x5, LMP_ANY, VOLT32_AF_D3, "ins32", {'s', 'v'}},
  {0x6, LMP_ANY, VOLT32_AF_D3, "inu64", {'s', 'v'}},
  {0x7, LMP_ANY, VOLT32_AF_D3, "ins64", {'s', 'v'}},
  /* -------- */
  {0x8, LMP_ANY, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0x9, LMP_ANY, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0xa, LMP_ANY, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0xb, LMP_ANY, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},

  {0xc, LMP_ANY, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0xd, LMP_ANY, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0xe, LMP_ANY, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0xf, LMP_ANY, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  /* -------- */
  {0x10, LMP_ANY, VOLT32_AF_D3, "outu8", {'s', 'v'}},
  {0x11, LMP_ANY, VOLT32_AF_D3, "outs8", {'s', 'v'}},
  {0x12, LMP_ANY, VOLT32_AF_D3, "outu16", {'s', 'v'}},
  {0x13, LMP_ANY, VOLT32_AF_D3, "outs16", {'s', 'v'}},

  {0x14, LMP_ANY, VOLT32_AF_D3, "outu32", {'s', 'v'}},
  {0x15, LMP_ANY, VOLT32_AF_D3, "outs32", {'s', 'v'}},
  {0x16, LMP_ANY, VOLT32_AF_D3, "outu64", {'s', 'v'}},
  {0x17, LMP_ANY, VOLT32_AF_D3, "outs64", {'s', 'v'}},
  /* -------- */
  {0x18, LMP_ANY, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0x19, LMP_ANY, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0x1a, LMP_ANY, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0x1b, LMP_ANY, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},

  {0x1c, LMP_ANY, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0x1d, LMP_ANY, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0x1e, LMP_ANY, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0x1f, LMP_ANY, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  /* -------- */
};
const volt32_opc_info_t volt32_g12_opc_info[VOLT32_OI_G12_DIM] =
{
  /* -------- */
  {0x0, LMP_ANY, VOLT32_AF_D1_SIMM21, "cpyi.s", VOLT32_NULL_PAIR},
  {0x1, LMP_ANY, VOLT32_AF_D1_IPCA_SIMM21, "addi.s", VOLT32_NULL_PAIR},
  /* -------- */
};
/* -------- */
const volt32_opc_info_t volt32_ps_opc_info[VOLT32_OI_PS_DIM] =
{
  /* -------- */
  {0x0, LMP_AUTOI_ANYD, VOLT32_OIAFPS_JUMP, "jdz", {'s', 'v'}},
  {0x1, LMP_AUTOI_ANYD, VOLT32_OIAFPS_JUMP, "jdnz", {'s', 'v'}},
  {0x2, LMP_AUTOI_ANYD, VOLT32_OIAFPS_BRANCH, "bz", {'s', 'v'}},
  {0x3, LMP_AUTOI_ANYD, VOLT32_OIAFPS_BRANCH, "bnz", {'s', 'v'}},

  {0x4, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0x5, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0x6, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0x7, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  /* -------- */
  {0x8, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0x9, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0xa, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0xb, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},

  {0xc, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0xd, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0xe, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0xf, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  /* -------- */
  {0x10, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0x11, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0x12, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0x13, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},

  {0x14, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0x15, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0x16, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0x17, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  /* -------- */
  {0x18, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0x19, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0x1a, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0x1b, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},

  {0x1c, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0x1d, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0x1e, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  {0x1f, LMP_BAD, VOLT32_AF_BAD, "bad", VOLT32_NULL_PAIR},
  /* -------- */
};
/* -------- */
const volt32_opc_info_t *volt32_raw_opc_info_arr[VOLT32_NUM_OI_GRPS] =
{
  /* -------- */
  &volt32_g0_opc_info,
  &volt32_g1_opc_info,
  &volt32_g2_opc_info,
  &volt32_g3_opc_info,
  &volt32_g4_opc_info,
  &volt32_g5_opc_info,
  &volt32_g6_opc_info,
  &volt32_g7_opc_info,
  &volt32_g8_opc_info,
  &volt32_g9_opc_info,
  &volt32_g10_opc_info,
  &volt32_g11_opc_info,
  &volt32_g12_opc_info,
  /* -------- */
};
/* -------- */
