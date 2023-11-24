#ifndef S21_MATH
#define S21_MATH

#include <stdio.h>

#define s21_POS_INF 1.0 / 0.0
#define s21_NEG_INF -1.0 / 0.0
#define s21_NAN 0.0 / 0.0
#define s21_EPS 1e-13
#define s21_LOG_10 2.30258509299
#define s21_LOG_2 0.69314718056
#define s21_MAX_double 1.7976931348623157e308
#define s21_PI 3.14159265358979324
#define s21_isfinite(x) __builtin_isfinite(x)

// Основные функции
int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

// Вспомогательные функции
long double calc_atan(double x);
long double check_int(double exp);
long double isNAN(double example);
long double to_range(double x);

#endif