// 3 sep 2025
// Structs

#include <stdio.h>
#include <munit.h>
#include "main_lib.h"
#include <math.h>

/* Helper function for float comparisons */
static int float_equals(double a, double b, double tolerance) {
  return fabs(a - b) < tolerance;
}

static MunitResult test_new_coordinate1(const MunitParameter params[], void* data) {
  struct Coordinate c = new_coord(1, 2, 3);

  if (c.x != 1) {
    printf("FAIL: new_coord(1,2,3).x = %d, expected %d\n", c.x, 1);
    return MUNIT_FAIL;
  }
  if (c.y != 2) {
    printf("FAIL: new_coord(1,2,3).y = %d, expected %d\n", c.y, 2);
    return MUNIT_FAIL;
  }
  if (c.z != 3) {
    printf("FAIL: new_coord(1,2,3).z = %d, expected %d\n", c.z, 3);
    return MUNIT_FAIL;
  }

  printf("PASS: new_coord(1,2,3) = (%d, %d, %d) ✓\n", c.x, c.y, c.z);
  return MUNIT_OK;
}

static MunitResult test_new_coordinate2(const MunitParameter params[], void* data) {
  struct Coordinate c = new_coord(4, 2, 0);

  if (c.x != 4) {
    printf("FAIL: new_coord(4,2,0).x = %d, expected %d\n", c.x, 4);
    return MUNIT_FAIL;
  }
  if (c.y != 2) {
    printf("FAIL: new_coord(4,2,0).y = %d, expected %d\n", c.y, 2);
    return MUNIT_FAIL;
  }
  if (c.z != 0) {
    printf("FAIL: new_coord(4,2,0).z = %d, expected %d\n", c.z, 0);
    return MUNIT_FAIL;
  }

  printf("PASS: new_coord(4,2,0) = (%d, %d, %d) ✓\n", c.x, c.y, c.z);
  return MUNIT_OK;
}

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
  MunitTest tests[] = {
    { "/create_coordinate1", test_new_coordinate1, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/create_coordinate2", test_new_coordinate2, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL } /* terminator */
  };

  MunitSuite suite = {
    "/coordinates", /* name */
    tests,          /* tests */
    NULL,           /* suites */
    1,              /* iterations */
    MUNIT_SUITE_OPTION_NONE
  };

  return munit_suite_main(&suite, NULL, argc, argv);
}
