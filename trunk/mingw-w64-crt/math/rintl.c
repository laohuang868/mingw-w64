/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <math.h>

long double rintl (long double x) {
  long double retval = 0.0L;
  __asm__ __volatile__ ("frndint;": "=t" (retval) : "0" (x));
  return retval;
}
