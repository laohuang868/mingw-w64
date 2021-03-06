/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#define __CRT__NO_INLINE
#include <math.h>

int __fpclassifyl (long double _x){
#ifdef __x86_64__
    __mingw_fp_types_t hlp;
    unsigned int e;
    hlp.ld = &_x;
    e = hlp.ldt->lh.sign_exponent & 0x7fff;
    if (!e)
      {
        unsigned int h = hlp.ldt->lh.high;
        if (!(hlp.ldt->lh.low | h))
          return FP_ZERO;
        else if (!(h & 0x80000000))
          return FP_SUBNORMAL;
      }
    else if (e == 0x7fff)
      return (((hlp.ldt->lh.high & 0x7fffffff) | hlp.ldt->lh.low) == 0 ?
	      FP_INFINITE : FP_NAN);
    return FP_NORMAL;
#else
  unsigned short sw;
  __asm__ __volatile__ (
	"fxam; fstsw %%ax;"
	: "=a" (sw)
	: "t" (_x)
	);
  return sw & (FP_NAN | FP_NORMAL | FP_ZERO );
#endif
}
