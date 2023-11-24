#include "s21_math.h"

long double s21_sqrt(double x) {
  long double cur = x;
  if (x < 0 || isNAN(x)) {
    cur = s21_NAN;
  } else if (x == 0 || x == s21_POS_INF) {
    cur = x;
  } else {
    long double res = 4;
    long double tmp = 0;
    while (s21_fabs(res - tmp) > s21_EPS) {
      tmp = res;
      res = (x / tmp + tmp) / 2;
    }

    cur = res;
  }

  return cur;
}