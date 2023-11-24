#include "s21_math.h"

long double s21_cos(double x) {
  long double ans = 0;
  if (isNAN(x) || !s21_isfinite(x))
    ans = s21_NAN;
  else {
    x = to_range(x);
    long double n = 1, sign = 1, ans0 = 2, npow = 1, fac = 1;
    while (s21_fabs(s21_fabs(ans0) - s21_fabs(ans)) > s21_EPS) {
      ans0 = ans;
      ans += sign * npow / fac;
      sign *= -1;
      npow *= x * x;
      fac *= (2 * n - 1) * (2 * n);
      ++n;
    }
  }
  return ans;
}
