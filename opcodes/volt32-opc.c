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

const volt32_opc_info_t volt32_g0_opc_info[VOLT32_OI_G0_DIM] =
{
  { 0x0, VOLT32_AF_D3, { "add.s", "add.v" } },
  { 0x1, VOLT32_AF_D3, { "sub.s", "sub.v" } },
  { 0x2, VOLT32_AF_D3, { "slt.s", "slt.v" } },
  { 0x3, VOLT32_AF_D3, { "mul.s", "mul.v" } },
  
  { 0x4, VOLT32_AF_D3, { "and.s", "and.v" } },
  { 0x5, VOLT32_AF_D3, { "or.s", "or.v" } },
  { 0x6, VOLT32_AF_D3, { "xor.s", "xor.v" } },
  { 0x7, VOLT32_AF_D3, { "shl.s", "shl.v" } },

  { 0x8, VOLT32_AF_D3, { "shr.s", "shr.v" } },
  { 0x9, VOLT32_AF_D3, { "rol.s", "rol.v" } },
  { 0xa, VOLT32_AF_D3, { "ror.s", "ror.v" } },
  { 0xb, VOLT32_AF_DA_DBA_DC, { "add.s", "add.v" } },

  { 0xc, VOLT32_AF_DA_DBA_DC, { "shl.s", "shl.v" } },
  { 0xd, VOLT32_AF_DA_IBA_DC, { "add.s", "add.v" } },
  { 0xe, VOLT32_AF_D4, { "div.s"  "div.s" } },
  { 0xf, VOLT32_AF_D4, { "div.v"  "div.v" } },
};
const volt32_opc_info_t volt32_g1_opc_info[VOLT32_OI_G1_DIM] =
{
  { 0x0, VOLT32_AF_D2, { "add.r", "add.r" } },
  { 0x1, VOLT32_AF_D2, { "mul.r", "mul.r" } },
  { 0x2, VOLT32_AF_D2, { "max.r", "max.r" } },
  { 0x3, VOLT32_AF_D2, { "min.r", "min.r" } },

  { 0x4, VOLT32_AF_D2, { "and.r", "and.r" } },
  { 0x5, VOLT32_AF_D2, { "or.r", "or.r" } },
  { 0x6, VOLT32_AF_D2, { "xor.r", "xor.r" } },
  { 0x7, VOLT32_AF_BAD, { "bad", "bad" } },

  { 0x8, VOLT32_AF_BAD, { "bad", "bad" } },
  { 0x9, VOLT32_AF_BAD, { "bad", "bad" } },
  { 0xa, VOLT32_AF_BAD, { "bad", "bad" } },
  { 0xb, VOLT32_AF_BAD, { "bad", "bad" } },

  { 0xc, VOLT32_AF_BAD, { "bad", "bad" } },
  { 0xd, VOLT32_AF_BAD, { "bad", "bad" } },
  { 0xe, VOLT32_AF_BAD, { "bad", "bad" } },
  { 0xf, VOLT32_AF_BAD, { "bad", "bad" } },
};
const volt32_opc_info_t volt32_g2_opc_info[VOLT32_OI_G2_DIM] =
{
  { 0x0, VOLT32_AF_D2_SIMM13, { "ldu8", "ldu8" } },
  { 0x1, VOLT32_AF_D2_SIMM13, { "lds8", "lds8" } },
  { 0x2, VOLT32_AF_D2_SIMM13, { "ldu16", "ldu16" } },
  { 0x3, VOLT32_AF_D2_SIMM13, { "lds16", "lds16" } },

  { 0x4, VOLT32_AF_D2_SIMM13, { "ldu32", "ldu32" } },
  { 0x5, VOLT32_AF_D2_SIMM13, { "lds32", "lds32" } },
  { 0x6, VOLT32_AF_D2_SIMM13, { "ldu64", "ldu64" } },
  { 0x7, VOLT32_AF_D2_SIMM13, { "lds64", "lds64" } },
};
const volt32_opc_info_t volt32_g3_opc_info[VOLT32_OI_G3_DIM] =
{
  { 0x0, VOLT32_AF_D2_SIMM13, { "stu8", "stu8" } },
  { 0x1, VOLT32_AF_D2_SIMM13, { "sts8", "sts8" } },
  { 0x2, VOLT32_AF_D2_SIMM13, { "stu16", "stu16" } },
  { 0x3, VOLT32_AF_D2_SIMM13, { "sts16", "sts16" } },

  { 0x4, VOLT32_AF_D2_SIMM13, { "stu32", "stu32" } },
  { 0x5, VOLT32_AF_D2_SIMM13, { "sts32", "sts32" } },
  { 0x6, VOLT32_AF_D2_SIMM13, { "stu64", "stu64" } },
  { 0x7, VOLT32_AF_D2_SIMM13, { "sts64", "sts64" } },
};
const volt32_opc_info_t volt32_g4_opc_info[VOLT32_OI_G4_DIM] =
{
  { 0x0, VOLT32_AF_D2, { "dpu8", "dpu8" } },
  { 0x1, VOLT32_AF_D2, { "dps8", "dps8" } },
  { 0x2, VOLT32_AF_D2, { "dpu16", "dpu16" } },
  { 0x3, VOLT32_AF_D2, { "dps16", "dps16" } },

  { 0x4, VOLT32_AF_D2, { "dpu32", "dpu32" } },
  { 0x5, VOLT32_AF_D2, { "dps32", "dps32" } },
  { 0x6, VOLT32_AF_D2, { "dpu64", "dpu64" } },
  { 0x7, VOLT32_AF_D2, { "dps64", "dps64" } },
};
const volt32_opc_info_t volt32_g5_opc_info[VOLT32_OI_G5_DIM] =
{
  { 0x0, VOLT32_AF_IA_IB_DC_JIMM4, { "fetch", "fetch" } },
  { 0x1, VOLT32_AF_IA_IB_ISIMM11_JIMM4, { "fetch", "fetch" } },
};
const volt32_opc_info_t volt32_g6_opc_info[VOLT32_OI_G6_DIM] =
{
  { 0x0, VOLT32_AF_DA_IB_IIMM5_JIMM5, { "sel.s", "sel.v" } },
  { 0x1, VOLT32_AF_DA_IB_IIMM5, { "jz.s", "jz.v" } },
  { 0x2, VOLT32_AF_DA_IB_IIMM5, { "jnz.s", "jnz.v" } },
  { 0x3, VOLT32_AF_D1, { "reti.s", "reti.v" } },

  { 0x4, VOLT32_AF_D1, { "retx.s", "retx.v" } },
  { 0x5, VOLT32_AF_BAD, { "bad", "bad" } },
  { 0x6, VOLT32_AF_BAD, { "bad", "bad" } },
  { 0x7, VOLT32_AF_BAD, { "bad", "bad" } },

  { 0x8, VOLT32_AF_BAD, { "bad", "bad" } },
  { 0x9, VOLT32_AF_BAD, { "bad", "bad" } },
  { 0xa, VOLT32_AF_BAD, { "bad", "bad" } },
  { 0xb, VOLT32_AF_BAD, { "bad", "bad" } },

  { 0xc, VOLT32_AF_BAD, { "bad", "bad" } },
  { 0xd, VOLT32_AF_BAD, { "bad", "bad" } },
  { 0xe, VOLT32_AF_BAD, { "bad", "bad" } },
  { 0xf, VOLT32_AF_BAD, { "bad", "bad" } },
};
const volt32_opc_info_t volt32_g7_opc_info[VOLT32_OI_G7_DIM] =
{
  { 0x0, VOLT32_AF_D2_IMM6, { "getaddrs.U", "getaddrs.S" } },
  { 0x1, VOLT32_AF_DA_IB_IMM6, { "getaddrs.U", "getaddrs.S" } },
  { 0x2, VOLT32_AF_D2_IMM6, { "gettypes.U", "gettypes.S" } },
  { 0x3, VOLT32_AF_D3_IMM6, { "ldm.U", "ldm.S" } },

  { 0x4, VOLT32_AF_IA_DB_IMM6, { "fetchm.U", "fetchm.S" } },
  { 0x5, VOLT32_AF_BAD, { "bad", "bad" } },
  { 0x6, VOLT32_AF_BAD, { "bad", "bad" } },
  { 0x7, VOLT32_AF_BAD, { "bad", "bad" } },
};
const volt32_opc_info_t volt32_g8_opc_info[VOLT32_OI_G8_DIM] =
{
  { 0x0, VOLT32_AF_DA_INTEN, { "cpy", "cpy" } },
  { 0x1, VOLT32_AF_INTEN_DA, { "cpy", "cpy" } },
  { 0x2, VOLT32_AF_DA_XCT, { "cpy", "cpy" } },
  { 0x3, VOLT32_AF_XCT_DA, { "cpy", "cpy" } },

  { 0x4, VOLT32_AF_DA_SWIARG0, { "cpy", "cpy" } },
  { 0x5, VOLT32_AF_SWIARG0_DA, { "cpy", "cpy" } },
  { 0x6, VOLT32_AF_DA_SWIARG1, { "cpy", "cpy" } },
  { 0x7, VOLT32_AF_SWIARG1_DA, { "cpy", "cpy" } },

  { 0x8, VOLT32_AF_DA_SWIARG2, { "cpy", "cpy" } },
  { 0x9, VOLT32_AF_SWIARG2_DA, { "cpy", "cpy" } },
  { 0xa, VOLT32_AF_DA_SWIARG3, { "cpy", "cpy" } },
  { 0xb, VOLT32_AF_SWIARG3_DA, { "cpy", "cpy" } },

  { 0xc, VOLT32_AF_D4, { "swi", "swi" } },
  { 0xd, VOLT32_AF_BAD, { "bad", "bad" } },
  { 0xe, VOLT32_AF_BAD, { "bad", "bad" } },
  { 0xf, VOLT32_AF_BAD, { "bad", "bad" } },
};
const volt32_opc_info_t volt32_g9_opc_info[VOLT32_OI_G9_DIM] =
{
  { 0x0, VOLT32_AF_D3, { "inu8.s", "inu8.v" } },
  { 0x1, VOLT32_AF_D3, { "ins8.s", "ins8.v" } },
  { 0x2, VOLT32_AF_D3, { "inu16.s", "inu16.v" } },
  { 0x3, VOLT32_AF_D3, { "ins16.s", "ins16.v" } },

  { 0x4, VOLT32_AF_D3, { "inu32.s", "inu32.v" } },
  { 0x5, VOLT32_AF_D3, { "ins32.s", "ins32.v" } },
  { 0x6, VOLT32_AF_D3, { "inu64.s", "inu64.v" } },
  { 0x7, VOLT32_AF_D3, { "ins64.s", "ins64.v" } },

  { 0x8, VOLT32_AF_D3, { "outu8.s", "outu8.v" } },
  { 0x9, VOLT32_AF_D3, { "outs8.s", "outs8.v" } },
  { 0xa, VOLT32_AF_D3, { "outu16.s", "outu16.v" } },
  { 0xb, VOLT32_AF_D3, { "outs16.s", "outs16.v" } },

  { 0xc, VOLT32_AF_D3, { "outu32.s", "outu32.v" } },
  { 0xd, VOLT32_AF_D3, { "outs32.s", "outs32.v" } },
  { 0xe, VOLT32_AF_D3, { "outu64.s", "outu64.v" } },
  { 0xf, VOLT32_AF_D3, { "outs64.s", "outs64.v" } },
};
const volt32_opc_info_t volt32_g10_opc_info[VOLT32_OI_G10_DIM] =
{
  { 0x0, VOLT32_AF_D2_IPCA_SIMM15_PCREL, { "add.s", "add.v" } }
};
const volt32_opc_info_t volt32_g11_opc_info[VOLT32_OI_G11_DIM] =
{
  { 0x0, VOLT32_AF_D2_IPCA_SIMM13_PCREL, { "ldu8", "ldu8" } },
  { 0x1, VOLT32_AF_D2_IPCA_SIMM13_PCREL, { "lds8", "lds8" } },
  { 0x2, VOLT32_AF_D2_IPCA_SIMM13_PCREL, { "ldu16", "ldu16" } },
  { 0x3, VOLT32_AF_D2_IPCA_SIMM13_PCREL, { "lds16", "lds16" } },

  { 0x4, VOLT32_AF_D2_IPCA_SIMM13_PCREL, { "ldu32", "ldu32" } },
  { 0x5, VOLT32_AF_D2_IPCA_SIMM13_PCREL, { "lds32", "lds32" } },
  { 0x6, VOLT32_AF_D2_IPCA_SIMM13_PCREL, { "ldu64", "ldu64" } },
  { 0x7, VOLT32_AF_D2_IPCA_SIMM13_PCREL, { "lds64", "lds64" } },
};
