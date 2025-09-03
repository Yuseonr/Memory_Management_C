// 3 sep 2025
// Structs

#include <stdio.h>
#include <munit.h>
#include "main_lib.h"
#include <math.h>

/* Helper for float comparisons */
static int float_equals(double a, double b, double tolerance) {
  return fabs(a - b) < tolerance;
}

static MunitResult test_optimal_size(const MunitParameter params[], void* data) {
  size_t result = sizeof(sneklang_var_t);
  size_t expected = 24;

  if (result != expected) {
    printf("FAIL: sizeof(sneklang_var_t) = %zu, expected %zu\n", result, expected);
    return MUNIT_FAIL;
  }

  printf("PASS: sizeof(sneklang_var_t) = %zu ✓\n", result);
  return MUNIT_OK;
}

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
  MunitTest tests[] = {
    { "/test_optimal_size", test_optimal_size, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL } /* null terminator */
  };

  MunitSuite suite = {
    "/padding",     /* name */
    tests,          /* tests */
    NULL,           /* suites */
    1,              /* iterations */
    MUNIT_SUITE_OPTION_NONE
  };

  return munit_suite_main(&suite, NULL, argc, argv);
}
