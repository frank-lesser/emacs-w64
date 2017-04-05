/* getopt (basic, portable features) gnulib wrapper header.
   Copyright (C) 1989-2017 Free Software Foundation, Inc.
   This file is part of gnulib.
   Unlike most of the getopt implementation, it is NOT shared
   with the GNU C Library.

   gnulib is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 3 of
   the License, or (at your option) any later version.

   gnulib is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public
   License along with gnulib; if not, see
   <http://www.gnu.org/licenses/>.  */

#ifndef _GETOPT_PFX_CORE_H
#define _GETOPT_PFX_CORE_H 1

/* This header should not be used directly; include getopt.h or
   unistd.h instead.  It does not have a protective #error, because
   the guard macro for getopt.h in gnulib is not fixed.  */

/* Standalone applications should #define __GETOPT_PREFIX to an
   identifier that prefixes the external functions and variables
   defined in getopt_core.h and getopt_ext.h.  Systematically
   rename identifiers so that they do not collide with the system
   functions and variables.  Renaming avoids problems with some
   compilers and linkers.  */
#ifdef __GETOPT_PREFIX
# ifndef __GETOPT_ID
#  define __GETOPT_CONCAT(x, y) x ## y
#  define __GETOPT_XCONCAT(x, y) __GETOPT_CONCAT (x, y)
#  define __GETOPT_ID(y) __GETOPT_XCONCAT (__GETOPT_PREFIX, y)
# endif
# undef getopt
# undef optarg
# undef opterr
# undef optind
# undef optopt
# define getopt __GETOPT_ID (getopt)
# define optarg __GETOPT_ID (optarg)
# define opterr __GETOPT_ID (opterr)
# define optind __GETOPT_ID (optind)
# define optopt __GETOPT_ID (optopt)
#endif

#include <getopt_core.h>

#endif /* getopt_pfx_core.h */