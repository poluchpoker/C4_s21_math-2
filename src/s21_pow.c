#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double result = 1;

  if (base == 1 || exp == 0 || (base == -1 && (exp == s21_POS_INF))) {
    result = 1;
  } else if ((s21_fabs(base) < 1 && exp == s21_NEG_INF) ||
             (s21_fabs(base) > 1 && exp == s21_POS_INF) ||
             (base == s21_NEG_INF &&
              ((exp > 0 && (int)exp % 2 == 0) || exp == s21_POS_INF)) ||
             (base == s21_POS_INF && exp > 0)) {
    result = s21_POS_INF;
  } else if (base == s21_NEG_INF && exp == s21_NEG_INF) {
    result = 0;
  } else if ((base < 0 && isNAN(exp)) || (isNAN(base) && isNAN(exp)) ||
             (base < 0 && exp < 0)) {
    result = s21_NAN;
  } else if ((base == 0 && exp > 0) || (base == s21_NEG_INF && exp < 0) ||
             (s21_fabs(base) > 1 && exp == s21_NEG_INF) ||
             (s21_fabs(base) < 1 && exp == s21_POS_INF) ||
             (base == s21_NEG_INF && (exp < 0 && (int)exp % 2 == 0))) {
    result = 0;
  } else if (base == s21_NEG_INF && (exp > 0 && (int)exp % 2 != 0)) {
    result = s21_NEG_INF;
  } else {
    if (check_int(exp)) {
      if (exp > 0) {
        while (exp-- >= 1) {
          result *= base;
        }
      } else {
        while (exp++ <= -1) {
          result /= base;
        }
      }
    } else {
      result = s21_exp(exp * s21_log(s21_fabs(base)));
    }
  }

  return result;
}

long double check_int(double exp) {
  long long int x = exp;

  return (x == exp) ? 1 : 0;
}
