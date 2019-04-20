#ifndef _C_MATH_H_
#define _C_MATH_H_

#include "compiler.h"

#define	M_E		2.7182818284590452354	/* e */
#define	M_LOG2E		1.4426950408889634074	/* log 2e */
#define	M_LOG10E	0.43429448190325182765	/* log 10e */
#define	M_LN2		0.69314718055994530942	/* log e2 */
#define	M_LN10		2.30258509299404568402	/* log e10 */
#define	M_PI		3.14159265358979323846	/* pi */
#define	M_PI_2		1.57079632679489661923	/* pi/2 */
#define	M_PI_4		0.78539816339744830962	/* pi/4 */
#define	M_1_PI		0.31830988618379067154	/* 1/pi */
#define	M_2_PI		0.63661977236758134308	/* 2/pi */
#define	M_2_SQRTPI	1.12837916709551257390	/* 2/sqrt(pi) */
#define	M_SQRT2		1.41421356237309504880	/* sqrt(2) */
#define	M_SQRT1_2	0.70710678118654752440	/* 1/sqrt(2) */

#define	MAXFLOAT	((float)3.40282346638528860e+38)
#define HUGE_VAL	1e500			/* positive infinity */

extern int signgam;

double acos(double x) SYS_PURE;
double asin(double x) SYS_PURE;
double atan(double x) SYS_PURE;
double atan2(double y, double x) SYS_PURE;
double ceil(double x) SYS_PURE;
double cos(double x) SYS_PURE;
double cosh(double x) SYS_PURE;
double exp(double x) SYS_PURE;
double fabs(double x) SYS_PURE;
double floor(double x) SYS_PURE;
double fmod(double x, double y) SYS_PURE;
double frexp(double value, int *exp);
double ldexp(double value, int exp) SYS_PURE;
double log(double x) SYS_PURE;
double log10(double x) SYS_PURE;
double modf(double value, double *iptr);
double pow(double x, double y) SYS_PURE;
double sin(double x) SYS_PURE;
double sinh(double x) SYS_PURE;
double sqrt(double x) SYS_PURE;
double tan(double x) SYS_PURE;
double tanh(double x) SYS_PURE;

double erf(double x) SYS_PURE;
double erfc(double x) SYS_PURE;
double gamma(double x);
double hypot(double x, double y) SYS_PURE;
double j0(double x) SYS_PURE;
double j1(double x) SYS_PURE;
double jn(int n, double x) SYS_PURE;
double lgamma(double x);
double y0(double x) SYS_PURE;
double y1(double x) SYS_PURE;
double yn(int n, double x) SYS_PURE;
int isnan(double x) SYS_PURE;

double acosh(double x) SYS_PURE;
double asinh(double x) SYS_PURE;
double atanh(double x) SYS_PURE;
double cbrt(double x) SYS_PURE;
double expm1(double x) SYS_PURE;
int ilogb(double x) SYS_PURE;
double log1p(double x) SYS_PURE;
double logb(double x) SYS_PURE;
double nextafter(double x, double y) SYS_PURE;
double remainder(double x, double y) SYS_PURE;
double rint(double l) SYS_PURE;
double scalb(double x, double n) SYS_PURE;

#endif /* _C_MATH_H_ */