/* Definitions for decoding the volt32 opcode table.
   Copyright (C) 2022 Free Software Foundation, Inc.

   Written by Andrew Clark (FL4SHK)

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA
   02110-1301, USA.  */

#include <stdint.h>
#include <stdbool.h>

#define VOLT32_GET_BITS(x, len, lo) (((x) >> (lo)) & ((((uint64_t)1) << (len)) - ((uint64_t)1)))

/* Assembler mode for LAR use the instruction belongs to */
typedef enum volt32_lar_mode_t
{
  VOLT32_LM_BAD,                    /* Reserved/invalid instructions */
  VOLT32_LM_MAN,                    /* manual LAR use */
  VOLT32_LM_AUTO,                   /* automatic LAR use */ 
  VOLT32_LM_ANY,                    /* either LAR use type */
  VOLT32_LM_LIM,                    /* the last value of this `enum` */
} volt32_lar_mode_t;

typedef struct volt32_lar_mode_pair_t
{
  volt32_lar_mode_t i, d;
} volt32_lar_mode_pair_t;

typedef enum volt32_arg_form_t
{
  VOLT32_AF_BAD,                    /* <bad instruction> */

  VOLT32_AF_D1,                     /* dA */
  VOLT32_AF_D2,                     /* dA, dB */
  VOLT32_AF_D3,                     /* dA, dB, dC */
  VOLT32_AF_D4,                     /* dA, dB, dC, dD */
  VOLT32_AF_DA_DBA_DC,              /* dA, dB.addr, dC */
  VOLT32_AF_DA_IBA_DC,              /* dA, iB.addr, dC */

  VOLT32_AF_D2_SIMM12,              /* dA, dB, simm12 */
  VOLT32_AF_DA_DBA_SIMM12,          /* dA, dB.addr, simm12 */

  VOLT32_AF_IA_IB_DC_JIMM4,         /* iA, iB, dC, jimm4 */
  VOLT32_AF_IA_IB_ISIMM11_JIMM4,    /* iA, iB, isimm11, jimm4 */
  VOLT32_AF_DA_IB_IIMM5_JIMM5,      /* dA, iB, iimm5, jimm5 */
  VOLT32_AF_DA_IB_IIMM5,            /* dA, iB, iimm5 */

  VOLT32_AF_D2_IMM6,                /* dA, dB, imm6 */
  VOLT32_AF_DA_IB_IMM6,             /* dA, iB, imm6 */
  VOLT32_AF_D3_IMM6,                /* dA, dB, dC, imm6 */
  VOLT32_AF_IA_DB_IMM6,             /* iA, dB, imm6 */

  VOLT32_AF_DA_INTEN,               /* dA, inten */
  VOLT32_AF_INTEN_DA,               /* intent, dA */
  VOLT32_AF_DA_XCT,                 /* dA, xct */
  VOLT32_AF_XCT_DA,                 /* xct, dA */

  VOLT32_AF_DA_SWIARG0,             /* dA, swiarg0 */
  VOLT32_AF_SWIARG0_DA,             /* swiarg0, dA */
  VOLT32_AF_DA_SWIARG1,             /* dA, swiarg1 */
  VOLT32_AF_SWIARG1_DA,             /* swiarg1, dA */

  VOLT32_AF_DA_SWIARG2,             /* dA, swiarg2 */
  VOLT32_AF_SWIARG2_DA,             /* swiarg2, dA */
  VOLT32_AF_DA_SWIARG3,             /* dA, swiarg3 */
  VOLT32_AF_SWIARG3_DA,             /* swiarg3, dA */

  VOLT32_AF_D1_IMM6,                /* dA, imm6 */
  VOLT32_AF_IA_IMM6,                /* iA, imm6 */
  VOLT32_AF_D1_SIMM20,              /* dA, simm20 */
  VOLT32_AF_D1_IPCA_SIMM20,         /* dA, ipc.addr, simm20 */

  /* "AFPS" is short for "arg form, pseudo" */
  VOLT32_OIAFPS_D2_SIMM11,          /* dA, dB, simm11 */
  VOLT32_OIAFPS_BRANCH_SIMM20,      /* dA, simm20 (pcrel) */

  VOLT32_AF_LIM,                    /* the last value of this `enum` */
} volt32_arg_form_t;


#define VOLT32_INT_NULL ((int)-1)

/* For `strn...()` */
#define VOLT32_OI_NAME_MAX_LEN 20
#define VOLT32_REG_NAME_MAX_LEN 20

/* Max pseudo-instruction sequence length */
#define VOLT32_PS_INSN_MAX_LEN 2

#define VOLT32_OI_SUB_ELEMS_LEN 2

typedef struct volt32_oi_sub_elem_t
{
  volt32_arg_form_t arg_form;
  const char *name;
} volt32_oi_sub_elem_t;

#define VOLT32_OI_NULL_OPCODE ((int32_t)(-1))

typedef struct volt32_opc_info_t
{
  int32_t opcode;
  volt32_lar_mode_pair_t lm_pair;
  volt32_oi_sub_elem_t sub_elems[VOLT32_OI_SUB_ELEMS_LEN];
} volt32_opc_info_t;

typedef struct volt32_oi_decode_t
{
  /* -------- */
  const volt32_opc_info_t *opc_info;

  struct
  {
    //bool dbg_grp_switch_eek: 1;
    bool grp_oor: 1;            /* group out of range */
    bool op_oor: 1;             /* opcode out of range */
  } error;
  /* -------- */
} volt32_oi_decode_t;

static inline int volt32_oi_name_strncmp(const char *oi_name, const char *to_cmp)
{
  return strncmp(oi_name, to_cmp, VOLT32_OI_NAME_MAX_LEN);
}
static inline int volt32_oi_name_strnlen(const char *oi_name)
{
  return strnlen(oi_name, VOLT32_OI_NAME_MAX_LEN);
}


//static inline bool volt32_oi_has_one_insn(const volt32_opc_info_t *opc_info)
//{
//  //return (strnlen(opc_info->sub_elems[1].name, VOLT32_OI_NAME_MAX_LEN) == 0);
//  //return (opc_info->sub_elems[1].name[0] == '\0');
//
//  //return (volt32_oi_name_strnlen(opc_info->sub_elems[1].name) == 0);
//  for (int i=1; i<VOLT32_OI_SUB_ELEMS_LEN; ++i)
//  {
//    if (opc_info->sub_elems[i].name[0] != '\0')
//    {
//      return false;
//    }
//  }
//  return true;
//}
static inline int volt32_oi_calc_name_idx(const volt32_opc_info_t *opc_info,
  const char *oi_name)
{
  for (int i=0; i<VOLT32_OI_SUB_ELEMS_LEN; ++i)
  {
    //if (strncmp(opc_info->sub_elems[i].name, oi_name, VOLT32_OI_NAME_MAX_LEN) == 0)
    if (volt32_oi_name_strncmp(opc_info->sub_elems[i].name, oi_name) == 0)
    {
      return i;
    }
  }
  return VOLT32_INT_NULL;
}

static inline bool volt32_oi_is_single(const volt32_opc_info_t *opc_info)
{
  for (int i=1; i<VOLT32_OI_SUB_ELEMS_LEN; ++i)
  {
    if (volt32_oi_name_strnlen(opc_info->sub_elems[i].name) > 0)
    {
      return false;
    }
  }
  return true;
}

extern volt32_oi_decode_t volt32_oi_decode(int32_t group, int32_t opcode);

/* Last two chars */
static inline bool volt32_oi_name_cmp_last_dot_c(const char *oi_name, char c)
{
  const size_t
    //oi_name_len = strnlen(oi_name, VOLT32_OI_NAME_MAX_LEN);
    oi_name_len = volt32_oi_name_strnlen(oi_name);

  return ((oi_name_len >= 2)
    && (oi_name[oi_name_len - 2] == '.')
    && (oi_name[oi_name_len - 1] == c));
}
static inline bool volt32_oi_name_is_scal(const char *oi_name)
{
  return volt32_oi_name_cmp_last_dot_c(oi_name, 's');
}
static inline bool volt32_oi_name_is_vec(const char *oi_name)
{
  return volt32_oi_name_cmp_last_dot_c(oi_name, 'v');
}
static inline bool volt32_oi_name_is_reduce(const char *oi_name)
{
  return volt32_oi_name_cmp_last_dot_c(oi_name, 'r');
}
static inline bool volt32_oi_name_is_user(const char *oi_name)
{
  return volt32_oi_name_cmp_last_dot_c(oi_name, 'U');
}
static inline bool volt32_oi_name_is_supervisor(const char *oi_name)
{
  return volt32_oi_name_cmp_last_dot_c(oi_name, 'S');
}


#define VOLT32_OI_G0_DIM 16
#define VOLT32_OI_G1_DIM 16
#define VOLT32_OI_G2_DIM 16
#define VOLT32_OI_G3_DIM 16
#define VOLT32_OI_G4_DIM 16
#define VOLT32_OI_G5_DIM 16
#define VOLT32_OI_G6_DIM 16
#define VOLT32_OI_G7_DIM 2
#define VOLT32_OI_G8_DIM 16
#define VOLT32_OI_G9_DIM 8
#define VOLT32_OI_G10_DIM 16
#define VOLT32_OI_G11_DIM 32
#define VOLT32_OI_G12_DIM 2
#define VOLT32_OI_G13_DIM 1
#define VOLT32_OI_G14_DIM 1
#define VOLT32_OI_G15_DIM 1

#define VOLT32_OI_MAX_DIM 128

#define VOLT32_OI_PS_DIM 80

extern const volt32_opc_info_t
  volt32_g0_opc_info[VOLT32_OI_G0_DIM],
  volt32_g1_opc_info[VOLT32_OI_G1_DIM],
  volt32_g2_opc_info[VOLT32_OI_G2_DIM],
  volt32_g3_opc_info[VOLT32_OI_G3_DIM],
  volt32_g4_opc_info[VOLT32_OI_G4_DIM],
  volt32_g5_opc_info[VOLT32_OI_G5_DIM],
  volt32_g6_opc_info[VOLT32_OI_G6_DIM],
  volt32_g7_opc_info[VOLT32_OI_G7_DIM],
  volt32_g8_opc_info[VOLT32_OI_G8_DIM],
  volt32_g9_opc_info[VOLT32_OI_G9_DIM],
  volt32_g10_opc_info[VOLT32_OI_G10_DIM],
  volt32_g11_opc_info[VOLT32_OI_G11_DIM],
  volt32_g12_opc_info[VOLT32_OI_G12_DIM],
  volt32_g13_opc_info[VOLT32_OI_G13_DIM],
  volt32_g14_opc_info[VOLT32_OI_G14_DIM],
  volt32_g15_opc_info[VOLT32_OI_G15_DIM],

  volt32_ps_opc_info[VOLT32_OI_PS_DIM];

#define VOLT32_OI_NUM_GRPS 16

//#define VOLT32_OI_REAL_NUM_GRPS 13
#define VOLT32_LIST_OF_OI(X) \
  X(0, volt32_g0_opc_info, VOLT32_OI_G0_DIM) \
  X(1, volt32_g1_opc_info, VOLT32_OI_G1_DIM) \
  X(2, volt32_g2_opc_info, VOLT32_OI_G2_DIM) \
  X(3, volt32_g3_opc_info, VOLT32_OI_G3_DIM) \
  X(4, volt32_g4_opc_info, VOLT32_OI_G4_DIM) \
  X(5, volt32_g5_opc_info, VOLT32_OI_G5_DIM) \
  X(6, volt32_g6_opc_info, VOLT32_OI_G6_DIM) \
  X(7, volt32_g7_opc_info, VOLT32_OI_G7_DIM) \
  X(8, volt32_g8_opc_info, VOLT32_OI_G8_DIM) \
  X(9, volt32_g9_opc_info, VOLT32_OI_G9_DIM) \
  X(10, volt32_g10_opc_info, VOLT32_OI_G10_DIM) \
  X(11, volt32_g11_opc_info, VOLT32_OI_G11_DIM) \
  X(12, volt32_g12_opc_info, VOLT32_OI_G12_DIM) \
  X(13, volt32_g13_opc_info, VOLT32_OI_G13_DIM) \
  X(14, volt32_g14_opc_info, VOLT32_OI_G14_DIM) \
  X(15, volt32_g15_opc_info, VOLT32_OI_G15_DIM) \

//extern const volt32_opc_info_t
//  volt32_raw_opc_info[][VOLT32_OI_REAL_NUM_GRPS];
//extern const size_t
//  VOLT32_OPC_INFO_DIM_ARR[VOLT32_OI_REAL_NUM_GRPS];

//extern const volt32_opc_info_t
//  **volt32_raw_opc_info_arr[VOLT32_OI_REAL_NUM_GRPS];

#define VOLT32_NUM_ILARS 64
#define VOLT32_NUM_DLARS 64

#define VOLT32_NUM_AUTO_REGS 40

#define VOLT32_NUM_NZ_AUTO_SCAL_REGS 24
#define VOLT32_NZ_AUTO_SCAL_REG_FIRST_IDX 1

#define VOLT32_NUM_NZ_AUTO_VEC_REGS 15
#define VOLT32_NZ_AUTO_VEC_REG_FIRST_IDX 25

extern const char
  *volt32_ilar_names[VOLT32_NUM_ILARS],
  *volt32_dlar_names[VOLT32_NUM_DLARS],

  *volt32_auto_reg_names[VOLT32_NUM_AUTO_REGS];

extern const char
  *volt32_reg_inten_name,
  *volt32_reg_xct_name,
  *volt32_reg_swiarg0_name,
  *volt32_reg_swiarg1_name,
  *volt32_reg_swiarg2_name,
  *volt32_reg_swiarg3_name;

#define VOLT32_INSN_NUM_BYTES 4
#define VOLT32_INSN_NUM_BITS (VOLT32_INSN_NUM_BYTES * 8)

#define VOLT32_LEN_GRP 4
#define VOLT32_LO_GRP 28

#define VOLT32_LEN_LAR 6
#define VOLT32_LO_LAR_A 22
#define VOLT32_LO_LAR_B 16
#define VOLT32_LO_LAR_C 10
#define VOLT32_LO_LAR_D 4

#define VOLT32_LEN_LAR_DL 5
#define VOLT32_LO_LAR_DL 5

#define VOLT32_LEN_V_S 1
//#define VOLT32_LO_G0_V 4
//#define VOLT32_LO_G6_V 5
//#define VOLT32_LO_G7_S 3
//#define VOLT32_LO_G9_V 4
//#define VOLT32_LO_G10_V 0

//#define VOLT32_LEN_G0_OPC 4
//#define VOLT32_LEN_G1_OPC 4
//#define VOLT32_LEN_G2_G3_OPC 3
//#define VOLT32_LEN_G4_OPC 3
//#define VOLT32_LEN_G5_OPC 1
//#define VOLT32_LEN_G6_OPC 5
//#define VOLT32_LEN_G7_OPC 3
//#define VOLT32_LEN_G8_OPC 4
//#define VOLT32_LEN_G9_OPC 4
//#define VOLT32_LEN_G11_OPC 3
#define VOLT32_LO_OPC 0

#define VOLT32_LEN_G2_G3_G5_SIMM12 12
#define VOLT32_LO_G2_G3_G5_SIMM12 3

//#define VOLT32_LEN_G5_ISIMM11 11
//#define VOLT32_LO_G5_ISIMM11 5
//#define VOLT32_LEN_G5_JIMM4 4
//#define VOLT32_LO_G5_JIMM4 1

//#define VOLT32_LEN_G6_IIMM5 5
//#define VOLT32_LO_G6_IIMM5 11
//#define VOLT32_LEN_G6_JIMM5 5
//#define VOLT32_LO_G6_JIMM5 6
//
//#define VOLT32_LEN_G7_IMM6 6
//#define VOLT32_LO_G7_IMM6 4
//
//#define VOLT32_LEN_G10_SIMM15 15
//#define VOLT32_LO_G10_SIMM15 1
//
//#define VOLT32_LEN_G11_SIMM13 13
//#define VOLT32_LO_G11_SIMM13 3
