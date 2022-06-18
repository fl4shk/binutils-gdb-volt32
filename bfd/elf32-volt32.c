/* moxie-specific support for 32-bit ELF.
   Copyright (C) 2022 Free Software Foundation, Inc.

   Contributed by Andrew Clark (FL4SHK)

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
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,
   MA 02110-1301, USA.  */

#include "sysdep.h"
#include "bfd.h"
#include "libbfd.h"
#include "elf-bfd.h"
#include "elf/volt32.h"

static reloc_howto_type volt32_elf_howto_table [] =
{
  /* This reloc does nothing. */
  HOWTO (R_VOLT32_NONE,		/* type */
	 0,			/* rightshift */
	 0,			/* size */
	 0,			/* bitsize */
	 false,			/* pc_relative */
	 0,			/* bitpos */
	 complain_overflow_dont, /* complain_on_overflow */
	 bfd_elf_generic_reloc,	/* special_function */
	 "R_VOLT32_NONE",		/* name */
	 false,			/* partial_inplace */
	 0,			/* src_mask */
	 0,			/* dst_mask */
	 false),		/* pcrel_offset */
/* -------- */
  HOWTO (R_VOLT32_G2_G3_SIMM7,	/* type */
	 0,			/* rightshift */
	 1,			/* size */
	 7,			/* bitsize */
	 false,			/* pc_relative */
	 3,			/* bitpos */
	 complain_overflow_signed, /* complain_on_overflow */
	 bfd_elf_generic_reloc,	/* special_function */
	 "R_VOLT32_G2_G3_SIMM7",/* name */
	 false,			/* partial_inplace */
	 0x00000000,		/* src_mask */
	 0x000003f8,		/* dst_mask */
	 false),		/* pcrel_offset */
/* -------- */
  HOWTO (R_VOLT32_G5_ISIMM6,	/* type */
	 0,			/* rightshift */
	 1,			/* size */
	 6,			/* bitsize */
	 false,			/* pc_relative */
	 4,			/* bitpos */
	 complain_overflow_signed, /* complain_on_overflow */
	 bfd_elf_generic_reloc,	/* special_function */
	 "R_VOLT32_G5_ISIMM6",	/* name */
	 false,			/* partial_inplace */
	 0x00000000,		/* src_mask */
	 0x000003f0,		/* dst_mask */
	 false),		/* pcrel_offset */
  HOWTO (R_VOLT32_G5_JIMM4,	/* type */
	 0,			/* rightshift */
	 1,			/* size */
	 4,			/* bitsize */
	 false,			/* pc_relative */
	 0,			/* bitpos */
	 complain_overflow_unsigned, /* complain_on_overflow */
	 bfd_elf_generic_reloc,	/* special_function */
	 "R_VOLT32_G5_JIMM4",	/* name */
	 false,			/* partial_inplace */
	 0x00000000,		/* src_mask */
	 0x0000000f,		/* dst_mask */
	 false),		/* pcrel_offset */
/* -------- */
  HOWTO (R_VOLT32_G6_IIMM5,	/* type */
	 0,			/* rightshift */
	 1,			/* size */
	 5,			/* bitsize */
	 false,			/* pc_relative */
	 10,			/* bitpos */
	 complain_overflow_unsigned, /* complain_on_overflow */
	 bfd_elf_generic_reloc,	/* special_function */
	 "R_VOLT32_G6_IIMM5",	/* name */
	 false,			/* partial_inplace */
	 0x00000000,		/* src_mask */
	 0x00007c00,		/* dst_mask */
	 false),		/* pcrel_offset */

  HOWTO (R_VOLT32_G6_JIMM5,	/* type */
	 0,			/* rightshift */
	 1,			/* size */
	 5,			/* bitsize */
	 false,			/* pc_relative */
	 5,			/* bitpos */
	 complain_overflow_unsigned, /* complain_on_overflow */
	 bfd_elf_generic_reloc,	/* special_function */
	 "R_VOLT32_G6_JIMM5",	/* name */
	 false,			/* partial_inplace */
	 0x00000000,		/* src_mask */
	 0x000003e0,		/* dst_mask */
	 false),		/* pcrel_offset */
/* -------- */
  HOWTO (R_VOLT32_G7_IIMM6,	/* type */
	 0,			/* rightshift */
	 1,			/* size */
	 6,			/* bitsize */
	 false,			/* pc_relative */
	 4,			/* bitpos */
	 complain_overflow_unsigned, /* complain_on_overflow */
	 bfd_elf_generic_reloc,	/* special_function */
	 "R_VOLT32_G7_IIMM6",	/* name */
	 false,			/* partial_inplace */
	 0x00000000,		/* src_mask */
	 0x000003f0,		/* dst_mask */
	 false),		/* pcrel_offset */
/* -------- */
};
