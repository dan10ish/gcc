/* Definitions of target machine for GNU compiler.  MIPS RISC-OS BSD version.
   Copyright (C) 1991 Free Software Foundation, Inc.

This file is part of GNU CC.

GNU CC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU CC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU CC; see the file COPYING.  If not, write to
the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */

#define MIPS_BSD43

#define CPP_PREDEFINES "-Dmips -Dunix -Dhost_mips -DMIPSEB -DR3000"

#define CPP_SPEC	"%{!ansi:	%{!ZSYSV: -DSYSTYPE_BSD43}	\
					%{ZSYSV:  -DSYSTYPE_SYSV}}	\
			 %{!ZSYSV: -D__SYSTYPE_BSD43__}			\
			 %{ZSYSV:  -D__SYSTYPE_SYSV__}			\
			 %{!nostdinc:	%{!ZSYSV: -I/bsd43/usr/include}	\
					%{ZSYSV:  -I/sysv/usr/include}}	\
			 %{.S:	-D__LANGUAGE_ASSEMBLY__			\
				-D_LANGUAGE_ASSEMBLY			\
				%{!ansi: -DLANGUAGE_ASSEMBLY}}		\
			 %{!.S:	-D__LANGUAGE_C__			\
				-D_LANGUAGE_C				\
				%{!ansi:-DLANGUAGE_C}}"

#define LINK_SPEC	"%{G*}						\
			 %{!mgas:					\
				%{EB} %{!EB: -EB}			\
				%{EL: %e-EL not supported}		\
				%{bestGnum}				\
				%{!ZSYSV: -systype /bsd43/}		\
				%{ZSYSV:  -systype /sysv/}}"
		    
#define LIB_SPEC "%{p:-lprof1} %{pg:-lprof1} -lc"

#define STARTFILE_SPEC "%{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt1.o%s crtn.o%s}}"

#define MACHINE_TYPE "RISC-OS BSD Mips"

#include "mips.h"
