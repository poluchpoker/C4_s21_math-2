#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double ans = 0, min_flag = 0;

  if ((x == s21_POS_INF) || (x == s21_NEG_INF)) {
    ans = s21_NAN;
  } else if (s21_fabs(y) < s21_EPS) {
    ans = s21_NAN;
  } else if ((y == s21_POS_INF) || (y == s21_NEG_INF)) {
    ans = x;
  } else {
    if (y < 0) {
      y *= -1;
    }
    if (x < 0) {
      x *= -1;
      min_flag = 1;
    }
    if (min_flag) {
      ans = -1 * (x - y * (long long int)(x / y));
    } else {
      ans = x - y * (long long int)(x / y);
    }
  }

  return ans;
}
