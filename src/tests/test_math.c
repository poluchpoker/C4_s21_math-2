#include "mainTest.h"

START_TEST(s21_abs_test) {
  ck_assert_int_eq(s21_abs(0), abs(0));
  ck_assert_int_eq(s21_abs(2147483647), abs(2147483647));
  ck_assert_int_eq(s21_abs(-2147483647), abs(-2147483647));
}
END_TEST

START_TEST(s21_acos_test) {
  // проверка внутренних значений от -1 до 1
  for (double x = -1; x < 1; x += 0.1) {
    ck_assert_ldouble_eq_tol(s21_acos(x), acos(x), 1e-6);
  }

  // проверка справа и слева от границы
  ck_assert_ldouble_nan(s21_acos(1.01));
  ck_assert_ldouble_nan(s21_acos(-1.01));

  // проверка особых случаев
  ck_assert_ldouble_nan(s21_acos(s21_NAN));
  ck_assert_ldouble_nan(s21_acos(s21_POS_INF));
  ck_assert_ldouble_nan(s21_acos(s21_NEG_INF));

  // табличные значения
  ck_assert_ldouble_eq_tol(s21_acos(-1.), acos(-1.), s21_EPS);
  ck_assert_ldouble_eq_tol(s21_acos(-0.866025), acos(-0.866025), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-1. / 2.), acos(-1. / 2.), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(1. / 2.), acos(1. / 2.), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0.43), acos(0.43), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos((s21_sqrt(3.) / 2.)),
                           acos((s21_sqrt(3.) / 2.)), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(1.), acos(1.), 1e-6);
}
END_TEST

START_TEST(s21_asin_test) {
  // проверка внутренних значений от -1 до 1
  for (double x = -1; x < 1; x += 0.1) {
    ck_assert_ldouble_eq_tol(s21_asin(x), asin(x), 1e-6);
  }

  // проверка справа и слева от границы
  ck_assert_ldouble_nan(s21_asin(1.01));
  ck_assert_ldouble_nan(s21_asin(-1.01));

  // проверка особых случаев
  ck_assert_ldouble_nan(s21_asin(s21_NAN));
  ck_assert_ldouble_nan(s21_asin(s21_POS_INF));
  ck_assert_ldouble_nan(s21_asin(s21_NEG_INF));

  // табличные значения
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-1 * (s21_sqrt(3) / 2)),
                           asin(-1 * (s21_sqrt(3) / 2)), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-0.123), asin(-0.123), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-1 / 2), asin(-1 / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(1 / 2), asin(1 / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0.123), asin(0.123), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin((s21_sqrt(3) / 2)), asin((s21_sqrt(3) / 2)),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), 1e-6);
}
END_TEST

START_TEST(s21_atan_test) {
  // прогонка значений
  for (double x = -0.9; x < 0.9; x += 0.1) {
    ck_assert_ldouble_eq_tol(s21_atan(x), atan(x), 1e-6);
  }

  // проверка особых случаев
  ck_assert_ldouble_nan(s21_atan(s21_NAN));
  ck_assert_ldouble_eq_tol(s21_atan(s21_POS_INF), atan(s21_POS_INF), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(s21_NEG_INF), atan(s21_NEG_INF), 1e-6);

  // проверка табличных значений
  ck_assert_ldouble_eq_tol(s21_atan(-1 * s21_sqrt(3)), atan(-1 * s21_sqrt(3)),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-1 / s21_sqrt(3)), atan(-1 / s21_sqrt(3)),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(1 / s21_sqrt(3)), atan(1 / s21_sqrt(3)),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(s21_sqrt(3)), atan(s21_sqrt(3)), 1e-6);
}
END_TEST

START_TEST(s21_ceil_test) {
  // проверка значений
  ck_assert_ldouble_eq_tol(s21_ceil(0), ceil(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(0.0000000000001), ceil(0.0000000000001),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(-0.0000000000001), ceil(-0.0000000000001),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(1.5), ceil(1.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(-1.5), ceil(-1.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(1.3435), ceil(1.3435), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(-1.3435), ceil(-1.3435), 1e-6);

  // особые случаи
  ck_assert_ldouble_nan(s21_ceil(s21_NAN));
  ck_assert_ldouble_infinite(s21_ceil(s21_POS_INF));
  ck_assert_ldouble_infinite(s21_ceil(s21_NEG_INF));
}
END_TEST

START_TEST(s21_cos_test) {
  // табличные значения
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(s21_PI / 6), cos(s21_PI / 6), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(s21_PI / 4), cos(s21_PI / 4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(s21_PI / 3), cos(s21_PI / 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(s21_PI / 2), cos(s21_PI / 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(s21_PI), cos(s21_PI), 1e-6);

  // особые случаи
  ck_assert_ldouble_nan(s21_cos(s21_NAN));
  ck_assert_ldouble_nan(s21_cos(s21_POS_INF));
  ck_assert_ldouble_nan(s21_cos(s21_NEG_INF));

  // проверка значений
  ck_assert_ldouble_eq_tol(s21_cos(1), cos(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-0.4), cos(-0.4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(0.4), cos(0.4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(10.1), cos(10.1), 1e-6);
}
END_TEST

START_TEST(s21_exp_test) {
  // проверка значений
  ck_assert_ldouble_eq_tol(s21_exp(0), exp(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(1), exp(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(0.23423476), exp(0.23423476), 1e-6);
  ck_assert_ldouble_infinite(s21_exp(900000));
  ck_assert_ldouble_eq_tol(s21_exp(-10), exp(-10), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-0.125), exp(-0.125), 1e-6);

  // особые случаи
  ck_assert_ldouble_nan(s21_exp(s21_NAN));
  ck_assert_ldouble_infinite(s21_exp(s21_POS_INF));
  ck_assert_ldouble_nan(s21_exp(s21_NEG_INF));
}
END_TEST

START_TEST(s21_fabs_test) {
  // проверка значений
  ck_assert_ldouble_eq_tol(s21_fabs(0.0), fabs(0.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(-1.021394), fabs(-1.021394), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(150000.0), fabs(150000.0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(-150000.1), fabs(-150000.1), 1e-6);

  // особые случаи
  ck_assert_ldouble_nan(s21_fabs(s21_NAN));
  ck_assert_ldouble_infinite(s21_fabs(s21_POS_INF));
  ck_assert_ldouble_infinite(s21_fabs(s21_NEG_INF));
}
END_TEST

START_TEST(s21_floor_test) {
  // особые случаи
  ck_assert_ldouble_nan(s21_floor(s21_NAN));
  ck_assert_ldouble_infinite(s21_floor(s21_POS_INF));
  ck_assert_ldouble_infinite(s21_floor(s21_NEG_INF));

  // проверка значений
  ck_assert_ldouble_eq_tol(s21_floor(0), floor(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_floor(0.0000000000001), floor(0.0000000000001),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_floor(-0.0000000000001), floor(-0.0000000000001),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_floor(1.5), floor(1.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_floor(-1.5), floor(-1.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_floor(1.3435), floor(1.3435), 1e-6);
  ck_assert_ldouble_eq_tol(s21_floor(-1.3435), floor(-1.3435), 1e-6);
}
END_TEST

START_TEST(s21_fmod_test) {
  // // Особые случаи
  ck_assert_ldouble_nan(s21_fmod(s21_POS_INF, s21_POS_INF));
  ck_assert_ldouble_nan(s21_fmod(s21_POS_INF, s21_NEG_INF));
  ck_assert_ldouble_nan(s21_fmod(s21_NEG_INF, s21_NEG_INF));
  ck_assert_ldouble_nan(s21_fmod(s21_NAN, s21_NAN));
  ck_assert_ldouble_nan(s21_fmod(s21_NAN, s21_POS_INF));
  ck_assert_ldouble_nan(s21_fmod(s21_NAN, s21_NEG_INF));
  ck_assert_ldouble_nan(s21_fmod(s21_POS_INF, s21_NAN));
  ck_assert_ldouble_nan(s21_fmod(s21_NEG_INF, s21_NAN));
  ck_assert_ldouble_nan(s21_fmod(2, 1e-16));

  // Проверка значений
  ck_assert_ldouble_eq_tol(s21_fmod(1.5, 5.), fmod(1.5, 5.), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(-1.5, 5.), fmod(-1.5, 5.), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(0.1, 5.), fmod(0.1, 5.), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(5., 5.), fmod(5., 5.), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(5., -2), fmod(5., -2), 1e-6);
}
END_TEST

START_TEST(s21_log_test) {
  // Граничные значения (в рамках задания 6 знаков после запятой)
  ck_assert_ldouble_eq_tol(s21_log(0.000001), log(0.000001), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(0.0000001), log(0.0000001), 1e-6);
  ck_assert_ldouble_nan(s21_log(-0.000001));
  ck_assert_ldouble_nan(s21_log(-0.0000001));

  // Особые случаи
  ck_assert_ldouble_nan(s21_log(s21_NAN));
  ck_assert_ldouble_infinite(s21_log(s21_POS_INF));
  ck_assert_ldouble_nan(s21_log(s21_NEG_INF));

  // Проверка значений
  ck_assert_ldouble_infinite(s21_log(0.));
  ck_assert_ldouble_eq_tol(s21_log(1.), log(1.), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(s21_exp(1.)), log(s21_exp(1.)), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(5.75), log(5.75), 1e-6);
}
END_TEST

START_TEST(s21_pow_test) {
  // Граничные значения (в рамках задания 6 знаков после запятой)
  ck_assert_ldouble_eq_tol(s21_pow(0.000001, 0.000001), pow(0.000001, 0.000001),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0.0000001, 0.0000001),
                           pow(0.0000001, 0.0000001), 1e-6);
  ck_assert_ldouble_nan(s21_pow(-0.000001, -0.000001));
  ck_assert_ldouble_nan(s21_pow(-0.0000001, -0.0000001));
  ck_assert_ldouble_eq_tol(s21_pow(1231241414, 0), pow(1231241414, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(1231.52, -21.2), pow(1231.52, -21.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(1231.52, -21), pow(1231.52, -21), 1e-6);

  // Особые случаи
  ck_assert_ldouble_eq_tol(s21_pow(s21_NEG_INF, 0), pow(s21_NEG_INF, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(s21_POS_INF, 0), pow(s21_POS_INF, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(s21_NAN, 0), pow(s21_NAN, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0, 0), pow(0, 0), 1e-6);

  ck_assert_ldouble_eq_tol(s21_pow(s21_NEG_INF, s21_NEG_INF),
                           pow(s21_NEG_INF, s21_NEG_INF), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(s21_POS_INF, s21_NEG_INF),
                           pow(s21_POS_INF, s21_NEG_INF), 1e-6);
  ck_assert_ldouble_nan(s21_pow(s21_NAN, s21_NEG_INF));
  ck_assert_ldouble_infinite(s21_pow(0, s21_NEG_INF));

  ck_assert_ldouble_infinite(s21_pow(s21_NEG_INF, s21_POS_INF));
  ck_assert_ldouble_infinite(s21_pow(s21_POS_INF, s21_POS_INF));
  ck_assert_ldouble_nan(s21_pow(s21_NAN, s21_POS_INF));
  ck_assert_ldouble_eq_tol(s21_pow(0, s21_POS_INF), pow(0, s21_POS_INF), 1e-6);

  ck_assert_ldouble_nan(s21_pow(s21_NEG_INF, s21_NAN));
  ck_assert_ldouble_nan(s21_pow(s21_POS_INF, s21_NAN));
  ck_assert_ldouble_nan(s21_pow(s21_NAN, s21_NAN));
  ck_assert_ldouble_nan(s21_pow(0, s21_NAN));

  ck_assert_ldouble_eq_tol(s21_pow(1, 0), pow(1, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(1, s21_NAN), pow(1, s21_NAN), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(1, s21_POS_INF), pow(1, s21_POS_INF), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(1, s21_NEG_INF), pow(1, s21_NEG_INF), 1e-6);

  ck_assert_ldouble_infinite(s21_pow(s21_NEG_INF, 3));
}
END_TEST

START_TEST(s21_sin_test) {
  // Граничные значения (в рамках задания 6 знаков после запятой)
  ck_assert_ldouble_eq_tol(s21_sin(0.000001), sin(0.000001), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0.0000001), sin(0.0000001), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-0.000001), sin(-0.000001), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-0.0000001), sin(-0.0000001), 1e-6);

  // Особые случаи
  ck_assert_ldouble_nan(s21_sin(s21_NAN));
  ck_assert_ldouble_nan(s21_sin(s21_POS_INF));
  ck_assert_ldouble_nan(s21_sin(s21_NEG_INF));

  // табличные значения
  ck_assert_ldouble_eq_tol(s21_sin(0.), sin(0.), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(s21_PI / 6.), sin(s21_PI / 6.), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(s21_PI / 4.), sin(s21_PI / 4.), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(s21_PI / 3.), sin(s21_PI / 3.), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(s21_PI / 2.), sin(s21_PI / 2.), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(s21_PI), sin(s21_PI), 1e-6);

  // проверка значений
  ck_assert_ldouble_eq_tol(s21_sin(1.), sin(1.), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-0.4), sin(-0.4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0.4), sin(0.4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(10.1), sin(10.1), 1e-6);
}
END_TEST

START_TEST(s21_sqrt_test) {
  // Граничные значения (в рамках задания 6 знаков после запятой)
  ck_assert_ldouble_eq_tol(s21_sqrt(0.000001), sqrt(0.000001), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(0.0000001), sqrt(0.0000001), 1e-6);
  ck_assert_ldouble_nan(s21_sqrt(-0.000001));
  ck_assert_ldouble_nan(s21_sqrt(-0.0000001));

  // Особые случаи
  ck_assert_ldouble_nan(s21_sqrt(s21_NAN));
  ck_assert_ldouble_infinite(s21_sqrt(s21_POS_INF));
  ck_assert_ldouble_nan(s21_sqrt(s21_NEG_INF));

  // Проверка значений
  ck_assert_ldouble_nan(s21_sqrt(-1.));
  ck_assert_ldouble_eq_tol(s21_sqrt(0.), sqrt(0.), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(4.), sqrt(4.), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(1.25), sqrt(1.25), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(6.25), sqrt(6.25), 1e-6);
}
END_TEST

START_TEST(s21_tan_test) {
  // Граничные значения (в рамках задания 6 знаков после запятой)
  ck_assert_ldouble_eq_tol(s21_tan(0.000001), tan(0.000001), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(0.0000001), tan(0.0000001), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-0.000001), tan(-0.000001), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-0.0000001), tan(-0.0000001), 1e-6);

  // Особые случаи
  ck_assert_ldouble_nan(s21_tan(s21_NAN));
  ck_assert_ldouble_nan(s21_tan(s21_POS_INF));
  ck_assert_ldouble_nan(s21_tan(s21_NEG_INF));
  ck_assert_ldouble_eq_tol(s21_tan(s21_PI / 2.), tan(s21_PI / 2.), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-s21_PI / 2.), tan(-s21_PI / 2.), 1e-6);

  // табличные значения
  ck_assert_ldouble_eq_tol(s21_tan(0.), tan(0.), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(s21_PI / 6.), tan(s21_PI / 6.), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(s21_PI / 4.), tan(s21_PI / 4.), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(s21_PI / 3.), tan(s21_PI / 3.), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(s21_PI), tan(s21_PI), 1e-6);

  // проверка значений
  ck_assert_ldouble_eq_tol(s21_tan(1.), tan(1.), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-0.4), tan(-0.4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(0.4), tan(0.4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(10.1), tan(10.1), 1e-6);
}
END_TEST

Suite *test_suite(void) {
  Suite *s = suite_create("TEST MATH");

  TCase *abs_tests = tcase_create("ABS");
  tcase_add_test(abs_tests, s21_abs_test);
  suite_add_tcase(s, abs_tests);

  TCase *acos_test = tcase_create("ACOS");
  tcase_add_test(acos_test, s21_acos_test);
  suite_add_tcase(s, acos_test);

  TCase *asin_test = tcase_create("ASIN");
  tcase_add_test(asin_test, s21_asin_test);
  suite_add_tcase(s, asin_test);

  TCase *atan_test = tcase_create("ATAN");
  tcase_add_test(atan_test, s21_atan_test);
  suite_add_tcase(s, atan_test);

  TCase *ceil_test = tcase_create("CEIL");
  tcase_add_test(ceil_test, s21_ceil_test);
  suite_add_tcase(s, ceil_test);

  TCase *cos_tests = tcase_create("COS");
  tcase_add_test(cos_tests, s21_cos_test);
  suite_add_tcase(s, cos_tests);

  TCase *exp_tests = tcase_create("EXP");
  tcase_add_test(exp_tests, s21_exp_test);
  suite_add_tcase(s, exp_tests);

  TCase *fabs_tests = tcase_create("FABS");
  tcase_add_test(fabs_tests, s21_fabs_test);
  suite_add_tcase(s, fabs_tests);

  TCase *floor_test = tcase_create("FLOOR");
  tcase_add_test(floor_test, s21_floor_test);
  suite_add_tcase(s, floor_test);

  TCase *fmod_test = tcase_create("FMOD");
  tcase_add_test(fmod_test, s21_fmod_test);
  suite_add_tcase(s, fmod_test);

  TCase *log_test = tcase_create("LOG");
  tcase_add_test(log_test, s21_log_test);
  suite_add_tcase(s, log_test);

  TCase *pow_test = tcase_create("POW");
  tcase_add_test(pow_test, s21_pow_test);
  suite_add_tcase(s, pow_test);

  TCase *sin_test = tcase_create("SIN");
  tcase_add_test(sin_test, s21_sin_test);
  suite_add_tcase(s, sin_test);

  TCase *sqrt_test = tcase_create("SQRT");
  tcase_add_test(sqrt_test, s21_sqrt_test);
  suite_add_tcase(s, sqrt_test);

  TCase *tan_test = tcase_create("TAN");
  tcase_add_test(tan_test, s21_tan_test);
  suite_add_tcase(s, tan_test);

  return s;
}

int main() {
  Suite *s = test_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int fail = srunner_ntests_failed(runner);
  srunner_free(runner);
  return fail ? EXIT_FAILURE : EXIT_SUCCESS;
}