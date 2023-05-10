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

static const volt32_oi_sub_elem_t
  VOLT32_OI_SE_BLANK = {VOLT32_AF_BAD, ""},
  VOLT32_OI_SE_BAD = {VOLT32_AF_BAD, "bad"};

#define VOLT32_LMP_ANY {.i=VOLT32_LM_ANY, .d=VOLT32_LM_ANY}
#define VOLT32_LMP_MANI_AUTOD {.i=VOLT32_LM_MAN, .d=VOLT32_LM_AUTO}
#define VOLT32_LMP_MANI_ANYD {.i=VOLT32_LM_MAN, .d=VOLT32_LM_ANY}
#define VOLT32_LMP_ANYI_MAND {.i=VOLT32_LM_ANY, .d=VOLT32_LM_MAN}
#define VOLT32_LMP_BAD {.i=VOLT32_LM_BAD, .d=VOLT32_LM_BAD}
#define VOLT32_LMP_AUTOI_ANYD {.i=VOLT32_LM_AUTO, .d=VOLT32_LM_ANY}
#define VOLT32_LMP_ANYI_AUTOD {.i=VOLT32_LM_ANY, .d=VOLT32_LM_AUTO}
/* -------- */
const volt32_opc_info_t volt32_g0_opc_info[VOLT32_OI_G0_DIM] =
{
  /* -------- */
  {0x0, VOLT32_LMP_ANY, {{VOLT32_AF_D3, "add.s"}, {VOLT32_AF_D3, "add.v"}}},
  {0x1, VOLT32_LMP_ANY, {{VOLT32_AF_D3, "sub.s"}, {VOLT32_AF_D3, "sub.v"}}},
  {0x2, VOLT32_LMP_ANY, {{VOLT32_AF_D3, "slt.s"}, {VOLT32_AF_D3, "slt.v"}}},
  {0x3, VOLT32_LMP_ANY, {{VOLT32_AF_D3, "mul.s"}, {VOLT32_AF_D3, "mul.v"}}},

  {0x4, VOLT32_LMP_ANY, {{VOLT32_AF_D3, "and.s"}, {VOLT32_AF_D3, "and.v"}}},
  {0x5, VOLT32_LMP_ANY, {{VOLT32_AF_D3, "or.s"}, {VOLT32_AF_D3, "or.v"}}},
  {0x6, VOLT32_LMP_ANY, {{VOLT32_AF_D3, "xor.s"}, {VOLT32_AF_D3, "xor.v"}}},
  {0x7, VOLT32_LMP_ANY, {{VOLT32_AF_D3, "shl.s"}, {VOLT32_AF_D3, "shl.v"}}},
  /* -------- */
  {0x8, VOLT32_LMP_ANY, {{VOLT32_AF_D3, "shr.s"}, {VOLT32_AF_D3, "shr.v"}}},
  {0x9, VOLT32_LMP_ANY, {{VOLT32_AF_D3, "rol.s"}, {VOLT32_AF_D3, "rol.v"}}},
  {0xa, VOLT32_LMP_ANY, {{VOLT32_AF_D3, "ror.s"}, {VOLT32_AF_D3, "ror.v"}}},
  {0xb, VOLT32_LMP_ANY, {{VOLT32_AF_DA_DBA_DC, "add.s"}, {VOLT32_AF_DA_DBA_DC, "add.v"}}},

  {0xc, VOLT32_LMP_ANY, {{VOLT32_AF_DA_IBA_DC, "add.s"}, {VOLT32_AF_DA_IBA_DC, "add.v"}}},
  {0xd, VOLT32_LMP_ANY, {{VOLT32_AF_DA_DBA_DC, "shl.s"}, {VOLT32_AF_DA_DBA_DC, "shl.v"}}},
  {0xe, VOLT32_LMP_ANY, {{VOLT32_AF_D4, "div.s"}, VOLT32_OI_SE_BLANK}},
  {0xf, VOLT32_LMP_ANY, {{VOLT32_AF_D4, "div.v"}, VOLT32_OI_SE_BLANK}},
  /* -------- */
};
const volt32_opc_info_t volt32_g1_opc_info[VOLT32_OI_G1_DIM] =
{
  /* -------- */
  {0x0, VOLT32_LMP_ANY, {{VOLT32_AF_D2, "add.r"}, VOLT32_OI_SE_BLANK}},
  {0x1, VOLT32_LMP_ANY, {{VOLT32_AF_D2, "mul.r"}, VOLT32_OI_SE_BLANK}},
  {0x2, VOLT32_LMP_ANY, {{VOLT32_AF_D2, "max.r"}, VOLT32_OI_SE_BLANK}},
  {0x3, VOLT32_LMP_ANY, {{VOLT32_AF_D2, "min.r"}, VOLT32_OI_SE_BLANK}},

  {0x4, VOLT32_LMP_ANY, {{VOLT32_AF_D2, "and.r"}, VOLT32_OI_SE_BLANK}},
  {0x5, VOLT32_LMP_ANY, {{VOLT32_AF_D2, "or.r"}, VOLT32_OI_SE_BLANK}},
  {0x6, VOLT32_LMP_ANY, {{VOLT32_AF_D2, "xor.r"}, VOLT32_OI_SE_BLANK}},
  {0x7, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  /* -------- */
};
const volt32_opc_info_t volt32_g2_opc_info[VOLT32_OI_G2_DIM] =
{
  /* -------- */
  {0x0, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_D2_SIMM12, "ldu8i"}, VOLT32_OI_SE_BLANK}},
  {0x1, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_D2_SIMM12, "lds8i"}, VOLT32_OI_SE_BLANK}},
  {0x2, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_D2_SIMM12, "ldu16i"}, VOLT32_OI_SE_BLANK}},
  {0x3, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_D2_SIMM12, "lds16i"}, VOLT32_OI_SE_BLANK}},

  {0x4, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_D2_SIMM12, "ldu32i"}, VOLT32_OI_SE_BLANK}},
  {0x5, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_D2_SIMM12, "lds32i"}, VOLT32_OI_SE_BLANK}},
  {0x6, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_D2_SIMM12, "ldu64i"}, VOLT32_OI_SE_BLANK}},
  {0x7, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_D2_SIMM12, "lds64i"}, VOLT32_OI_SE_BLANK}},
  /* -------- */
  {0x8, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x9, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xa, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xb, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},

  {0xc, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xd, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xe, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xf, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  /* -------- */
};

const volt32_opc_info_t volt32_g3_opc_info[VOLT32_OI_G3_DIM] =
{
  /* -------- */
  {0x0, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_DA_DBA_SIMM12, "ldu8i"}, VOLT32_OI_SE_BLANK}},
  {0x1, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_DA_DBA_SIMM12, "lds8i"}, VOLT32_OI_SE_BLANK}},
  {0x2, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_DA_DBA_SIMM12, "ldu16i"}, VOLT32_OI_SE_BLANK}},
  {0x3, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_DA_DBA_SIMM12, "lds16i"}, VOLT32_OI_SE_BLANK}},

  {0x4, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_DA_DBA_SIMM12, "ldu32i"}, VOLT32_OI_SE_BLANK}},
  {0x5, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_DA_DBA_SIMM12, "lds32i"}, VOLT32_OI_SE_BLANK}},
  {0x6, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_DA_DBA_SIMM12, "ldu64i"}, VOLT32_OI_SE_BLANK}},
  {0x7, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_DA_DBA_SIMM12, "lds64i"}, VOLT32_OI_SE_BLANK}},
  /* -------- */
  {0x8, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x9, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xa, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xb, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},

  {0xc, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xd, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xe, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xf, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  /* -------- */
};
const volt32_opc_info_t volt32_g4_opc_info[VOLT32_OI_G4_DIM] =
{
  /* -------- */
  {0x0, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_D3, "ldu8"}, VOLT32_OI_SE_BLANK}},
  {0x1, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_D3, "lds8"}, VOLT32_OI_SE_BLANK}},
  {0x2, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_D3, "ldu16"}, VOLT32_OI_SE_BLANK}},
  {0x3, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_D3, "lds16"}, VOLT32_OI_SE_BLANK}},

  {0x4, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_D3, "ldu32"}, VOLT32_OI_SE_BLANK}},
  {0x5, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_D3, "lds32"}, VOLT32_OI_SE_BLANK}},
  {0x6, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_D3, "ldu64"}, VOLT32_OI_SE_BLANK}},
  {0x7, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_D3, "lds64"}, VOLT32_OI_SE_BLANK}},
  /* -------- */
  {0x8, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x9, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xa, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xb, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},

  {0xc, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xd, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xe, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xf, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  /* -------- */
};
const volt32_opc_info_t volt32_g5_opc_info[VOLT32_OI_G5_DIM] =
{
  /* -------- */
  {0x0, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_D2_SIMM12, "stu8i"}, VOLT32_OI_SE_BLANK}},
  {0x1, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_D2_SIMM12, "sts8i"}, VOLT32_OI_SE_BLANK}},
  {0x2, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_D2_SIMM12, "stu16i"}, VOLT32_OI_SE_BLANK}},
  {0x3, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_D2_SIMM12, "sts16i"}, VOLT32_OI_SE_BLANK}},

  {0x4, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_D2_SIMM12, "stu32i"}, VOLT32_OI_SE_BLANK}},
  {0x5, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_D2_SIMM12, "sts32i"}, VOLT32_OI_SE_BLANK}},
  {0x6, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_D2_SIMM12, "stu64i"}, VOLT32_OI_SE_BLANK}},
  {0x7, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_D2_SIMM12, "sts64i"}, VOLT32_OI_SE_BLANK}},
  /* -------- */
  {0x8, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x9, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xa, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xb, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},

  {0xc, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xd, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xe, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xf, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  /* -------- */
};
const volt32_opc_info_t volt32_g6_opc_info[VOLT32_OI_G6_DIM] =
{
  /* -------- */
  {0x0, VOLT32_LMP_ANY, {{VOLT32_AF_D2, "dpu8"}, VOLT32_OI_SE_BLANK}},
  {0x1, VOLT32_LMP_ANY, {{VOLT32_AF_D2, "dps8"}, VOLT32_OI_SE_BLANK}},
  {0x2, VOLT32_LMP_ANY, {{VOLT32_AF_D2, "dpu16"}, VOLT32_OI_SE_BLANK}},
  {0x3, VOLT32_LMP_ANY, {{VOLT32_AF_D2, "dps16"}, VOLT32_OI_SE_BLANK}},

  {0x4, VOLT32_LMP_ANY, {{VOLT32_AF_D2, "dpu32"}, VOLT32_OI_SE_BLANK}},
  {0x5, VOLT32_LMP_ANY, {{VOLT32_AF_D2, "dps32"}, VOLT32_OI_SE_BLANK}},
  {0x6, VOLT32_LMP_ANY, {{VOLT32_AF_D2, "dpu64"}, VOLT32_OI_SE_BLANK}},
  {0x7, VOLT32_LMP_ANY, {{VOLT32_AF_D2, "dps64"}, VOLT32_OI_SE_BLANK}},
  /* -------- */
  {0x8, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x9, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xa, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xb, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},

  {0xc, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xd, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xe, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xf, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  /* -------- */
};
const volt32_opc_info_t volt32_g7_opc_info[VOLT32_OI_G7_DIM] =
{
  /* -------- */
  {0x0, VOLT32_LMP_MANI_ANYD, {{VOLT32_AF_IA_IB_DC_JIMM4, "fetch"}, VOLT32_OI_SE_BLANK}},
  {0x1, VOLT32_LMP_MANI_ANYD, {{VOLT32_AF_IA_IB_ISIMM11_JIMM4, "fetchi"}, VOLT32_OI_SE_BLANK}},
  /* -------- */
};
const volt32_opc_info_t volt32_g8_opc_info[VOLT32_OI_G8_DIM] =
{
  /* -------- */
  {0x0, VOLT32_LMP_MANI_ANYD, 
    {{VOLT32_AF_DA_IB_IIMM5_JIMM5, "sel.s"}, {VOLT32_AF_DA_IB_IIMM5_JIMM5, "sel.v"}}},
  {0x1, VOLT32_LMP_MANI_ANYD, {{VOLT32_AF_DA_IB_IIMM5, "jz.s"}, {VOLT32_AF_DA_IB_IIMM5, "jz.v"}}},
  {0x2, VOLT32_LMP_MANI_ANYD, {{VOLT32_AF_DA_IB_IIMM5, "jnz.s"}, {VOLT32_AF_DA_IB_IIMM5, "jnz.v"}}},
  {0x3, VOLT32_LMP_ANY, {{VOLT32_AF_D1, "reti.s"}, {VOLT32_AF_D1, "reti.v"}}},

  {0x4, VOLT32_LMP_ANY, {{VOLT32_AF_D1, "retx.s"}, {VOLT32_AF_D1, "retx.v"}}},
  {0x5, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x6, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x7, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  /* -------- */
  {0x8, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x9, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xa, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xb, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},

  {0xc, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xd, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xe, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xf, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  /* -------- */
};
const volt32_opc_info_t volt32_g9_opc_info[VOLT32_OI_G9_DIM] =
{
  /* -------- */
  {0x0, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_D2_IMM6, "getaddrs.U"}, {VOLT32_AF_D2_IMM6, "getaddrs.S"}}},
  {0x1, VOLT32_LMP_ANYI_MAND,
    {{VOLT32_AF_DA_IB_IMM6, "getaddrs.U"}, {VOLT32_AF_DA_IB_IMM6, "getaddrs.S"}}},
  {0x2, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_D2_IMM6, "gettypes.U"}, {VOLT32_AF_D2_IMM6, "gettypes.S"}}},
  {0x3, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_D3_IMM6, "ldm.U"}, {VOLT32_AF_D3_IMM6, "ldm.S"}}},

  {0x4, VOLT32_LMP_ANYI_MAND,
    {{VOLT32_AF_IA_DB_IMM6, "fetchm.U"}, {VOLT32_AF_IA_DB_IMM6, "fetchm.S"}}},
  {0x5, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_D1_IMM6, "reload.U"}, {VOLT32_AF_D1_IMM6, "reload.S"}}},
  {0x6, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_IA_IMM6, "reload.U"}, {VOLT32_AF_IA_IMM6, "reload.S"}}},
  {0x7, VOLT32_LMP_ANYI_MAND, {{VOLT32_AF_D1_IMM6, "flush.U"}, {VOLT32_AF_D1_IMM6, "flush.S"}}},
  /* -------- */
};
const volt32_opc_info_t volt32_g10_opc_info[VOLT32_OI_G10_DIM] =
{
  /* -------- */
  {0x0, VOLT32_LMP_ANY, {{VOLT32_AF_DA_INTEN, "cpy.s"}, VOLT32_OI_SE_BLANK}},
  {0x1, VOLT32_LMP_ANY, {{VOLT32_AF_INTEN_DA, "cpy.s"}, VOLT32_OI_SE_BLANK}},
  {0x2, VOLT32_LMP_ANY, {{VOLT32_AF_DA_XCT, "cpy.s"}, VOLT32_OI_SE_BLANK}},
  {0x3, VOLT32_LMP_ANY, {{VOLT32_AF_XCT_DA, "cpy.s"}, VOLT32_OI_SE_BLANK}},

  {0x4, VOLT32_LMP_ANY, {{VOLT32_AF_DA_SWIARG0, "cpy.v"}, VOLT32_OI_SE_BLANK}},
  {0x5, VOLT32_LMP_ANY, {{VOLT32_AF_SWIARG0_DA, "cpy.v"}, VOLT32_OI_SE_BLANK}},
  {0x6, VOLT32_LMP_ANY, {{VOLT32_AF_DA_SWIARG1, "cpy.v"}, VOLT32_OI_SE_BLANK}},
  {0x7, VOLT32_LMP_ANY, {{VOLT32_AF_SWIARG1_DA, "cpy.v"}, VOLT32_OI_SE_BLANK}},
  /* -------- */
  {0x8, VOLT32_LMP_ANY, {{VOLT32_AF_DA_SWIARG2, "cpy.v"}, VOLT32_OI_SE_BLANK}},
  {0x9, VOLT32_LMP_ANY, {{VOLT32_AF_SWIARG2_DA, "cpy.v"}, VOLT32_OI_SE_BLANK}},
  {0xa, VOLT32_LMP_ANY, {{VOLT32_AF_DA_SWIARG3, "cpy.v"}, VOLT32_OI_SE_BLANK}},
  {0xb, VOLT32_LMP_ANY, {{VOLT32_AF_SWIARG3_DA, "cpy.v"}, VOLT32_OI_SE_BLANK}},

  {0xc, VOLT32_LMP_ANY, {{VOLT32_AF_D4, "swi"}, VOLT32_OI_SE_BLANK}},
  {0xd, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xe, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xf, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  /* -------- */
};
const volt32_opc_info_t volt32_g11_opc_info[VOLT32_OI_G11_DIM] =
{
  /* -------- */
  {0x0, VOLT32_LMP_ANY, {{VOLT32_AF_D3, "inu8.s"}, {VOLT32_AF_D3, "inu8.v"}}},
  {0x1, VOLT32_LMP_ANY, {{VOLT32_AF_D3, "ins8.s"}, {VOLT32_AF_D3, "ins8.v"}}},
  {0x2, VOLT32_LMP_ANY, {{VOLT32_AF_D3, "inu16.s"}, {VOLT32_AF_D3, "inu16.v"}}},
  {0x3, VOLT32_LMP_ANY, {{VOLT32_AF_D3, "ins16.s"}, {VOLT32_AF_D3, "ins16.v"}}},

  {0x4, VOLT32_LMP_ANY, {{VOLT32_AF_D3, "inu32.s"}, {VOLT32_AF_D3, "inu32.v"}}},
  {0x5, VOLT32_LMP_ANY, {{VOLT32_AF_D3, "ins32.s"}, {VOLT32_AF_D3, "ins32.v"}}},
  {0x6, VOLT32_LMP_ANY, {{VOLT32_AF_D3, "inu64.s"}, {VOLT32_AF_D3, "inu64.v"}}},
  {0x7, VOLT32_LMP_ANY, {{VOLT32_AF_D3, "ins64.s"}, {VOLT32_AF_D3, "ins64.v"}}},
  /* -------- */
  {0x8, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x9, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xa, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xb, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},

  {0xc, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xd, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xe, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xf, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  /* -------- */
  {0x10, VOLT32_LMP_ANY, {{VOLT32_AF_D3, "outu8.s"}, {VOLT32_AF_D3, "outu8.v"}}},
  {0x11, VOLT32_LMP_ANY, {{VOLT32_AF_D3, "outs8.s"}, {VOLT32_AF_D3, "outs8.v"}}},
  {0x12, VOLT32_LMP_ANY, {{VOLT32_AF_D3, "outu16.s"}, {VOLT32_AF_D3, "outu16.v"}}},
  {0x13, VOLT32_LMP_ANY, {{VOLT32_AF_D3, "outs16.s"}, {VOLT32_AF_D3, "outs16.v"}}},

  {0x14, VOLT32_LMP_ANY, {{VOLT32_AF_D3, "outu32.s"}, {VOLT32_AF_D3, "outu32.v"}}},
  {0x15, VOLT32_LMP_ANY, {{VOLT32_AF_D3, "outs32.s"}, {VOLT32_AF_D3, "outs32.v"}}},
  {0x16, VOLT32_LMP_ANY, {{VOLT32_AF_D3, "outu64.s"}, {VOLT32_AF_D3, "outu64.v"}}},
  {0x17, VOLT32_LMP_ANY, {{VOLT32_AF_D3, "outs64.s"}, {VOLT32_AF_D3, "outs64.v"}}},
  /* -------- */
  {0x18, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x19, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x1a, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x1b, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},

  {0x1c, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x1d, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x1e, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x1f, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  /* -------- */
};
const volt32_opc_info_t volt32_g12_opc_info[VOLT32_OI_G12_DIM] =
{
  /* -------- */
  {0x0, VOLT32_LMP_ANY, {{VOLT32_AF_D1_SIMM20, "cpyi.s"}, VOLT32_OI_SE_BLANK}},
  {0x1, VOLT32_LMP_ANY, {{VOLT32_AF_D1_IPCA_SIMM20, "addi.s"}, VOLT32_OI_SE_BLANK}},
  /* -------- */
};
/* -------- */
const volt32_opc_info_t volt32_g13_opc_info[VOLT32_OI_G13_DIM] =
{
  {0x0, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
};
const volt32_opc_info_t volt32_g14_opc_info[VOLT32_OI_G14_DIM] =
{
  {0x0, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
};
const volt32_opc_info_t volt32_g15_opc_info[VOLT32_OI_G15_DIM] =
{
  {0x0, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
};
/* -------- */
/* Pseudo instructions' `volt32_opc_info_t` */
const volt32_opc_info_t volt32_ps_opc_info[VOLT32_OI_PS_DIM] =
{
  /* -------- */
  {0x0, VOLT32_LMP_AUTOI_ANYD,
    {{VOLT32_OIAFPS_D2_SIMM11, "jdz.s"}, {VOLT32_OIAFPS_D2_SIMM11, "jdz.v"}}},
  {0x1, VOLT32_LMP_AUTOI_ANYD,
    {{VOLT32_OIAFPS_D2_SIMM11, "jdnz.s"}, {VOLT32_OIAFPS_D2_SIMM11, "jdnz.v"}}},
  {0x2, VOLT32_LMP_AUTOI_ANYD, 
    {{VOLT32_OIAFPS_BRANCH_SIMM20, "bz.s"}, {VOLT32_OIAFPS_BRANCH_SIMM20, "bz.v"}}},
  {0x3, VOLT32_LMP_AUTOI_ANYD,
    {{VOLT32_OIAFPS_BRANCH_SIMM20, "bnz.s"}, {VOLT32_OIAFPS_BRANCH_SIMM20, "bnz.v"}}},

  {0x4, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x5, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x6, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x7, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  /* -------- */
  {0x8, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x9, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xa, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xb, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},

  {0xc, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xd, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xe, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0xf, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  /* -------- */
  {0x10, VOLT32_LMP_ANYI_AUTOD, {{VOLT32_AF_D2_SIMM12, "ldu8i.s"}, {VOLT32_AF_D2_SIMM12, "ldu8i.v"}}},
  {0x11, VOLT32_LMP_ANYI_AUTOD, {{VOLT32_AF_D2_SIMM12, "lds8i.s"}, {VOLT32_AF_D2_SIMM12, "lds8i.v"}}},
  {0x12, VOLT32_LMP_ANYI_AUTOD,
    {{VOLT32_AF_D2_SIMM12, "ldu16i.s"}, {VOLT32_AF_D2_SIMM12, "ldu16i.v"}}},
  {0x13, VOLT32_LMP_ANYI_AUTOD,
    {{VOLT32_AF_D2_SIMM12, "lds16i.s"}, {VOLT32_AF_D2_SIMM12, "lds16i.v"}}},

  {0x14, VOLT32_LMP_ANYI_AUTOD,
    {{VOLT32_AF_D2_SIMM12, "ldu32i.s"}, {VOLT32_AF_D2_SIMM12, "ldu32i.v"}}},
  {0x15, VOLT32_LMP_ANYI_AUTOD,
    {{VOLT32_AF_D2_SIMM12, "lds32i.s"}, {VOLT32_AF_D2_SIMM12, "lds32i.v"}}},
  {0x16, VOLT32_LMP_ANYI_AUTOD,
    {{VOLT32_AF_D2_SIMM12, "ldu64i.s"}, {VOLT32_AF_D2_SIMM12, "ldu64i.v"}}},
  {0x17, VOLT32_LMP_ANYI_AUTOD,
    {{VOLT32_AF_D2_SIMM12, "lds64i.s"}, {VOLT32_AF_D2_SIMM12, "lds64i.v"}}},
  /* -------- */
  /* Reserved for future load type tags */
  {0x18, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x19, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x1a, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x1b, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},

  {0x1c, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x1d, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x1e, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x1f, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  /* -------- */
  {0x20, VOLT32_LMP_ANYI_AUTOD, {{VOLT32_AF_D3, "ldu8.s"}, {VOLT32_AF_D3, "ldu8.v"}}},
  {0x21, VOLT32_LMP_ANYI_AUTOD, {{VOLT32_AF_D3, "lds8.s"}, {VOLT32_AF_D3, "lds8.v"}}},
  {0x22, VOLT32_LMP_ANYI_AUTOD, {{VOLT32_AF_D3, "ldu16.s"}, {VOLT32_AF_D3, "ldu16.v"}}},
  {0x23, VOLT32_LMP_ANYI_AUTOD, {{VOLT32_AF_D3, "lds16.s"}, {VOLT32_AF_D3, "lds16.v"}}},

  {0x24, VOLT32_LMP_ANYI_AUTOD, {{VOLT32_AF_D3, "ldu32.s"}, {VOLT32_AF_D3, "ldu32.v"}}},
  {0x25, VOLT32_LMP_ANYI_AUTOD, {{VOLT32_AF_D3, "lds32.s"}, {VOLT32_AF_D3, "lds32.v"}}},
  {0x26, VOLT32_LMP_ANYI_AUTOD, {{VOLT32_AF_D3, "ldu64.s"}, {VOLT32_AF_D3, "ldu64.v"}}},
  {0x27, VOLT32_LMP_ANYI_AUTOD, {{VOLT32_AF_D3, "lds64.s"}, {VOLT32_AF_D3, "lds64.v"}}},
  /* -------- */
  /* Reserved for future load type tags */
  {0x28, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x29, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x2a, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x2b, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},

  {0x2c, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x2d, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x2e, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x2f, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  /* -------- */
  {0x30, VOLT32_LMP_ANYI_AUTOD, {{VOLT32_AF_D2_SIMM12, "stu8i.s"}, {VOLT32_AF_D2_SIMM12, "stu8i.v"}}},
  {0x31, VOLT32_LMP_ANYI_AUTOD, {{VOLT32_AF_D2_SIMM12, "sts8i.s"}, {VOLT32_AF_D2_SIMM12, "sts8i.v"}}},
  {0x32, VOLT32_LMP_ANYI_AUTOD,
    {{VOLT32_AF_D2_SIMM12, "stu16i.s"}, {VOLT32_AF_D2_SIMM12, "stu16i.v"}}},
  {0x33, VOLT32_LMP_ANYI_AUTOD,
    {{VOLT32_AF_D2_SIMM12, "sts16i.s"}, {VOLT32_AF_D2_SIMM12, "sts16i.v"}}},

  {0x34, VOLT32_LMP_ANYI_AUTOD,
    {{VOLT32_AF_D2_SIMM12, "stu32i.s"}, {VOLT32_AF_D2_SIMM12, "stu32i.v"}}},
  {0x35, VOLT32_LMP_ANYI_AUTOD,
    {{VOLT32_AF_D2_SIMM12, "sts32i.s"}, {VOLT32_AF_D2_SIMM12, "sts32i.v"}}},
  {0x36, VOLT32_LMP_ANYI_AUTOD,
    {{VOLT32_AF_D2_SIMM12, "stu64i.s"}, {VOLT32_AF_D2_SIMM12, "stu64i.v"}}},
  {0x37, VOLT32_LMP_ANYI_AUTOD,
    {{VOLT32_AF_D2_SIMM12, "sts64i.s"}, {VOLT32_AF_D2_SIMM12, "sts64i.v"}}},
  /* -------- */
  /* Reserved for future store type tags */
  {0x38, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x39, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x3a, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x3b, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},

  {0x3c, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x3d, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x3e, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x3f, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  /* -------- */
  {0x40, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x41, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x42, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x43, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},

  {0x44, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x45, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x46, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x47, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  /* -------- */
  {0x48, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x49, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x4a, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x4b, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},

  {0x4c, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x4d, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x4e, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  {0x4f, VOLT32_LMP_BAD, {VOLT32_OI_SE_BAD, VOLT32_OI_SE_BLANK}},
  /* -------- */
};
/* -------- */
//const int32_t test_2 = test_arr[2][3];
/* -------- */
//const volt32_opc_info_t **volt32_raw_opc_info_arr[VOLT32_OI_NUM_GRPS] =
//{
//  /* -------- */
//  &volt32_g0_opc_info,
//  &volt32_g1_opc_info,
//  &volt32_g2_opc_info,
//  &volt32_g3_opc_info,
//  &volt32_g4_opc_info,
//  &volt32_g5_opc_info,
//  &volt32_g6_opc_info,
//  &volt32_g7_opc_info,
//  &volt32_g8_opc_info,
//  &volt32_g9_opc_info,
//  &volt32_g10_opc_info,
//  &volt32_g11_opc_info,
//  &volt32_g12_opc_info,
//  /* -------- */
//};

volt32_oi_decode_t volt32_oi_decode(int32_t group, int32_t opcode)
{
  volt32_oi_decode_t ret =
  {
    .opc_info=NULL,
    .error={.grp_oor=false, .op_oor=false}
  };

  #define VOLT32_X(num, oi, dim) \
    case num : \
    { \
      if ((opcode >= 0) && (opcode < dim)) \
      { \
        ret.opc_info = (oi) + opcode; \
      } \
      else \
      { \
        ret.error.op_oor = true; \
      } \
      return ret; \
    } \

  switch (group)
  {
    VOLT32_LIST_OF_OI(VOLT32_X);

    default:
      ret.error.grp_oor = true;
      return ret;
  }

  #undef VOLT32_X

  return ret;
}
/* -------- */
