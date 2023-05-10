# MIPS32 DSP ASE test
# mach:  mips32r2 mips64r2
#as:		-mdsp
#ld:		-N -Ttext=0x80010000
#output:	*\\npass\\n

# Copyright (C) 2005-2023 Free Software Foundation, Inc.
# Contributed by MIPS Technologies, Inc.  Written by Chao-ying Fu.
#
# This file is part of the GNU simulators.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

	.include "testutils.inc"
	.include "utils-dsp.inc"

	setup

	.set noreorder

	.ent DIAG
DIAG:

	writemsg "[1] Test addq.ph"
	dspck_dstio addq.ph, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_dstio addq.ph, 0x20002, 0x10001, 0x10001, 0x0, 0x0
	dspck_dstio addq.ph, 0xfffefffe, 0xffffffff, 0xffffffff, 0x0, 0x0
	dspck_dstio addq.ph, 0xffff0000, 0xffffffff, 0x1, 0x0, 0x0
	dspck_dstio addq.ph, 0x0, 0xffffffff, 0x10001, 0x0, 0x0

	writemsg "[2] Test addq_s.ph"
	dspck_dstio addq_s.ph, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_dstio addq_s.ph, 0x20002, 0x10001, 0x10001, 0x0, 0x0
	dspck_dstio addq_s.ph, 0xfffefffe, 0xffffffff, 0xffffffff, 0x0, 0x0
	dspck_dstio addq_s.ph, 0xffff0000, 0xffffffff, 0x1, 0x0, 0x0
	dspck_dstio addq_s.ph, 0xffff0000, 0x1, 0xffffffff, 0x0, 0x0

	writemsg "[3] Test addq_s.w"
	dspck_dsti addq_s.w, 0x0, 0x0, 0x0, 0x0
	dspck_dstio addq_s.w, 0x2, 0x1, 0x1, 0x0, 0x0
	dspck_dstio addq_s.w, 0xfffffffe, 0xffffffff, 0xffffffff, 0x0, 0x0
	dspck_dstio addq_s.w, 0x0, 0xffffffff, 0x1, 0x0, 0x0
	dspck_dstio addq_s.w, 0xffff, 0xffffffff, 0x10000, 0x0, 0x0

	writemsg "[4] Test addu.qb"
	dspck_dstio addu.qb, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_dstio addu.qb, 0x2040000, 0x102ff01, 0x10201ff, 0x0, 0x100000
	dspck_dstio addu.qb, 0xfe0001fe, 0x7f80ffff, 0x7f8002ff, 0x0, 0x100000
	dspck_dstio addu.qb, 0xffffffff, 0x10203, 0xfffefdfc, 0x0, 0x0
	dspck_dstio addu.qb, 0xffffffff, 0xfbfaf9f8, 0x4050607, 0x0, 0x0

	writemsg "[5] Test addu_s.qb"
	dspck_dstio addu_s.qb, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_dstio addu_s.qb, 0x204ffff, 0x102ff01, 0x10201ff, 0x0, 0x100000
	dspck_dstio addu_s.qb, 0xfeffffff, 0x7f80ffff, 0x7f8002ff, 0x0, 0x100000
	dspck_dstio addu_s.qb, 0xffffffff, 0x10203, 0xfffefdfc, 0x0, 0x0
	dspck_dstio addu_s.qb, 0xffffffff, 0xfbfaf9f8, 0x4050607, 0x0, 0x0

	writemsg "[6] Test subq.ph"
	dspck_dstio subq.ph, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_dstio subq.ph, 0x10001, 0x20002, 0x10001, 0x0, 0x0
	dspck_dstio subq.ph, 0x1ffff, 0x2fffe, 0x1ffff, 0x0, 0x0
	dspck_dstio subq.ph, 0x7fff0000, 0xfffe8000, 0x7fff8000, 0x0, 0x100000
	dspck_dstio subq.ph, 0x1ffff, 0x7fff8000, 0x7ffe8001, 0x0, 0x0

	writemsg "[7] Test subq_s.ph"
	dspck_dstio subq_s.ph, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_dstio subq_s.ph, 0x10001, 0x20002, 0x10001, 0x0, 0x0
	dspck_dstio subq_s.ph, 0x1ffff, 0x2fffe, 0x1ffff, 0x0, 0x0
	dspck_dstio subq_s.ph, 0x0, 0x7fff8000, 0x7fff8000, 0x0, 0x0
	dspck_dstio subq_s.ph, 0x1ffff, 0x7fff8000, 0x7ffe8001, 0x0, 0x0

	writemsg "[8] Test subq_s.w"
	dspck_dsti subq_s.w, 0x0, 0x0, 0x0, 0x0
	dspck_dsti subq_s.w, 0x0, 0x7fffffff, 0x7fffffff, 0x0
	dspck_dstio subq_s.w, 0x7fffffff, 0x0, 0x80000000, 0x0, 0x100000
	dspck_dstio subq_s.w, 0x1, 0x2, 0x1, 0x0, 0x0
	dspck_dstio subq_s.w, 0xffffffff, 0xfffffffe, 0xffffffff, 0x0, 0x0

	writemsg "[9] Test subu.qb"
	dspck_dstio subu.qb, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_dstio subu.qb, 0x4030201, 0x8060402, 0x4030201, 0x0, 0x0
	dspck_dstio subu.qb, 0xfcfdfeff, 0x4030201, 0x8060402, 0x0, 0x100000
	dspck_dstio subu.qb, 0x102ff01, 0x2040000, 0x10201ff, 0x0, 0x100000
	dspck_dstio subu.qb, 0x7f80ffff, 0xfe0001fe, 0x7f8002ff, 0x0, 0x100000

	writemsg "[10] Test subu_s.qb"
	dspck_dstio subu_s.qb, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_dstio subu_s.qb, 0x4030201, 0x8060402, 0x4030201, 0x0, 0x0
	dspck_dstio subu_s.qb, 0x0, 0x4030201, 0x8060402, 0x0, 0x100000
	dspck_dstio subu_s.qb, 0x1020000, 0x2040000, 0x10201ff, 0x0, 0x100000
	dspck_dstio subu_s.qb, 0x7f000000, 0xfe0001fe, 0x7f8002ff, 0x0, 0x100000

	writemsg "[11] Test addsc"
	dspck_dstio addsc, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_dstio addsc, 0x1000000, 0x84000000, 0x7d000000, 0x0, 0x2000
	dspck_dstio addsc, 0xf1000000, 0x74000000, 0x7d000000, 0x0, 0x0
	dspck_dstio addsc, 0x2, 0x1, 0x1, 0x0, 0x0
	dspck_dstio addsc, 0xffffffff, 0xfffffffe, 0x1, 0x0, 0x0

	writemsg "[12] Test addwc"
	dspck_dstio addwc, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_dstio addwc, 0x2, 0x1, 0x1, 0x0, 0x0
	dspck_dstio addwc, 0x3, 0x1, 0x1, 0x2000, 0x2000
	dspck_dsti addwc, 0x1, 0xffffffff, 0x1, 0x2000
	dspck_dsti addwc, 0x11, 0xa, 0x6, 0x2000

	writemsg "[13] Test modsub"
	dspck_dstio modsub, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_dstio modsub, 0x76, 0x78, 0x7802, 0x0, 0x0
	dspck_dstio modsub, 0x74, 0x76, 0x7802, 0x0, 0x0
	dspck_dstio modsub, 0x78, 0x0, 0x7802, 0x0, 0x0
	dspck_dstio modsub, 0xf9, 0xfc, 0xfe03, 0x0, 0x0

	writemsg "[14] Test raddu.w.qb"
	dspck_dsio raddu.w.qb, 0x0, 0x0, 0x0, 0x0
	dspck_dsio raddu.w.qb, 0x2, 0x1000100, 0x0, 0x0
	dspck_dsio raddu.w.qb, 0x4, 0x1010101, 0x0, 0x0
	dspck_dsio raddu.w.qb, 0x200, 0xff01ff01, 0x0, 0x0
	dspck_dsio raddu.w.qb, 0x3fc, 0xffffffff, 0x0, 0x0

	writemsg "[15] Test absq_s.ph"
	dspck_dsio absq_s.ph, 0x0, 0x0, 0x0, 0x0
	dspck_dsio absq_s.ph, 0x10001, 0xffffffff, 0x0, 0x0
	dspck_dsio absq_s.ph, 0x7fff7fff, 0x80008000, 0x0, 0x100000
	dspck_dsio absq_s.ph, 0x60000002, 0xa000fffe, 0x0, 0x0
	dspck_dsio absq_s.ph, 0x70000004, 0x9000fffc, 0x0, 0x0

	writemsg "[16] Test absq_s.w"
	dspck_dsio absq_s.w, 0x0, 0x0, 0x0, 0x0
	dspck_dsio absq_s.w, 0x1, 0xffffffff, 0x0, 0x0
	dspck_dsio absq_s.w, 0x7fffffff, 0x80000000, 0x0, 0x100000
	dspck_dsio absq_s.w, 0x40000001, 0xbfffffff, 0x0, 0x0
	dspck_dsio absq_s.w, 0x8000001, 0xf7ffffff, 0x0, 0x0

	writemsg "[17] Test precrq.qb.ph"
	dspck_dstio precrq.qb.ph, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_dstio precrq.qb.ph, 0xff7f4020, 0xffff7fff, 0x40002000, 0x0, 0x0
	dspck_dstio precrq.qb.ph, 0xfeba7632, 0xfedcba98, 0x76543210, 0x0, 0x0
	dspck_dstio precrq.qb.ph, 0x7632feba, 0x76543210, 0xfedcba98, 0x0, 0x0
	dspck_dstio precrq.qb.ph, 0x14589cd, 0x1234567, 0x89abcdef, 0x0, 0x0

	writemsg "[18] Test precrq.ph.w"
	dspck_dstio precrq.ph.w, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_dstio precrq.ph.w, 0xffff4000, 0xffff7fff, 0x40002000, 0x0, 0x0
	dspck_dstio precrq.ph.w, 0xfedc7654, 0xfedcba98, 0x76543210, 0x0, 0x0
	dspck_dstio precrq.ph.w, 0x7654fedc, 0x76543210, 0xfedcba98, 0x0, 0x0
	dspck_dstio precrq.ph.w, 0x12389ab, 0x1234567, 0x89abcdef, 0x0, 0x0

	writemsg "[19] Test precrq_rs.ph.w"
	dspck_dstio precrq_rs.ph.w, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_dstio precrq_rs.ph.w, 0x7fff0000, 0x7fffffff, 0xffffffff, 0x0, 0x400000
	dspck_dstio precrq_rs.ph.w, 0x80008001, 0x80007fff, 0x8000ffff, 0x0, 0x0
	dspck_dstio precrq_rs.ph.w, 0xfedd7654, 0xfedcba98, 0x76543210, 0x0, 0x0
	dspck_dstio precrq_rs.ph.w, 0x7654fedd, 0x76543210, 0xfedcba98, 0x0, 0x0

	writemsg "[20] Test precrqu_s.qb.ph"
	dspck_dstio precrqu_s.qb.ph, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_dstio precrqu_s.qb.ph, 0xff8040, 0xffff7fff, 0x40002000, 0x0, 0x400000
	dspck_dstio precrqu_s.qb.ph, 0xec64, 0xfedcba98, 0x76543210, 0x0, 0x400000
	dspck_dstio precrqu_s.qb.ph, 0xec640000, 0x76543210, 0xfedcba98, 0x0, 0x400000
	dspck_dstio precrqu_s.qb.ph, 0x28a0000, 0x1234567, 0x89abcdef, 0x0, 0x400000

	writemsg "[21] Test preceq.w.phl"
	dspck_dsio preceq.w.phl, 0x0, 0x0, 0x0, 0x0
	dspck_dsio preceq.w.phl, 0xffff0000, 0xffffffff, 0x0, 0x0
	dspck_dsio preceq.w.phl, 0x80000000, 0x80004000, 0x0, 0x0
	dspck_dsio preceq.w.phl, 0xc0010000, 0xc0012001, 0x0, 0x0
	dspck_dsio preceq.w.phl, 0x76540000, 0x76543210, 0x0, 0x0

	writemsg "[22] Test preceq.w.phr"
	dspck_dsio preceq.w.phr, 0x0, 0x0, 0x0, 0x0
	dspck_dsio preceq.w.phr, 0xffff0000, 0xffffffff, 0x0, 0x0
	dspck_dsio preceq.w.phr, 0x40000000, 0x80004000, 0x0, 0x0
	dspck_dsio preceq.w.phr, 0x20010000, 0xc0012001, 0x0, 0x0
	dspck_dsio preceq.w.phr, 0x32100000, 0x76543210, 0x0, 0x0

	writemsg "[23] Test precequ.ph.qbl"
	dspck_dsio precequ.ph.qbl, 0x0, 0x0, 0x0, 0x0
	dspck_dsio precequ.ph.qbl, 0x7f807f80, 0xffffffff, 0x0, 0x0
	dspck_dsio precequ.ph.qbl, 0x40000000, 0x80004000, 0x0, 0x0
	dspck_dsio precequ.ph.qbl, 0x60000080, 0xc0012001, 0x0, 0x0
	dspck_dsio precequ.ph.qbl, 0x3b002a00, 0x76543210, 0x0, 0x0

	writemsg "[24] Test precequ.ph.qbr"
	dspck_dsio precequ.ph.qbr, 0x0, 0x0, 0x0, 0x0
	dspck_dsio precequ.ph.qbr, 0x7f807f80, 0xffffffff, 0x0, 0x0
	dspck_dsio precequ.ph.qbr, 0x20000000, 0x80004000, 0x0, 0x0
	dspck_dsio precequ.ph.qbr, 0x10000080, 0xc0012001, 0x0, 0x0
	dspck_dsio precequ.ph.qbr, 0x19000800, 0x76543210, 0x0, 0x0

	writemsg "[25] Test precequ.ph.qbla"
	dspck_dsio precequ.ph.qbla, 0x0, 0x0, 0x0, 0x0
	dspck_dsio precequ.ph.qbla, 0x7f807f80, 0xffffffff, 0x0, 0x0
	dspck_dsio precequ.ph.qbla, 0x40002000, 0x80004000, 0x0, 0x0
	dspck_dsio precequ.ph.qbla, 0x60001000, 0xc0012001, 0x0, 0x0
	dspck_dsio precequ.ph.qbla, 0x3b001900, 0x76543210, 0x0, 0x0

	writemsg "[26] Test precequ.ph.qbra"
	dspck_dsio precequ.ph.qbra, 0x0, 0x0, 0x0, 0x0
	dspck_dsio precequ.ph.qbra, 0x7f807f80, 0xffffffff, 0x0, 0x0
	dspck_dsio precequ.ph.qbra, 0x0, 0x80004000, 0x0, 0x0
	dspck_dsio precequ.ph.qbra, 0x800080, 0xc0012001, 0x0, 0x0
	dspck_dsio precequ.ph.qbra, 0x2a000800, 0x76543210, 0x0, 0x0

	writemsg "[27] Test preceu.ph.qbl"
	dspck_dsio preceu.ph.qbl, 0x0, 0x0, 0x0, 0x0
	dspck_dsio preceu.ph.qbl, 0xff00ff, 0xffffffff, 0x0, 0x0
	dspck_dsio preceu.ph.qbl, 0x800000, 0x80004000, 0x0, 0x0
	dspck_dsio preceu.ph.qbl, 0xc00001, 0xc0012001, 0x0, 0x0
	dspck_dsio preceu.ph.qbl, 0x760054, 0x76543210, 0x0, 0x0

	writemsg "[28] Test preceu.ph.qbr"
	dspck_dsio preceu.ph.qbr, 0x0, 0x0, 0x0, 0x0
	dspck_dsio preceu.ph.qbr, 0xff00ff, 0xffffffff, 0x0, 0x0
	dspck_dsio preceu.ph.qbr, 0x400000, 0x80004000, 0x0, 0x0
	dspck_dsio preceu.ph.qbr, 0x200001, 0xc0012001, 0x0, 0x0
	dspck_dsio preceu.ph.qbr, 0x320010, 0x76543210, 0x0, 0x0

	writemsg "[29] Test preceu.ph.qbla"
	dspck_dsio preceu.ph.qbla, 0x0, 0x0, 0x0, 0x0
	dspck_dsio preceu.ph.qbla, 0xff00ff, 0xffffffff, 0x0, 0x0
	dspck_dsio preceu.ph.qbla, 0x800040, 0x80004000, 0x0, 0x0
	dspck_dsio preceu.ph.qbla, 0xc00020, 0xc0012001, 0x0, 0x0
	dspck_dsio preceu.ph.qbla, 0x760032, 0x76543210, 0x0, 0x0

	writemsg "[30] Test preceu.ph.qbra"
	dspck_dsio preceu.ph.qbra, 0x0, 0x0, 0x0, 0x0
	dspck_dsio preceu.ph.qbra, 0xff00ff, 0xffffffff, 0x0, 0x0
	dspck_dsio preceu.ph.qbra, 0x0, 0x80004000, 0x0, 0x0
	dspck_dsio preceu.ph.qbra, 0x10001, 0xc0012001, 0x0, 0x0
	dspck_dsio preceu.ph.qbra, 0x540010, 0x76543210, 0x0, 0x0

	writemsg "[31] Test shll.qb"
	dspck_dtsaio shll.qb, 0x0, 0x0, 0, 0x0, 0x0
	dspck_dtsai shll.qb, 0x202fefe, 0x101ffff, 1, 0x0
	dspck_dtsai shll.qb, 0xfefe0002, 0x7fff8081, 1, 0x0
	dspck_dtsai shll.qb, 0xfcfc0020, 0x7fff8008, 2, 0x0
	dspck_dtsai shll.qb, 0x68b0d868, 0x6db6db6d, 3, 0x0

	writemsg "[32] Test shllv.qb"
	dspck_dstio shllv.qb, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_dsti shllv.qb, 0x202fefe, 0x101ffff, 0x1, 0x0
	dspck_dsti shllv.qb, 0xfefe0002, 0x7fff8081, 0x1, 0x0
	dspck_dsti shllv.qb, 0xfcfc0020, 0x7fff8008, 0x2, 0x0
	dspck_dsti shllv.qb, 0x68b0d868, 0x6db6db6d, 0x3, 0x0

	writemsg "[33] Test shll.ph"
	dspck_dtsaio shll.ph, 0x0, 0x0, 0, 0x0, 0x0
	dspck_dtsaio shll.ph, 0x2fffe, 0x1ffff, 1, 0x0, 0x0
	dspck_dtsaio shll.ph, 0xfffe0000, 0x7fff8000, 1, 0x0, 0x400000
	dspck_dtsaio shll.ph, 0xfffc0020, 0x7fff8008, 2, 0x0, 0x400000
	dspck_dtsaio shll.ph, 0x6db0db68, 0x6db6db6d, 3, 0x0, 0x400000

	writemsg "[34] Test shllv.ph"
	dspck_dstio shllv.ph, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_dstio shllv.ph, 0x2fffe, 0x1ffff, 0x1, 0x0, 0x0
	dspck_dstio shllv.ph, 0xfffe0000, 0x7fff8000, 0x1, 0x0, 0x400000
	dspck_dstio shllv.ph, 0xfffc0020, 0x7fff8008, 0x2, 0x0, 0x400000
	dspck_dstio shllv.ph, 0x6db0db68, 0x6db6db6d, 0x3, 0x0, 0x400000

	writemsg "[35] Test shll_s.ph"
	dspck_dtsaio shll_s.ph, 0x0, 0x0, 0, 0x0, 0x0
	dspck_dtsaio shll_s.ph, 0x2fffe, 0x1ffff, 1, 0x0, 0x0
	dspck_dtsaio shll_s.ph, 0x7fff8000, 0x7fff8000, 1, 0x0, 0x400000
	dspck_dtsaio shll_s.ph, 0x7fff8000, 0x7fff8008, 2, 0x0, 0x400000
	dspck_dtsaio shll_s.ph, 0x7fff8000, 0x6db6db6d, 3, 0x0, 0x400000

	writemsg "[36] Test shllv_s.ph"
	dspck_dstio shllv_s.ph, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_dstio shllv_s.ph, 0x2fffe, 0x1ffff, 0x1, 0x0, 0x0
	dspck_dstio shllv_s.ph, 0x7fff8000, 0x7fff8000, 0x1, 0x0, 0x400000
	dspck_dstio shllv_s.ph, 0x7fff8000, 0x7fff8008, 0x2, 0x0, 0x400000
	dspck_dstio shllv_s.ph, 0x7fff8000, 0x6db6db6d, 0x3, 0x0, 0x400000

	writemsg "[37] Test shll_s.w"
	dspck_dtsaio shll_s.w, 0x0, 0x0, 0, 0x0, 0x0
	dspck_dtsaio shll_s.w, 0x3fffe, 0x1ffff, 1, 0x0, 0x0
	dspck_dtsaio shll_s.w, 0x7fffffff, 0x7fff8000, 1, 0x0, 0x400000
	dspck_dtsaio shll_s.w, 0x80000000, 0x80000000, 1, 0x0, 0x400000
	dspck_dtsaio shll_s.w, 0x7fffffff, 0x7fff8008, 2, 0x0, 0x400000

	writemsg "[38] Test shllv_s.w"
	dspck_dstio shllv_s.w, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_dstio shllv_s.w, 0x3fffe, 0x1ffff, 0x1, 0x0, 0x0
	dspck_dstio shllv_s.w, 0x7fffffff, 0x7fff8000, 0x1, 0x0, 0x400000
	dspck_dstio shllv_s.w, 0x80000000, 0x80000000, 0x1, 0x0, 0x400000
	dspck_dstio shllv_s.w, 0x7fffffff, 0x7fff8008, 0x2, 0x0, 0x400000

	writemsg "[39] Test shrl.qb"
	dspck_dtsaio shrl.qb, 0x0, 0x0, 0, 0x0, 0x0
	dspck_dtsai shrl.qb, 0x7f7f, 0x101ffff, 1, 0x0
	dspck_dtsai shrl.qb, 0x3f7f4040, 0x7fff8081, 1, 0x0
	dspck_dtsai shrl.qb, 0x1f3f2002, 0x7fff8008, 2, 0x0
	dspck_dtsai shrl.qb, 0xd161b0d, 0x6db6db6d, 3, 0x0

	writemsg "[40] Test shrlv.qb"
	dspck_dstio shrlv.qb, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_dsti shrlv.qb, 0x7f7f, 0x101ffff, 0x1, 0x0
	dspck_dsti shrlv.qb, 0x3f7f4040, 0x7fff8081, 0x1, 0x0
	dspck_dsti shrlv.qb, 0x1f3f2002, 0x7fff8008, 0x2, 0x0
	dspck_dsti shrlv.qb, 0xd161b0d, 0x6db6db6d, 0x3, 0x0

	writemsg "[41] Test shra.ph"
	dspck_dtsaio shra.ph, 0x10001, 0x20002, 1, 0x0, 0x0
	dspck_dtsaio shra.ph, 0x10006, 0x10106f6f, 12, 0x0, 0x0
	dspck_dtsaio shra.ph, 0x1c000, 0x28000, 1, 0x0, 0x0
	dspck_dtsaio shra.ph, 0x2f800, 0x208000, 4, 0x0, 0x0
	dspck_dtsaio shra.ph, 0xfc01fc00, 0x80208000, 5, 0x0, 0x0

	writemsg "[42] Test shrav.ph"
	dspck_dstio shrav.ph, 0x10001, 0x20002, 0x1, 0x0, 0x0
	dspck_dstio shrav.ph, 0x10006, 0x10106f6f, 0xc, 0x0, 0x0
	dspck_dstio shrav.ph, 0x1c000, 0x28000, 0x1, 0x0, 0x0
	dspck_dstio shrav.ph, 0x2f800, 0x208000, 0x4, 0x0, 0x0
	dspck_dstio shrav.ph, 0xfc01fc00, 0x80208000, 0x5, 0x0, 0x0

	writemsg "[43] Test shra_r.ph"
	dspck_dtsaio shra_r.ph, 0x20001, 0x30002, 1, 0x0, 0x0
	dspck_dtsaio shra_r.ph, 0x10001, 0x20001, 1, 0x0, 0x0
	dspck_dtsaio shra_r.ph, 0x10001, 0x10001, 1, 0x0, 0x0
	dspck_dtsaio shra_r.ph, 0x0, 0x10001, 2, 0x0, 0x0
	dspck_dtsaio shra_r.ph, 0x7fff8000, 0x7fff8000, 0, 0x0, 0x0
	dspck_dtsaio shra_r.ph, 0x4000c000, 0x7fff8000, 1, 0x0, 0x0
	dspck_dtsaio shra_r.ph, 0x2000e000, 0x7ffe8000, 2, 0x0, 0x0

	writemsg "[44] Test shrav_r.ph"
	dspck_dstio shrav_r.ph, 0x20001, 0x30002, 0x1, 0x0, 0x0
	dspck_dstio shrav_r.ph, 0x10001, 0x20001, 0x1, 0x0, 0x0
	dspck_dstio shrav_r.ph, 0x10001, 0x10001, 0x1, 0x0, 0x0
	dspck_dstio shrav_r.ph, 0x0, 0x10001, 0x2, 0x0, 0x0
	dspck_dstio shrav_r.ph, 0x7fff8000, 0x7fff8000, 0, 0x0, 0x0
	dspck_dstio shrav_r.ph, 0x2000e000, 0x7fff8000, 2, 0x0, 0x0

	writemsg "[45] Test shra_r.w"
	dspck_dtsaio shra_r.w, 0x1, 0x2, 1, 0x0, 0x0
	dspck_dtsaio shra_r.w, 0xffff8000, 0x80000000, 16, 0x0, 0x0
	dspck_dtsaio shra_r.w, 0x8001, 0x10001, 1, 0x0, 0x0
	dspck_dtsaio shra_r.w, 0x1, 0x10001, 17, 0x0, 0x0
	dspck_dtsaio shra_r.w, 0xffffc001, 0x80010001, 17, 0x0, 0x0
	dspck_dtsaio shra_r.w, 0x7fffffff, 0x7fffffff, 0, 0x0, 0x0
	dspck_dtsaio shra_r.w, 0x40000000, 0x7fffffff, 1, 0x0, 0x0
	dspck_dtsaio shra_r.w, 0x20000000, 0x7ffffffe, 2, 0x0, 0x0

	writemsg "[46] Test shrav_r.w"
	dspck_dstio shrav_r.w, 0x1, 0x2, 0x1, 0x0, 0x0
	dspck_dstio shrav_r.w, 0xffff8000, 0x80000000, 0x10, 0x0, 0x0
	dspck_dstio shrav_r.w, 0x8001, 0x10001, 0x1, 0x0, 0x0
	dspck_dstio shrav_r.w, 0x8001, 0x10001, 0x21, 0x0, 0x0
	dspck_dstio shrav_r.w, 0x4000, 0x10001, 0x2, 0x0, 0x0
	dspck_dstio shrav_r.w, 0x7fffffff, 0x7fffffff, 0x0, 0x0, 0x0
	dspck_dstio shrav_r.w, 0x10000000, 0x7ffffffc, 0x3, 0x0, 0x0
	dspck_dstio shrav_r.w, 0x08000000, 0x7ffffff8, 0x4, 0x0, 0x0

	writemsg "[47] Test muleu_s.ph.qbl"
	dspck_dstio muleu_s.ph.qbl, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_dstio muleu_s.ph.qbl, 0x0, 0x0, 0x40004000, 0x0, 0x0
	dspck_dstio muleu_s.ph.qbl, 0x0, 0xffffffff, 0x0, 0x0, 0x0
	dspck_dstio muleu_s.ph.qbl, 0x10001, 0x1010101, 0x10001, 0x0, 0x0
	dspck_dstio muleu_s.ph.qbl, 0x10000, 0x1000001, 0x10001, 0x0, 0x0

	writemsg "[48] Test muleu_s.ph.qbr"
	dspck_dstio muleu_s.ph.qbr, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_dstio muleu_s.ph.qbr, 0x0, 0x0, 0x40004000, 0x0, 0x0
	dspck_dstio muleu_s.ph.qbr, 0x0, 0xffffffff, 0x0, 0x0, 0x0
	dspck_dstio muleu_s.ph.qbr, 0x10001, 0x1010101, 0x10001, 0x0, 0x0
	dspck_dstio muleu_s.ph.qbr, 0x1, 0x1000001, 0x10001, 0x0, 0x0

	writemsg "[49] Test mulq_rs.ph"
	dspck_dstio mulq_rs.ph, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_dstio mulq_rs.ph, 0x0, 0x1, 0x1, 0x0, 0x0
	dspck_dstio mulq_rs.ph, 0x20000000, 0x40007fff, 0x40000000, 0x0, 0x0
	dspck_dstio mulq_rs.ph, 0x33330000, 0x66660000, 0x40007fff, 0x0, 0x0
	dspck_dstio mulq_rs.ph, 0xccd3332, 0x66666666, 0x10003fff, 0x0, 0x0

	writemsg "[50] Test muleq_s.w.phl"
	dspck_dstio muleq_s.w.phl, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_dstio muleq_s.w.phl, 0x0, 0x0, 0x40004000, 0x0, 0x0
	dspck_dstio muleq_s.w.phl, 0x0, 0x7fff7fff, 0x0, 0x0, 0x0
	dspck_dstio muleq_s.w.phl, 0x0, 0x0, 0xc000c000, 0x0, 0x0
	dspck_dstio muleq_s.w.phl, 0x0, 0x80008000, 0x0, 0x0, 0x0

	writemsg "[51] Test muleq_s.w.phr"
	dspck_dstio muleq_s.w.phr, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_dstio muleq_s.w.phr, 0x0, 0x0, 0x40004000, 0x0, 0x0
	dspck_dstio muleq_s.w.phr, 0x0, 0x7fff7fff, 0x0, 0x0, 0x0
	dspck_dstio muleq_s.w.phr, 0x0, 0x0, 0xc000c000, 0x0, 0x0
	dspck_dstio muleq_s.w.phr, 0x0, 0x80008000, 0x0, 0x0, 0x0

	writemsg "[52] Test dpau.h.qbl"
	dspck_astio dpau.h.qbl, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_astio dpau.h.qbl, 0x0, 0x0, 0x0, 0x1, 0x1010101, 0x1000001, 0x0, 0x0
	dspck_astio dpau.h.qbl, 0xffffffff, 0xffffffff, 0x0, 0x0, 0x1010101, 0x1000001, 0x0, 0x0
	dspck_astio dpau.h.qbl, 0x0, 0x0, 0x0, 0x0, 0xffff0000, 0xffff, 0x0, 0x0
	dspck_astio dpau.h.qbl, 0x0, 0x0, 0x0, 0xff, 0xffff0001, 0x1ffff, 0x0, 0x0

	writemsg "[53] Test dpau.h.qbr"
	dspck_astio dpau.h.qbr, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_astio dpau.h.qbr, 0x0, 0x0, 0x0, 0x1, 0x1010101, 0x1000001, 0x0, 0x0
	dspck_astio dpau.h.qbr, 0xffffffff, 0xffffffff, 0x0, 0x0, 0x1010101, 0x1000001, 0x0, 0x0
	dspck_astio dpau.h.qbr, 0x0, 0x0, 0x0, 0x0, 0xffff0000, 0xffff, 0x0, 0x0
	dspck_astio dpau.h.qbr, 0x0, 0x0, 0x0, 0xff, 0xffff0001, 0x1ffff, 0x0, 0x0

	writemsg "[54] Test dpsu.h.qbl"
	dspck_astio dpsu.h.qbl, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_astio dpsu.h.qbl, 0x0, 0x1, 0x0, 0x0, 0x1010101, 0x1000001, 0x0, 0x0
	dspck_astio dpsu.h.qbl, 0x0, 0x0, 0xffffffff, 0xffffffff, 0x1010101, 0x1000001, 0x0, 0x0
	dspck_astio dpsu.h.qbl, 0x0, 0x0, 0x0, 0x0, 0xffff0000, 0xffff, 0x0, 0x0
	dspck_astio dpsu.h.qbl, 0x0, 0xff, 0x0, 0x0, 0xffff0001, 0x1ffff, 0x0, 0x0

	writemsg "[55] Test dpsu.h.qbr"
	dspck_astio dpsu.h.qbr, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_astio dpsu.h.qbr, 0x0, 0x1, 0x0, 0x0, 0x1010101, 0x1000001, 0x0, 0x0
	dspck_astio dpsu.h.qbr, 0x0, 0x0, 0xffffffff, 0xffffffff, 0x1010101, 0x1000001, 0x0, 0x0
	dspck_astio dpsu.h.qbr, 0x0, 0x0, 0x0, 0x0, 0xffff0000, 0xffff, 0x0, 0x0
	dspck_astio dpsu.h.qbr, 0x0, 0xff, 0x0, 0x0, 0xffff0001, 0x1ffff, 0x0, 0x0

	writemsg "[56] Test dpaq_s.w.ph"
	dspck_astio dpaq_s.w.ph, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_astio dpaq_s.w.ph, 0x0, 0x0, 0x0, 0xfffc0004, 0x7fff7fff, 0x7fff7fff, 0x0, 0x0
	dspck_astio dpaq_s.w.ph, 0x0, 0x0, 0x0, 0xfffffffe, 0x80008000, 0x80008000, 0x0, 0xf0000
	dspck_astio dpaq_s.w.ph, 0x0, 0x0, 0xffffffff, 0xa0000000, 0x40002000, 0x80008000, 0x0, 0x0
	dspck_astio dpaq_s.w.ph, 0xffffffff, 0xa0000000, 0xffffffff, 0x88000000, 0x10000800, 0x80008000, 0x0, 0x0

	writemsg "[57] Test dpsq_s.w.ph"
	dspck_astio dpsq_s.w.ph, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_astio dpsq_s.w.ph, 0x0, 0xfffc0004, 0x0, 0x0, 0x7fff7fff, 0x7fff7fff, 0x0, 0x0
	dspck_astio dpsq_s.w.ph, 0x0, 0xfffffffe, 0x0, 0x0, 0x80008000, 0x80008000, 0x0, 0xf0000
	dspck_astio dpsq_s.w.ph, 0xffffffff, 0xa0000000, 0x0, 0x0, 0x40002000, 0x80008000, 0x0, 0x0
	dspck_astio dpsq_s.w.ph, 0xffffffff, 0x88000000, 0xffffffff, 0xa0000000, 0x10000800, 0x80008000, 0x0, 0x0

	writemsg "[58] Test mulsaq_s.w.ph"
	dspck_astio mulsaq_s.w.ph, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_astio mulsaq_s.w.ph, 0x0, 0x0, 0x0, 0x0, 0x4000, 0xc0000000, 0x0, 0x0
	dspck_astio mulsaq_s.w.ph, 0x0, 0x0, 0xffffffff, 0x60010000, 0x80004000, 0x7fff4000, 0x0, 0x0
	dspck_astio mulsaq_s.w.ph, 0x0, 0x0, 0x0, 0x5fffffff, 0x80004000, 0x80004000, 0x0, 0xf0000
	dspck_astio mulsaq_s.w.ph, 0x7fffffff, 0xffffffff, 0x80000000, 0xfffc0003, 0x7fff8001, 0x7fff7fff, 0x0, 0x0

	writemsg "[59] Test dpaq_sa.l.w"
	dspck_astio dpaq_sa.l.w, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_astio dpaq_sa.l.w, 0x0, 0x0, 0x7ffffffe, 0x2, 0x7fffffff, 0x7fffffff, 0x0, 0x0
	dspck_astio dpaq_sa.l.w, 0x0, 0x0, 0x7fffffff, 0xffffffff, 0x80000000, 0x80000000, 0x0, 0xf0000
	dspck_astio dpaq_sa.l.w, 0x0, 0x0, 0xc0000000, 0x80000000, 0xc0000000, 0x7fffffff, 0x0, 0x0
	dspck_astio dpaq_sa.l.w, 0x20000000, 0x0, 0x0, 0x40000000, 0xe0000000, 0x7fffffff, 0x0, 0x0

	writemsg "[60] Test dpsq_sa.l.w"
	dspck_astio dpsq_sa.l.w, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_astio dpsq_sa.l.w, 0x7fffffff, 0xffffffff, 0x0, 0x0, 0x80000000, 0x80000000, 0x0, 0xf0000
	dspck_astio dpsq_sa.l.w, 0x80000000, 0x0, 0x80000000, 0x0, 0x80000000, 0x80000000, 0x0, 0xf0000
	dspck_astio dpsq_sa.l.w, 0x0, 0x0, 0x80000000, 0x1, 0x80000000, 0x80000000, 0x0, 0xf0000
	dspck_astio dpsq_sa.l.w, 0x0, 0x0, 0x3fffffff, 0x80000000, 0xc0000000, 0x7fffffff, 0x0, 0x0

	writemsg "[61] Test maq_s.w.phl"
	dspck_astio maq_s.w.phl, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_astio maq_s.w.phl, 0xffffffff, 0x0, 0xffffffff, 0x0, 0x0, 0x40004000, 0x0, 0x0
	dspck_astio maq_s.w.phl, 0x0, 0xffffffff, 0x0, 0xffffffff, 0x7fff7fff, 0x0, 0x0, 0x0
	dspck_astio maq_s.w.phl, 0xffffffff, 0x0, 0xffffffff, 0x0, 0x7fff7fff, 0x0, 0x0, 0x0
	dspck_astio maq_s.w.phl, 0x0, 0x40000000, 0x0, 0x40000000, 0x0, 0xc000c000, 0x0, 0x0

	writemsg "[62] Test maq_s.w.phr"
	dspck_astio maq_s.w.phr, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_astio maq_s.w.phr, 0xffffffff, 0x0, 0xffffffff, 0x0, 0x0, 0x40004000, 0x0, 0x0
	dspck_astio maq_s.w.phr, 0x0, 0xffffffff, 0x0, 0xffffffff, 0x7fff7fff, 0x0, 0x0, 0x0
	dspck_astio maq_s.w.phr, 0xffffffff, 0x0, 0xffffffff, 0x0, 0x7fff7fff, 0x0, 0x0, 0x0
	dspck_astio maq_s.w.phr, 0x0, 0x40000000, 0x0, 0x40000000, 0x0, 0xc000c000, 0x0, 0x0

	writemsg "[63] Test maq_sa.w.phl"
	dspck_astio maq_sa.w.phl, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_astio maq_sa.w.phl, 0xffffffff, 0x80000000, 0xffffffff, 0x80000000, 0x0, 0x40004000, 0x0, 0x0
	dspck_astio maq_sa.w.phl, 0x0, 0x7fffffff, 0x0, 0x7fffffff, 0x7fff7fff, 0x0, 0x0, 0x0
	dspck_astio maq_sa.w.phl, 0xffffffff, 0x80000000, 0xffffffff, 0x80000000, 0x7fff7fff, 0x0, 0x0, 0x0
	dspck_astio maq_sa.w.phl, 0x0, 0x40000000, 0x0, 0x40000000, 0x0, 0xc000c000, 0x0, 0x0

	writemsg "[64] Test maq_sa.w.phr"
	dspck_astio maq_sa.w.phr, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_astio maq_sa.w.phr, 0xffffffff, 0x80000000, 0xffffffff, 0x80000000, 0x0, 0x40004000, 0x0, 0x0
	dspck_astio maq_sa.w.phr, 0x0, 0x7fffffff, 0x0, 0x7fffffff, 0x7fff7fff, 0x0, 0x0, 0x0
	dspck_astio maq_sa.w.phr, 0xffffffff, 0x80000000, 0xffffffff, 0x80000000, 0x7fff7fff, 0x0, 0x0, 0x0
	dspck_astio maq_sa.w.phr, 0x0, 0x40000000, 0x0, 0x40000000, 0x0, 0xc000c000, 0x0, 0x0

	writemsg "[65] Test bitrev"
	dspck_dsio bitrev, 0x0, 0x0, 0x0, 0x0
	dspck_dsio bitrev, 0x1, 0x8000, 0x0, 0x0
	dspck_dsio bitrev, 0x8000, 0x1, 0x0, 0x0
	dspck_dsio bitrev, 0xc0c0, 0x1010303, 0x0, 0x0
	dspck_dsio bitrev, 0x1, 0xffff8000, 0x0, 0x0

	writemsg "[66] Test insv"
	dspck_tsi insv, 0xf0caf0f0, 0xf0f0f0f0, 0xa5a5a5a5, 0x311
	dspck_tsi insv, 0x7fffffe, 0x0, 0x7ffffff, 0xd01
	dspck_tsi insv, 0x3fff, 0x0, 0x3fff, 0x700
	dspck_tsi insv, 0xf0f2f0f0, 0xf0f0f0f0, 0xa5a5a5a5, 0x28f
	dspck_tsi insv, 0x3fc, 0x0, 0x3ff, 0x402

	writemsg "[67] Test repl.qb"
	dspck_dIio repl.qb, 0x0, 0, 0x0, 0x0
	dspck_dIio repl.qb, 0x1010101, 1, 0x0, 0x0
	dspck_dIio repl.qb, 0xffffffff, 255, 0x0, 0x0
	dspck_dIio repl.qb, 0x7f7f7f7f, 127, 0x0, 0x0
	dspck_dIio repl.qb, 0xfefefefe, 254, 0x0, 0x0

	writemsg "[68] Test replv.qb"
	dspck_dsio replv.qb, 0x0, 0x0, 0x0, 0x0
	dspck_dsio replv.qb, 0x1010101, 0x1, 0x0, 0x0
	dspck_dsio replv.qb, 0xffffffff, 0xff, 0x0, 0x0
	dspck_dsio replv.qb, 0x7f7f7f7f, 0x37f, 0x0, 0x0
	dspck_dsio replv.qb, 0xfefefefe, 0xfffffffe, 0x0, 0x0

	writemsg "[69] Test repl.ph"
	dspck_dIio repl.ph, 0x0, 0, 0x0, 0x0
	dspck_dIio repl.ph, 0x10001, 1, 0x0, 0x0
	dspck_dIio repl.ph, 0xffffffff, -1, 0x0, 0x0
	dspck_dIio repl.ph, 0xff7fff7f, -129, 0x0, 0x0
	dspck_dIio repl.ph, 0xfffefffe, -2, 0x0, 0x0

	writemsg "[70] Test replv.ph"
	dspck_dsio replv.ph, 0x0, 0x0, 0x0, 0x0
	dspck_dsio replv.ph, 0x10001, 0x1, 0x0, 0x0
	dspck_dsio replv.ph, 0xffffffff, 0x5555ffff, 0x0, 0x0
	dspck_dsio replv.ph, 0x37f037f, 0x37f, 0x0, 0x0
	dspck_dsio replv.ph, 0xfffefffe, 0xfffffffe, 0x0, 0x0

	writemsg "[71] Test cmpu.eq.qb"
	dspck_stio cmpu.eq.qb, 0x0, 0x0, 0x0, 0xf000000
	dspck_stio cmpu.eq.qb, 0xffffffff, 0x0, 0x0, 0x0
	dspck_stio cmpu.eq.qb, 0x0, 0xffffffff, 0x0, 0x0
	dspck_stio cmpu.eq.qb, 0x10203, 0x4050607, 0x0, 0x0
	dspck_stio cmpu.eq.qb, 0x8090a0b, 0xc0d0e0f, 0x0, 0x0

	writemsg "[72] Test cmpu.lt.qb"
	dspck_stio cmpu.lt.qb, 0x0, 0x0, 0x0, 0x0
	dspck_stio cmpu.lt.qb, 0xffffffff, 0x0, 0x0, 0x0
	dspck_stio cmpu.lt.qb, 0x0, 0xffffffff, 0x0, 0xf000000
	dspck_stio cmpu.lt.qb, 0x10203, 0x4050607, 0x0, 0xf000000
	dspck_stio cmpu.lt.qb, 0x8090a0b, 0xc0d0e0f, 0x0, 0xf000000

	writemsg "[73] Test cmpu.le.qb"
	dspck_stio cmpu.le.qb, 0x0, 0x0, 0x0, 0xf000000
	dspck_stio cmpu.le.qb, 0xffffffff, 0x0, 0x0, 0x0
	dspck_stio cmpu.le.qb, 0x0, 0xffffffff, 0x0, 0xf000000
	dspck_stio cmpu.le.qb, 0x10203, 0x4050607, 0x0, 0xf000000
	dspck_stio cmpu.le.qb, 0x8090a0b, 0xc0d0e0f, 0x0, 0xf000000

	writemsg "[74] Test cmpgu.eq.qb"
	dspck_dstio cmpgu.eq.qb, 0xf, 0x0, 0x0, 0x0, 0x0
	dspck_dstio cmpgu.eq.qb, 0x0, 0xffffffff, 0x0, 0x0, 0x0
	dspck_dstio cmpgu.eq.qb, 0x0, 0x0, 0xffffffff, 0x0, 0x0
	dspck_dstio cmpgu.eq.qb, 0x0, 0x10203, 0x4050607, 0x0, 0x0
	dspck_dstio cmpgu.eq.qb, 0x0, 0x8090a0b, 0xc0d0e0f, 0x0, 0x0

	writemsg "[75] Test cmpgu.lt.qb"
	dspck_dstio cmpgu.lt.qb, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_dstio cmpgu.lt.qb, 0x0, 0xffffffff, 0x0, 0x0, 0x0
	dspck_dstio cmpgu.lt.qb, 0xf, 0x0, 0xffffffff, 0x0, 0x0
	dspck_dstio cmpgu.lt.qb, 0xf, 0x10203, 0x4050607, 0x0, 0x0
	dspck_dstio cmpgu.lt.qb, 0xf, 0x8090a0b, 0xc0d0e0f, 0x0, 0x0

	writemsg "[76] Test cmpgu.le.qb"
	dspck_dstio cmpgu.le.qb, 0xf, 0x0, 0x0, 0x0, 0x0
	dspck_dstio cmpgu.le.qb, 0x0, 0xffffffff, 0x0, 0x0, 0x0
	dspck_dstio cmpgu.le.qb, 0xf, 0x0, 0xffffffff, 0x0, 0x0
	dspck_dstio cmpgu.le.qb, 0xf, 0x10203, 0x4050607, 0x0, 0x0
	dspck_dstio cmpgu.le.qb, 0xf, 0x8090a0b, 0xc0d0e0f, 0x0, 0x0

	writemsg "[77] Test cmp.eq.ph"
	dspck_stio cmp.eq.ph, 0x0, 0x0, 0x0, 0x3000000
	dspck_stio cmp.eq.ph, 0x0, 0xffffffff, 0x0, 0x0
	dspck_stio cmp.eq.ph, 0xffffffff, 0x0, 0x0, 0x0
	dspck_stio cmp.eq.ph, 0x7fff7fff, 0xffffffff, 0x0, 0x0
	dspck_stio cmp.eq.ph, 0x11112222, 0x33334444, 0x0, 0x0

	writemsg "[78] Test cmp.lt.ph"
	dspck_stio cmp.lt.ph, 0x0, 0x0, 0x0, 0x0
	dspck_stio cmp.lt.ph, 0x0, 0xffffffff, 0x0, 0x0
	dspck_stio cmp.lt.ph, 0xffffffff, 0x0, 0x0, 0x3000000
	dspck_stio cmp.lt.ph, 0x7fff7fff, 0xffffffff, 0x0, 0x0
	dspck_stio cmp.lt.ph, 0x11112222, 0x33334444, 0x0, 0x3000000

	writemsg "[79] Test cmp.le.ph"
	dspck_stio cmp.le.ph, 0x0, 0x0, 0x0, 0x3000000
	dspck_stio cmp.le.ph, 0x0, 0xffffffff, 0x0, 0x0
	dspck_stio cmp.le.ph, 0xffffffff, 0x0, 0x0, 0x3000000
	dspck_stio cmp.le.ph, 0x7fff7fff, 0xffffffff, 0x0, 0x0
	dspck_stio cmp.le.ph, 0x11112222, 0x33334444, 0x0, 0x3000000

	writemsg "[80] Test pick.qb"
	dspck_dsti pick.qb, 0x0, 0x0, 0x0, 0x0
	dspck_dsti pick.qb, 0x0, 0xffffffff, 0x0, 0x0
	dspck_dsti pick.qb, 0xffffffff, 0xffffffff, 0x0, 0xf000000
	dspck_dsti pick.qb, 0xff, 0xffffffff, 0x0, 0x1000000
	dspck_dsti pick.qb, 0xff00, 0xffffffff, 0x0, 0x2000000

	writemsg "[81] Test pick.ph"
	dspck_dsti pick.ph, 0x0, 0x0, 0x0, 0x0
	dspck_dsti pick.ph, 0x0, 0xffffffff, 0x0, 0x0
	dspck_dsti pick.ph, 0xffffffff, 0xffffffff, 0x0, 0x3000000
	dspck_dsti pick.ph, 0xffff, 0xffffffff, 0x0, 0x1000000
	dspck_dsti pick.ph, 0xffff0000, 0xffffffff, 0x0, 0x2000000

	writemsg "[82] Test packrl.ph"
	dspck_dstio packrl.ph, 0x00000000, 0x00000000, 0x00000000, 0x0, 0x0
	dspck_dstio packrl.ph, 0x0000ffff, 0x00000000, 0xffff0000, 0x0, 0x0
	dspck_dstio packrl.ph, 0x00000000, 0x00000000, 0x0000ffff, 0x0, 0x0
	dspck_dstio packrl.ph, 0x00005555, 0x00000000, 0x5555aaaa, 0x0, 0x0
	dspck_dstio packrl.ph, 0x0000aaaa, 0x00000000, 0xaaaa5555, 0x0, 0x0

	writemsg "[83] Test extr.w"
	dspck_atsaio extr.w, 0x0, 0x0 0x0, 0x0, 0x0, 0x0
	dspck_atsaio extr.w, 0x7fffffff, 0xcbcdef01 0xffffffff, 0x1f, 0x0, 0x800000
	dspck_atsaio extr.w, 0x3fffffff, 0x2bcdef01 0x7ffffffe, 0x1f, 0x0, 0x0
	dspck_atsaio extr.w, 0xffffffff, 0xffffffff 0xffffffff, 0x0, 0x0, 0x0
	dspck_atsaio extr.w, 0x0, 0xfffffffe 0x7fffffff, 0x1, 0x0, 0x0

	writemsg "[84] Test extr_r.w"
	dspck_atsaio extr_r.w, 0x0, 0x0 0x0, 0x0, 0x0, 0x0
	dspck_atsaio extr_r.w, 0x7fffffff, 0xcbcdef01 0x0, 0x1f, 0x0, 0x800000
	dspck_atsaio extr_r.w, 0x3fffffff, 0x2bcdef01 0x7ffffffe, 0x1f, 0x0, 0x0
	dspck_atsaio extr_r.w, 0xffffffff, 0xffffffff 0xffffffff, 0x0, 0x0, 0x0
	dspck_atsaio extr_r.w, 0x0, 0xfffffffe 0x7fffffff, 0x1, 0x0, 0x0

	writemsg "[85] Test extr_rs.w"
	dspck_atsaio extr_rs.w, 0x0, 0x0 0x0, 0x0, 0x0, 0x0
	dspck_atsaio extr_rs.w, 0x7fffffff, 0xcbcdef01 0x7fffffff, 0x1f, 0x0, 0x800000
	dspck_atsaio extr_rs.w, 0x3fffffff, 0x2bcdef01 0x7ffffffe, 0x1f, 0x0, 0x0
	dspck_atsaio extr_rs.w, 0xffffffff, 0xffffffff 0xffffffff, 0x0, 0x0, 0x0
	dspck_atsaio extr_rs.w, 0x0, 0xfffffffe 0x7fffffff, 0x1, 0x0, 0x0

	writemsg "[86] Test extr_s.h"
	dspck_atsaio extr_s.h, 0x0, 0x0 0x0, 0x0, 0x0, 0x0
	dspck_atsaio extr_s.h, 0x7fffffff, 0xcbcdef01 0x7fff, 0x1f, 0x0, 0x800000
	dspck_atsaio extr_s.h, 0x3fffffff, 0x2bcdef01 0x7fff, 0x1f, 0x0, 0x800000
	dspck_atsaio extr_s.h, 0xffffffff, 0xffffffff 0xffffffff, 0x0, 0x0, 0x0
	dspck_atsaio extr_s.h, 0x0, 0xfffffffe 0x7fff, 0x1, 0x0, 0x800000

	writemsg "[87] Test extrv_s.h"
	dspck_atsio extrv_s.h, 0x0, 0x0 0x0, 0x0, 0x0, 0x0
	dspck_atsio extrv_s.h, 0x7fffffff, 0xcbcdef01 0x7fff, 0x1f, 0x0, 0x800000
	dspck_atsio extrv_s.h, 0x3fffffff, 0x2bcdef01 0x7fff, 0x1f, 0x0, 0x800000
	dspck_atsio extrv_s.h, 0xffffffff, 0xffffffff 0xffffffff, 0x0, 0x0, 0x0
	dspck_atsio extrv_s.h, 0x0, 0xfffffffe 0x7fff, 0x1, 0x0, 0x800000

	writemsg "[88] Test extrv.w"
	dspck_atsio extrv.w, 0x0, 0x0 0x0, 0x0, 0x0, 0x0
	dspck_atsio extrv.w, 0x7fffffff, 0xcbcdef01 0xffffffff, 0x1f, 0x0, 0x800000
	dspck_atsio extrv.w, 0x3fffffff, 0x2bcdef01 0x7ffffffe, 0x1f, 0x0, 0x0
	dspck_atsio extrv.w, 0xffffffff, 0xffffffff 0xffffffff, 0x0, 0x0, 0x0
	dspck_atsio extrv.w, 0x0, 0xfffffffe 0x7fffffff, 0x1, 0x0, 0x0

	writemsg "[89] Test extrv_r.w"
	dspck_atsio extrv_r.w, 0x0, 0x0 0x0, 0x0, 0x0, 0x0
	dspck_atsio extrv_r.w, 0x7fffffff, 0xcbcdef01 0x0, 0x1f, 0x0, 0x800000
	dspck_atsio extrv_r.w, 0x3fffffff, 0x2bcdef01 0x7ffffffe, 0x1f, 0x0, 0x0
	dspck_atsio extrv_r.w, 0xffffffff, 0xffffffff 0xffffffff, 0x0, 0x0, 0x0
	dspck_atsio extrv_r.w, 0x0, 0xfffffffe 0x7fffffff, 0x1, 0x0, 0x0

	writemsg "[90] Test extrv_rs.w"
	dspck_atsio extrv_rs.w, 0x0, 0x0 0x0, 0x0, 0x0, 0x0
	dspck_atsio extrv_rs.w, 0x7fffffff, 0xcbcdef01 0x7fffffff, 0x1f, 0x0, 0x800000
	dspck_atsio extrv_rs.w, 0x3fffffff, 0x2bcdef01 0x7ffffffe, 0x1f, 0x0, 0x0
	dspck_atsio extrv_rs.w, 0xffffffff, 0xffffffff 0xffffffff, 0x0, 0x0, 0x0
	dspck_atsio extrv_rs.w, 0x0, 0xfffffffe 0x7fffffff, 0x1, 0x0, 0x0

	writemsg "[91] Test extp"
	dspck_tasiimom extp, 0x0, 0x0, 0x0, 0x0, 0x4000, 0x403f, 0x0, 0x403f
	dspck_tasiimom extp, 0xffffffff, 0xffff7eff, 0x7e, 0x7, 0xf, 0x3f, 0x0, 0x4000
	dspck_tasiim extp, 0xfffffff7, 0xefffffff, 0x7e, 0x7, 0x23, 0x3f
	dspck_tasiim extp, 0xffff7eff, 0xffffffff, 0x7e, 0x7, 0x2f, 0x3f

	writemsg "[92] Test extpv"
	dspck_tasimom extpv, 0x0, 0x0, 0x0, 0x0, 0x4000, 0x403f, 0x0, 0x403f
	dspck_tasimom extpv, 0xffffffff, 0xffff7eff, 0x7e, 0x7, 0xf, 0x3f, 0x0, 0x4000
	dspck_tasim extpv, 0xfffffff7, 0xefffffff, 0x7e, 0x7, 0x23, 0x3f
	dspck_tasim extpv, 0xffff7eff, 0xffffffff, 0x7e, 0x7, 0x2f, 0x3f

	writemsg "[93] Test extpdp"
	dspck_tasiimom extpdp, 0x0, 0x0, 0x0, 0x0, 0x4000, 0x403f, 0x3f, 0x403f
	dspck_tasiimom extpdp, 0xffffffff, 0xffff7eff, 0x7e, 0x7, 0xf, 0x3f, 0x0, 0x4000
	dspck_tasiim extpdp, 0xfffffff7, 0xefffffff, 0x7e, 0x7, 0x23, 0x3f
	dspck_tasiim extpdp, 0xffff7eff, 0xffffffff, 0x7e, 0x7, 0x2f, 0x3f

	writemsg "[94] Test extpdpv"
	dspck_tasimom extpdpv, 0x0, 0x0, 0x0, 0x0, 0x4000, 0x403f, 0x3f, 0x403f
	dspck_tasimom extpdpv, 0xffffffff, 0xffff7eff, 0x7e, 0x7, 0xf, 0x3f, 0x0, 0x4000
	dspck_tasim extpdpv, 0xfffffff7, 0xefffffff, 0x7e, 0x7, 0x23, 0x3f
	dspck_tasim extpdpv, 0xffff7eff, 0xffffffff, 0x7e, 0x7, 0x2f, 0x3f

	writemsg "[95] Test shilo"
	dspck_asaio shilo, 0x0, 0x0, 0x0, 0x0, 0, 0x0, 0x0
	dspck_asaio shilo, 0x1, 0x80000000, 0x1, 0x80000000, 0, 0x0, 0x0
	dspck_asaio shilo, 0x1, 0x80000000, 0x3, 0x0, -1, 0x0, 0x0
	dspck_asaio shilo, 0x1, 0x80000000, 0x6, 0x0, -2, 0x0, 0x0
	dspck_asaio shilo, 0x1, 0x80000000, 0x18, 0x0, -4, 0x0, 0x0

	writemsg "[96] Test shilov"
	dspck_asio shilov, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
	dspck_asio shilov, 0x1, 0x80000000, 0x1, 0x80000000, 0x0, 0x0, 0x0
	dspck_asio shilov, 0x1, 0x80000000, 0x3, 0x0, 0xffffffff, 0x0, 0x0
	dspck_asio shilov, 0x1, 0x80000000, 0x6, 0x0, 0xfffffffe, 0x0, 0x0
	dspck_asio shilov, 0x1, 0x80000000, 0x18, 0x0, 0xfffffffc, 0x0, 0x0

	writemsg "[97] Test mthlip"
	dspck_saio mthlip, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x20
	dspck_saio mthlip, 0x0, 0x1, 0x1, 0x2, 0x2, 0x8, 0x28
	dspck_saio mthlip, 0xffffffff, 0xffff1234, 0xffff1234, 0xfffffffe, 0xfffffffe, 0x10, 0x30
	dspck_saio mthlip, 0xdeadbeef, 0x1234, 0x1234, 0xbeefdead, 0xbeefdead, 0x18, 0x38

	writemsg "[98] Test wrdsp"
	dspck_wrdsp 0x0, 0x0, 0x0, 0x0
	dspck_wrdsp 0x4000, 0x20, 0x0, 0x4000
	dspck_wrdsp 0xffffffff, 0x3f, 0x0, 0x0fff7fbf
	dspck_wrdsp 0x3f, 0x1, 0x0, 0x3f
	dspck_wrdsp 0x1f80, 0x2, 0x0, 0x1f80

	writemsg "[99] Test rddsp"
	dspck_rddsp 0x0, 0x0, 0x0
	dspck_rddsp 0x0, 0x0, 0xffffffff
	dspck_rddsp 0x3f, 0x1, 0xffffffff
	dspck_rddsp 0x1f80, 0x2, 0x0fff7fbf
	dspck_rddsp 0x2000, 0x4, 0x0fff7fbf

	writemsg "[100] Test lbux"
	.data
mydata:
	.byte	0x12
	.byte	0x34
	.byte	0x56
	.byte	0x78
	.byte	0x9a
	.byte	0xbc
	.byte	0xde
	.byte	0xf0
	.previous
	dspck_load lbux, 0x12, 0x0, mydata
	dspck_load lbux, 0x34, 0x1, mydata
	dspck_load lbux, 0x56, 0x2, mydata
	dspck_load lbux, 0x78, 0x3, mydata
	dspck_load lbux, 0x9a, 0x4, mydata
	dspck_load lbux, 0xbc, 0x5, mydata
	dspck_load lbux, 0xde, 0x6, mydata
	dspck_load lbux, 0xf0, 0x7, mydata

	writemsg "[101] Test lhx"
	.data
myhdata:
	.hword	0x1234
	.hword	0x5678
	.hword	0x9abc
	.hword	0xdef0
	.previous
	dspck_load lhx, 0x1234, 0x0, myhdata
	dspck_load lhx, 0x5678, 0x2, myhdata
	dspck_load lhx, 0xffff9abc, 0x4, myhdata
	dspck_load lhx, 0xffffdef0, 0x6, myhdata

	writemsg "[102] Test lwx"
	.data
mywdata:
	.word	0x12345678
	.word	0x9abcdef0
	.word	0x13579abc
	.word	0xffff0001
	.previous
	dspck_load lwx, 0x12345678, 0x0, mywdata
	dspck_load lwx, 0x9abcdef0, 0x4, mywdata
	dspck_load lwx, 0x13579abc, 0x8, mywdata
	dspck_load lwx, 0xffff0001, 0xc, mywdata

	writemsg "[103] Test bposge32"
	dspck_bposge32 0x0, 0
	dspck_bposge32 0x1f, 0
	dspck_bposge32 0x20, 1
	dspck_bposge32 0x3f, 1

	pass
	.end DIAG

