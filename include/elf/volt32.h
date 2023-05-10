/* volt32 ELF support for BFD.
   Copyright (C) 2022 Free Software Foundation, Inc.

   Written by Andrew Clark (FL4SHK)

   This file is part of BFD, the Binary File Descriptor library.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */

#ifndef _ELF_VOLT32_H
#define _ELF_VOLT32_H

#include "elf/reloc-macros.h"

/* Relocation types.  */
START_RELOC_NUMBERS (elf_volt32_reloc_type)
  RELOC_NUMBER (R_VOLT32_NONE, 0)
  RELOC_NUMBER (R_VOLT32_32, 1)
  RELOC_NUMBER (R_VOLT32_G2_G3_G5_SIMM12, 2)
  RELOC_NUMBER (R_VOLT32_G7_ISIMM11, 3)
  RELOC_NUMBER (R_VOLT32_G7_JIMM4, 4)
  RELOC_NUMBER (R_VOLT32_G8_IIMM5, 5)
  RELOC_NUMBER (R_VOLT32_G8_JIMM5, 6)
  RELOC_NUMBER (R_VOLT32_G9_IMM6, 7)
  RELOC_NUMBER (R_VOLT32_G12_SIMM20, 8)
  RELOC_NUMBER (R_VOLT32_G12_SIMM20_PCREL, 9)
  /* RELOC_NUMBER (R_VOLT32_G12_CPYIS_SIMM32, 9) */
  /* RELOC_NUMBER (R_VOLT32_G12_CPYIS_SIMM64, 10) */
  /* RELOC_NUMBER (R_VOLT32_G10_SIMM15_PCREL, 9) */
  /* RELOC_NUMBER (R_VOLT32_G11_SIMM13_PCREL, 10) */
END_RELOC_NUMBERS (R_VOLT32_count)

#endif /* _ELF_VOLT32_H */
