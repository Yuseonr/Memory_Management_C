// 3 sep 2025
// Structs

#include <stdio.h>
#include <munit.h>
#include "main_lib.h"
#include <math.h>

/* Helper for float comparisons (not used in these int tests, but ready if needed) */
static int float_equals(double a, double b, double tolerance) {
  return fabs(a - b) < tolerance;
}

static MunitResult test_new_coordinate(const MunitParameter params[], void* data) {
  struct Coordinate c;
  c.x = 1;
  c.y = 2;
  c.z = 3;

  if (c.x != 1) {
    printf("FAIL: new_coord manual init .x = %d, expected %d\n", c.x, 1);
    return MUNIT_FAIL;
  }
  if (c.y != 2) {
    printf("FAIL: new_coord manual init .y = %d, expected %d\n", c.y, 2);
    return MUNIT_FAIL;
  }
  if (c.z != 3) {
    printf("FAIL: new_coord manual init .z = %d, expected %d\n", c.z, 3);
    return MUNIT_FAIL;
  }

  printf("PASS: new_coord manual init = (%d, %d, %d) ✓\n", c.x, c.y, c.z);
  return MUNIT_OK;
}

static MunitResult test_scale_coordinate1(const MunitParameter params[], void* data) {
  struct Coordinate c = new_coord(1, 2, 3);
  struct Coordinate scaled = scale_coordinate(c, 2);

  if (scaled.x != 2) {
    printf("FAIL: scale_coordinate((1,2,3),2).x = %d, expected %d\n", scaled.x, 2);
    return MUNIT_FAIL;
  }
  if (scaled.y != 4) {
    printf("FAIL: scale_coordinate((1,2,3),2).y = %d, expected %d\n", scaled.y, 4);
    return MUNIT_FAIL;
  }
  if (scaled.z != 6) {
    printf("FAIL: scale_coordinate((1,2,3),2).z = %d, expected %d\n", scaled.z, 6);
    return MUNIT_FAIL;
  }

  printf("PASS: scale_coordinate((1,2,3),2) = (%d, %d, %d) ✓\n", scaled.x, scaled.y, scaled.z);
  return MUNIT_OK;
}

static MunitResult test_scale_coordinate2(const MunitParameter params[], void* data) {
  struct Coordinate c = new_coord(4, 2, 0);
  struct Coordinate scaled = scale_coordinate(c, 2);

  if (scaled.x != 8) {
    printf("FAIL: scale_coordinate((4,2,0),2).x = %d, expected %d\n", scaled.x, 8);
    return MUNIT_FAIL;
  }
  if (scaled.y != 4) {
    printf("FAIL: scale_coordinate((4,2,0),2).y = %d, expected %d\n", scaled.y, 4);
    return MUNIT_FAIL;
  }
  if (scaled.z != 0) {
    printf("FAIL: scale_coordinate((4,2,0),2).z = %d, expected %d\n", scaled.z, 0);
    return MUNIT_FAIL;
  }

  printf("PASS: scale_coordinate((4,2,0),2) = (%d, %d, %d) ✓\n", scaled.x, scaled.y, scaled.z);
  return MUNIT_OK;
}

static MunitResult test_original_unchanged(const MunitParameter params[], void* data) {
  struct Coordinate c = new_coord(1, 2, 3);
  struct Coordinate scaled = scale_coordinate(c, 2);

  if (c.x != 1) {
    printf("FAIL: original c.x changed = %d, expected %d\n", c.x, 1);
    return MUNIT_FAIL;
  }
  if (c.y != 2) {
    printf("FAIL: original c.y changed = %d, expected %d\n", c.y, 2);
    return MUNIT_FAIL;
  }
  if (c.z != 3) {
    printf("FAIL: original c.z changed = %d, expected %d\n", c.z, 3);
    return MUNIT_FAIL;
  }

  printf("PASS: original c unchanged after scale = (%d, %d, %d) ✓\n", c.x, c.y, c.z);
  return MUNIT_OK;
}

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
  MunitTest tests[] = {
    { "/create_coordinate", test_new_coordinate, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_scale_coordinate1", test_scale_coordinate1, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_scale_coordinate2", test_scale_coordinate2, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_original_unchanged", test_original_unchanged, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
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
