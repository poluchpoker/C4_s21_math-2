#include "s21_math.h"

long double s21_log(double x) {
  long double res = 0;
  if (x < 0)
    res = s21_NAN;
  else if (x == s21_POS_INF || x == s21_NEG_INF)
    res = x;
  else if (isNAN(x))
    res = s21_NAN;
  else if (x == 0.0) {
    res = s21_NEG_INF;
  } else {
    int power_adj = 0;

    if (x > 2.0) {
      while (x > 1.0) {
        x /= 10;
        power_adj++;
      }
    } else if (x < 1.0) {
      while (x < 1.0) {
        x *= 10;
        power_adj--;
      }
    }

    int div = 0;

    while (x >= 2) {
      x /= 2;
      div++;
    }

    res = power_adj * s21_LOG_10 + div * s21_LOG_2;

    long double z = x - 1, buf = 1, log_n = 0;
    int position = 1, sign = 1;

    while (s21_fabs(buf) > s21_EPS) {
      buf *= z;
      log_n += sign * buf / position;
      position++;
      sign *= -1;
    }
    res += log_n;
  }

  return res;
}