#include "s21_math.h"

long double s21_sin(double x) {
  long double ans = 0;
  if (isNAN(x) || !s21_isfinite(x)) {
    ans = s21_NAN;
  } else {
    x = to_range(x);
    long double n = 1, sign = 1, ans1 = 2, npow = x, fac = 1;

    while (s21_fabs(s21_fabs(ans1) - s21_fabs(ans)) > s21_EPS) {
      ans1 = ans;
      ans += sign * npow / fac;
      sign *= -1;
      npow *= x * x;
      fac *= (2 * n) * (2 * n + 1);
      ++n;
    }
  }

  return ans;
}

long double to_range(double x) {
  long long int y = x / 2 / s21_PI;
  x = x - y * 2 * s21_PI - 2 * s21_PI;

  return x;
}
