#include "s21_math.h"

long double s21_asin(double x) {
  long double res = 0;
  if (isNAN(x) || (x > 1) || (x < -1) || (x == s21_NEG_INF) ||
      (x == s21_POS_INF)) {
    res = s21_NAN;
  } else {
    res = s21_atan(x / s21_sqrt(1 - x * x));
  }

  return res;
}
