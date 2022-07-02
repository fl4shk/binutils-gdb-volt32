/* BFD support for the volt32 processor.
   Copyright (C) 2009-2022 Free Software Foundation, Inc.

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

#include "sysdep.h"
#include "bfd.h"
#include "libbfd.h"

const bfd_arch_info_type bfd_volt32_arch =
{
  32,				/* Bits in a word.  */
  32,				/* Bits in an address.  */
  8,				/* Bits in a byte.  */
  bfd_arch_volt32,		/* Architecture Number.  */
  bfd_mach_volt32,		/* Machine number.  */
  "volt32",			/* Arch name.  */
  "volt32",			/* Printable name.  */
  2,				/* Section alignment power.  */
  true,				/* The one and only.  */
  bfd_default_compatible,	/* `compatible` function */
  bfd_default_scan,		/* `scan` function */
  bfd_arch_default_fill,	/* `fill` function */
  NULL,				/* `next` */
  0				/* Maximum offset of a reloc from the start of an insn.  */
};
