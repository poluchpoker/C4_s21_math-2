#include "s21_math.h"

long double s21_exp(double x) {
  long double res = 1.;

  if (isNAN(x)) {
    res = s21_NAN;
  } else if (x == s21_POS_INF) {
    res = s21_POS_INF;
  } else if (x == s21_NEG_INF) {
    res = s21_NAN;
  } else if (x == 0) {
    res = 1;
  } else {
    long double count = 1.;
    int sign = 0;

    if (x < 0) {
      sign = 1;
      x *= -1;
    }

    long double element = (long double)x;

    for (int position = 1; s21_fabs(count / res) > s21_EPS; position++) {
      count = count * element / position;
      res += count;
      if (res > s21_MAX_double) {
        res = s21_POS_INF;
        break;
      }
    }

    if (sign) {
      res = 1. / res;
    }
  }

  return res;
}
