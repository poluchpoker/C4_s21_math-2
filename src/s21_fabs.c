#include "s21_math.h"

long double s21_fabs(double x) {
  if (isNAN(x))
    x = s21_NAN;
  else if (x == s21_POS_INF || x == s21_NEG_INF)
    x = s21_POS_INF;
  else if (x < 0)
    x *= -1;

  return x;
}
