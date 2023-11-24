#include "s21_math.h"

long double s21_atan(double x) {
  long double res = 0;
  if (x < 1.0 && x > -1.0) {
    res = calc_atan(x);
  } else if (x > 1.) {
    res = s21_PI / 2. - calc_atan(1 / x);
  } else if (x < -1.) {
    res = -s21_PI / 2. - calc_atan(1 / x);
  } else if (x == 1.) {
    res = s21_PI / 4.;
  } else if (x == -1.) {
    res = -s21_PI / 4.;
  } else if (isNAN(x)) {
    res = s21_NAN;
  }

  return res;
}

long double calc_atan(double x) {
  long double sum = x, tmp = x, count = 1, temp_a = tmp;

  while (s21_fabs(temp_a) > s21_EPS && count < 10000) {
    temp_a = s21_pow(-1, count) * s21_pow(tmp, 2 * count + 1) / (2 * count + 1);
    sum += temp_a;
    count++;
  }

  return sum;
}