#ifndef _NEWCOMPLEX_TEST_H
#define _NEWCOMPLEX_TEST_H

#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <math.h>
#include <complex.h>

/* Default to double types.  */
#if !(defined (_NEW_COMPLEX_FLOAT) || defined (_NEW_COMPLEX_DOUBLE) || defined (_NEW_COMPLEX_LDOUBLE))
#define _NEW_COMPLEX_DOUBLE 1
#endif

/* Grab the internals for things like __FLT_PI, etc.  */
#include "complex_internal.h"

#if defined(_NEW_COMPLEX_DOUBLE)
# define __FLT_CMP	compare_dbl
# define __FLT_CCMP	compare_cdbl
# define __FLT_DELTA	(2.0 * __DBL_EPSILON__)
# define __FLT_FMT	"%0.32g"
#elif defined (_NEW_COMPLEX_FLOAT)
# define __FLT_CMP	compare_flt
# define __FLT_CCMP	compare_cflt
# define __FLT_DELTA	(2.0F * __FLT_EPSILON__)
# define __FLT_FMT	 "%0.32g"
#elif defined (_NEW_COMPLEX_LDOUBLE)
# define __FLT_CMP	compare_ldbl
# define __FLT_CCMP	compare_cldbl
# define __FLT_DELTA	(2.0L * __LDBL_EPSILON__)
# define __FLT_FMT	 "%0.32Lg"
#endif

struct complex_test
{
  /* The input value to the complex function */
  __FLT_TYPE input_r;
  __FLT_TYPE input_i;
  /* The expected value from the complex function */
  __FLT_TYPE expected_r;
  __FLT_TYPE expected_i;
  /* Some C99 signs are +/-.  When these are true, don't compare signs */
  int real_sign_dontcare;
  int imag_sign_dontcare;
};

/* Definition of the function under test.  */
typedef __FLT_TYPE complex (*complex_function)(__FLT_TYPE complex z);
typedef __FLT_TYPE         (*real_function)(__FLT_TYPE complex z);

/* Some possible behaviors of the function.  */
/* func (conj (z)) = conj (func (z))  */
#define FUNC_BEHAVIOR_CONJ 0x0001
/* func (-z) = -func (z)  */
#define FUNC_BEHAVIOR_ODD  0x0002
/* func (-z) = func (z)  */
#define FUNC_BEHAVIOR_EVEN 0x0004

/* Structure to hold info about the complex function.  */
struct test_func_desc
{
  const char *fname;
  complex_function complex_test;
  real_function    real_test;
  int              behavior;
};

/**
 * Compares expected and test values with a delta tolerance.
 * 0 for pass, 1 for fail.
 * TODO:
 * Tune comparison precision
 **/

static int
__FLT_CMP (__FLT_TYPE expected, __FLT_TYPE in, int sign_dontcare)
{
  int bad = 0;
  if (isnan (expected) || isnan (in))
    {
      /* NaN comparisons */
      bad = isnan (expected) != isnan (in);
    }
  else if (isfinite (expected) && isfinite (in))
    {
      /* Finite value tests */
      if (expected == 0 && in == 0)
	{
	  /* Signed zero comparison */
	  bad = (sign_dontcare) ? 0 : signbit (expected) != signbit (in);
	}
      else
	{
	  bad = (expected > in) ?
		((expected - in) > __FLT_DELTA) :
		((in - expected) > __FLT_DELTA);
	}
    }
  else
    {
      /* Either expected or in is an infinite */
      bad = (isfinite (expected) != isfinite (in)) ||
	    (sign_dontcare ? 0 : (signbit (expected) != signbit (in)));
    }

  return bad;
}

static int
__FLT_CCMP (complex __FLT_TYPE expected,
	    complex __FLT_TYPE in,
	    int real_sign_dontcare,
	    int imag_sign_dontcare)
{
  return (__FLT_CMP (__FLT_ABI(creal)(expected), __FLT_ABI(creal)(in), real_sign_dontcare) ||
	  __FLT_CMP (__FLT_ABI(cimag)(expected), __FLT_ABI(cimag)(in), real_sign_dontcare));
}

/* Runs comparison and (DEBUG) print error.
   returns 1 on fail, 0 on success.  */
static int
error_check_test (const struct test_func_desc *fdesc,
		  const char* testdescription,
		  int testindex,
		  __FLT_TYPE complex test,
		  __FLT_TYPE complex expected,
		  int real_sign_dontcare,
		  int imag_sign_dontcare)
{
  int bad = 0;
  __FLT_TYPE complex actual;
  if (fdesc->complex_test)
    {
      actual = fdesc->complex_test (test);
      bad = __FLT_CCMP (expected, actual, real_sign_dontcare, imag_sign_dontcare);
      if (bad)
	{
	  printf("%s %s test index %d failed on input " __FLT_FMT " + " __FLT_FMT "i.\n"
		"\tExpected: " __FLT_FMT " + " __FLT_FMT "i\n"
		"\tActual: " __FLT_FMT " + " __FLT_FMT "i (epsilon=" __FLT_FMT ")\n",
		fdesc->fname, testdescription, testindex,
		__FLT_ABI(creal) (test),    __FLT_ABI(cimag) (test),
		__FLT_ABI(creal) (expected), __FLT_ABI(cimag) (expected),
		__FLT_ABI(creal) (actual),   __FLT_ABI(cimag) (actual),
		__FLT_DELTA);
	}
    }
  else
    {
      __real__ actual = fdesc->real_test (test);
      bad = __FLT_CMP (__real__ expected, actual, real_sign_dontcare);
      if (bad)
	{
	  printf("%s %s test index %d failed on input " __FLT_FMT " + " __FLT_FMT "i.\n"
		"\tExpected: " __FLT_FMT "\n"
		"\tActual: " __FLT_FMT " (epsilon=" __FLT_FMT ")\n",
		fdesc->fname, testdescription, testindex,
		__FLT_ABI(creal) (test),    __FLT_ABI(cimag) (test),
		__FLT_ABI(creal) (expected),
		__FLT_ABI(creal) (actual),
		__FLT_DELTA);
	}
    }

  return bad;
}

/* Tests of conjugates, function should satisfy
   func (conj (z)) = conj (func (z)).  We test this two ways.  The first
   way is that the func (conj (z)) should return the conj of the expected,
   since expected is the expected result of func (z).  The second test
   actually confirms the equality.  */
static int
conjugate_tests (const struct test_func_desc *fdesc,
		 int testindex,
		 __FLT_TYPE complex test,
		 __FLT_TYPE complex expected,
		 int real_sign_dontcare,
		 int imag_sign_dontcare)
{
  int ret = 0;

  /* Conjugate test 1: verify result of func (conj (z)) is conj (expected) */
  __FLT_TYPE complex ctest =    __FLT_ABI(conj) (test);
  __FLT_TYPE complex cexpected = __FLT_ABI(conj) (expected);

  ret |= error_check_test (fdesc, "Congugate of expected", testindex, ctest, cexpected,
			  real_sign_dontcare, imag_sign_dontcare);

#if NOTYET
  /* Conjugate test 2: verify result of func (conj (z)) is conj (func (z)) */
  ctest =    __FLT_ABI(conj) (test);
  cexpected = __FLT_ABI(conj) (fdesc->test (test));
  ret |= error_check_test (fdesc, "Congugate of result", testindex, ctest, cexpected,
			  real_sign_dontcare, imag_sign_dontcare);
#endif
  return ret;
}

/* Tests of odd functions, function should satisfy
   func (-z) = -func (z).  We test this two ways.  The first
   way is that func (-z) should result in the -expected result, since
   expected is the expected result of func (z).  The second test confirms
   the equality.  */
static int
odd_tests (const struct test_func_desc *fdesc,
	   int testindex,
	   __FLT_TYPE complex test,
	   __FLT_TYPE complex expected,
	   int real_sign_dontcare,
	   int imag_sign_dontcare)
{
  int ret = 0;

  /* Oddness test 1: verify result of func (-z) is -expected */
  __FLT_TYPE complex ctest =    -test;
  __FLT_TYPE complex cexpected = -expected;

  ret |= error_check_test (fdesc, "Oddness of expected", testindex, ctest, cexpected,
			  real_sign_dontcare, imag_sign_dontcare);

  /* Need to do conjugate of the odd values as well */
  ret |= conjugate_tests(fdesc, testindex, ctest, cexpected, real_sign_dontcare,
			imag_sign_dontcare);

#if NOTYET
  /* Oddness test 2: verify result of func (-z) is -func (z) */
  ctest =    -test;
  cexpected = -(fdesc->test (test));
  ret |= error_check_test (fdesc, "Oddness of returns", testindex, ctest, cexpected,
			  real_sign_dontcare, imag_sign_dontcare);

  /* Need to do conjugate of the odd values as well */
  ret |= conjugate_tests(fdesc, testindex, ctest, cexpected, real_sign_dontcare,
			imag_sign_dontcare);
#endif
  return ret;
}

/* Tests of even functions, function should satisfy
   func (-z) = func (z).  We test this two ways.  The first
   way is that func (-z) should result in the expected result, since
   expected is the expected result of func (z).  The second test confirms
   the equality.  */
static int
even_tests (const struct test_func_desc *fdesc,
	   int testindex,
	   __FLT_TYPE complex test,
	   __FLT_TYPE complex expected,
	   int real_sign_dontcare,
	   int imag_sign_dontcare)
{
  int ret = 0;

  /* Evenness test 1: verify result of func (-z) is expected */
  __FLT_TYPE complex ctest =    -test;
  __FLT_TYPE complex cexpected = expected;

  ret |= error_check_test (fdesc, "Evenness of expected", testindex, ctest, cexpected,
			  real_sign_dontcare, imag_sign_dontcare);

  /* Need to do conjugate of the even values as well */
  ret |= conjugate_tests(fdesc, testindex, ctest, cexpected, real_sign_dontcare,
			imag_sign_dontcare);

#if NOTYET
  /* Evenness test 2: verify result of func (-z) is func (z) */
  ctest =    -test;
  cexpected = fdesc->test (test);

  ret |= error_check_test (fdesc, "Evenness of returns", testindex, ctest, cexpected,
			  real_sign_dontcare, imag_sign_dontcare);

  /* Need to do conjugate of the even values as well */
  ret |= conjugate_tests(fdesc, testindex, ctest, cexpected, real_sign_dontcare,
			imag_sign_dontcare);
#endif
  return ret;
}

/* Actually run the tests.  */
static int
runtests (const struct test_func_desc *testfunc,
	  const struct complex_test *testarray,
	  int testcount)
{
  int i;
  int ret = 0;

  for (i = 0; i < testcount; i++)
    {
      __FLT_TYPE complex test;
      __FLT_TYPE complex expected;
      __real__ test = testarray[i].input_r;
      __imag__ test = testarray[i].input_i;
      __real__ expected = testarray[i].expected_r;
      __imag__ expected = testarray[i].expected_i;

      /* Main test --- specified in Annex G, et al. */
      ret |= error_check_test (testfunc, "Annex G", i, test, expected,
		testarray[i].real_sign_dontcare, testarray[i].imag_sign_dontcare);

      if (testfunc->behavior & FUNC_BEHAVIOR_CONJ)
	{
	  ret |= conjugate_tests (testfunc, i, test, expected,
		 testarray[i].real_sign_dontcare, testarray[i].imag_sign_dontcare);
	}

      if (testfunc->behavior & FUNC_BEHAVIOR_ODD)
	{
	  ret |= odd_tests (testfunc, i, test, expected,
		 testarray[i].real_sign_dontcare, testarray[i].imag_sign_dontcare);
	}

      if (testfunc->behavior & FUNC_BEHAVIOR_EVEN)
	{
	  ret |= even_tests (testfunc, i, test, expected,
		 testarray[i].real_sign_dontcare, testarray[i].imag_sign_dontcare);
	}
    }

  return ret;
}

#define __FLT_STRING(x) #x
#define __FLT_STRINGIFY(x) __FLT_STRING(x)

/* Define that can be used by the test to actually define the function under test.  */
#define DEFINE_TEST_FUNCTION(funcname, behavior)	\
  struct test_func_desc testfunc =			\
  {							\
    __FLT_STRINGIFY(__FLT_ABI(funcname)),		\
    __FLT_ABI(funcname),				\
    NULL,						\
    behavior						\
  }

#define DEFINE_REAL_TEST_FUNCTION(funcname, behavior)	\
  struct test_func_desc testfunc =			\
  {							\
    __FLT_STRINGIFY(__FLT_ABI(funcname)),		\
    NULL,						\
    __FLT_ABI(funcname),				\
    behavior						\
  }

/* Do not use semicolons with these macros.  */
#define TEST_PROLOGUE const struct complex_test testarray[] = {
#define DECLARE_TEST(input_r, input_i, expected_r, expected_i, real_sign_dontcare, imag_sign_dontcare)	\
  { input_r, input_i, expected_r, expected_i, real_sign_dontcare, imag_sign_dontcare },
#define TEST_EPILOGUE };

/* Actually run the tests */
#define RUNTESTS runtests(&testfunc, testarray, (sizeof (testarray) / sizeof (*testarray)));

#endif  /* _NEWCOMPLEX_TEST_H */
