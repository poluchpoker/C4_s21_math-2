#include "s21_math.h"

long double s21_acos(double x) {
  long double result = s21_NAN;

  if (s21_fabs(-1.0 - x) < s21_EPS) {
    result = s21_PI;
  } else if (s21_fabs(x - 1) < s21_EPS) {
    result = 0;
  } else if (x > -1.0 && x < 1.0) {
    result = s21_PI / 2 - s21_asin(x);
  }

  return result;
}