/* Disassemble volt32 instructions.
   Copyright (C) 2022 Free Software Foundation, Inc.

   Written by Andrew Clark (FL4SHK)

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
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,
   MA 02110-1301, USA.  */

#include "sysdep.h"
#include <stdio.h>

#define STATIC_TABLE
#define DEFINE_TABLE

#include "opcode/volt32.h"
#include "disassemble.h"
/* -------- */
//static fprintf_ftype fpr;
//static void *stream;

const char *volt32_ilar_names[VOLT32_NUM_ILARS] =
{
  "i0", "i1", "i2", "i3", "i4", "i5", "i6", "i7",
  "i8", "i9", "i10", "i11", "i12", "i13", "i14", "i15",
  "i16", "i17", "i18", "i19", "i20", "i21", "i22", "i23",
  "i24", "i25", "i26", "i27", "i28", "i29", "i30", "i31",
  "i32", "i33", "i34", "i35", "i36", "i37", "i38", "i39",
  "i40", "i41", "i42", "i43", "i44", "i45", "i46", "i47",
  "i48", "i49", "i50", "i51", "i52", "i53", "i54", "i55",
  "i56", "i57", "i58", "i59", "i60", "i61", "i62", "ipc"
};

const char *volt32_dlar_names[VOLT32_NUM_DLARS] =
{
  "d0", "d1", "d2", "d3", "d4", "d5", "d6", "d7",
  "d8", "d9", "d10", "d11", "d12", "d13", "d14", "d15",
  "d16", "d17", "d18", "d19", "d20", "d21", "d22", "d23",
  "d24", "d25", "d26", "d27", "d28", "d29", "d30", "d31",
  "d32", "d33", "d34", "d35", "d36", "d37", "d38", "d39",
  "d40", "d41", "d42", "d43", "d44", "d45", "d46", "d47",
  "d48", "d49", "d50", "d51", "d52", "d53", "d54", "d55",
  "d56", "d57", "d58", "dt0", "dt1", "dcp", "dfp", "dsp"
};

const char *volt32_auto_reg_names[VOLT32_NUM_AUTO_REGS] =
{
  /* -------- */
  "r0",
  /* -------- */
  "s1", "s2", "s3", "s4", "s5", "s6", "s7", "s8",
  "s9", "s10", "s11", "s12", "s13", "s14", "s15", "s16",
  "s17", "s18", "s19", "s20", "s21", "s22", "s23", "s24",
  /* -------- */
  "v25", "v26", "v27", "v28", "v29", "v30", "v31", "v32",
  "v33", "v34", "v35", "v36", "v37", "v38", "v39",
  /* -------- */
};

const char
  *volt32_reg_inten_name = "inten",
  *volt32_reg_xct_name = "xct",
  *volt32_reg_swiarg0_name = "swiarg0",
  *volt32_reg_swiarg1_name = "swiarg1",
  *volt32_reg_swiarg2_name = "swiarg2",
  *volt32_reg_swiarg3_name = "swiarg3";
/* -------- */
//int
//print_insn_volt32 (bfd_vma addr, struct disassemble_info * info)
//{
//  /* -------- */
//  int status;
//  stream = info->stream;
//  const volt32_opc_info_t *opcode = NULL;
//  bfd_byte buffer[VOLT32_INSTR_NUM_BYTES];
//  uint32_t iword;
//  /* -------- */
//  if (status = info->read_memory_func (addr, buffer, VOLT32_INSTR_NUM_BYTES, info))
//  {
//    goto fail;
//  }
//
//  iword = bfd_getb32 (buffer);
//  /* -------- */
//  const uint32_t
//    enc_grp = VOLT32_GET_BITS(iword, VOLT32_LEN_GRP, VOLT32_LO_GRP),
//
//    enc_lar_a = VOLT32_GET_BITS(iword, VOLT32_LEN_LAR, VOLT32_LO_LAR_A),
//    enc_lar_b = VOLT32_GET_BITS(iword, VOLT32_LEN_LAR, VOLT32_LO_LAR_B),
//    enc_lar_c = VOLT32_GET_BITS(iword, VOLT32_LEN_LAR, VOLT32_LO_LAR_C),
//    enc_lar_d = VOLT32_GET_BITS(iword, VOLT32_LEN_LAR, VOLT32_LO_LAR_D),
//    /* -------- */
//    enc_g0_v = VOLT32_GET_BITS(iword, VOLT32_LEN_V_S, VOLT32_LO_G0_V),
//    enc_g0_opc = VOLT32_GET_BITS(iword, VOLT32_LEN_G0_OPC, VOLT32_LO_OPC),
//    /* -------- */
//    enc_g1_opc = VOLT32_GET_BITS(iword, VOLT32_LEN_G1_OPC, VOLT32_LO_OPC),
//    /* -------- */
//    enc_g2_g3_simm7 = VOLT32_GET_BITS(iword, VOLT32_LEN_G2_G3_SIMM7, VOLT32_LO_G2_G3_SIMM7),
//    enc_g2_g3_opc = VOLT32_GET_BITS(iword, VOLT32_LEN_G2_G3_OPC, VOLT32_LO_OPC),
//    /* -------- */
//    enc_g4_opc = VOLT32_GET_BITS(iword, VOLT32_LEN_G4_OPC, VOLT32_LO_OPC),
//    /* -------- */
//    enc_g5_isimm6 = VOLT32_GET_BITS(iword, VOLT32_LEN_G5_ISIMM6, VOLT32_LO_G5_ISIMM6),
//    enc_g5_jimm4 = VOLT32_GET_BITS(iword, VOLT32_LEN_G5_JIMM4, VOLT32_LO_G5_JIMM4),
//    /* -------- */
//    enc_g6_iimm5 = VOLT32_GET_BITS(iword, VOLT32_LEN_G6_IIMM5, VOLT32_LO_G6_IIMM5),
//    enc_g6_jimm5 = VOLT32_GET_BITS(iword, VOLT32_LEN_G6_JIMM5, VOLT32_LO_G6_JIMM5),
//    enc_g6_v = VOLT32_GET_BITS(iword, VOLT32_LEN_V_S, VOLT32_LO_G6_V),
//    enc_g6_opc = VOLT32_GET_BITS(iword, VOLT32_LEN_G6_OPC, VOLT32_LO_OPC),
//    /* -------- */
//    /* -------- */
//  /* -------- */
//}
/* -------- */
