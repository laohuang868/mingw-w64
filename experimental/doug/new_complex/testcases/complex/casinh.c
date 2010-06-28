/*
 This Software is provided under the Zope Public License (ZPL) Version 2.1.

 Copyright (c) 2009, 2010 by the mingw-w64 project

 See the AUTHORS file for the list of contributors to the mingw-w64 project.

 This license has been certified as open source. It has also been designated
 as GPL compatible by the Free Software Foundation (FSF).

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

   1. Redistributions in source code must retain the accompanying copyright
      notice, this list of conditions, and the following disclaimer.
   2. Redistributions in binary form must reproduce the accompanying
      copyright notice, this list of conditions, and the following disclaimer
      in the documentation and/or other materials provided with the
      distribution.
   3. Names of the copyright holders must not be used to endorse or promote
      products derived from this software without prior written permission
      from the copyright holders.
   4. The right to distribute this software or to use it for any purpose does
      not give you the right to use Servicemarks (sm) or Trademarks (tm) of
      the copyright holders.  Use of them is covered by separate agreement
      with the copyright holders.
   5. If any files are modified, you must cause the modified files to carry
      prominent notices stating that you changed the files and the date of
      any change.

 Disclaimer

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY EXPRESSED
 OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY DIRECT, INDIRECT,
 INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
 OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "complex_test.h"

/**
 * Annex G.6.2.2 The casinh functions
 * casinh(conj(z)) = conj(casinh(z)) and casinh is odd.
 * casinh(+0 + i0) returns 0 + i0.
 * casinh(x + i inf) returns +inf + ipi /2 for positive-signed finite x.
 * casinh(x + iNaN) returns NaN + iNaN and optionally raises the invalid floating-point exception, for finite x.
 * casinh(+inf + iy) returns +inf + i0 for positive-signed finite y.
 * casinh(+inf + i inf) returns +inf + ipi /4.
 * casinh(+inf + iNaN) returns +inf + iNaN.
 * casinh(NaN + i0) returns NaN + i0.
 * casinh(NaN + iy) returns NaN + iNaN and optionally raises the invalid floating-point exception, for finite nonzero y.
 * casinh(NaN + i inf) returns +/-inf + iNaN (where the sign of the real part of the result is unspecified).
 * casinh(NaN + iNaN) returns NaN + iNaN.
 */

int __FLT_ABI(test_function_casinh) ()
{
  DEFAULT_TESTS_START

  DEFINE_TEST ( __FLT_CST( 0.0),   __FLT_CST(0.0), __FLT_CST(0.0), __FLT_CST(0.0), 0, 0)
  DEFINE_TEST (__FLT_CST(42.42),         INFINITY,       INFINITY,     __FLT_PI_2, 0, 0)
  DEFINE_TEST (__FLT_CST(42.42),        __FLT_NAN,      __FLT_NAN,      __FLT_NAN, 0, 0)
  DEFINE_TEST (        INFINITY, __FLT_CST(42.42),       INFINITY, __FLT_CST(0.0), 0, 0)
  DEFINE_TEST (        INFINITY,         INFINITY,       INFINITY,     __FLT_PI_4, 0, 0)
  DEFINE_TEST (        INFINITY,        __FLT_NAN,       INFINITY,      __FLT_NAN, 0, 0)
  DEFINE_TEST (       __FLT_NAN,   __FLT_CST(0.0),      __FLT_NAN, __FLT_CST(0.0), 0, 0)
  DEFINE_TEST (       __FLT_NAN, __FLT_CST(42.42),      __FLT_NAN,      __FLT_NAN, 0, 0)
  DEFINE_TEST (       __FLT_NAN,         INFINITY,       INFINITY,      __FLT_NAN, 1, 0)
  DEFINE_TEST (       __FLT_NAN,        __FLT_NAN,      __FLT_NAN,      __FLT_NAN, 0, 0)

  TESTS_END

  return RUN_DEFAULT_TESTS(casinh);
}
