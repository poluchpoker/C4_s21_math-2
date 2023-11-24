#include "s21_math.h"

long double s21_ceil(double x) {
  long double result = 0;
  if (x == s21_POS_INF)
    result = s21_POS_INF;
  else if (x == s21_NEG_INF)
    result = s21_NEG_INF;
  else if (!isNAN(x)) {
    result = (long double)(long long int)x;
    if (result < x) result += 1;
  } else {
    result = -1 * x;
  }

  return result;
}
