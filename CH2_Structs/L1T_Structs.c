// 3 sep 2025
// Structs

#include <stdio.h>
#include <munit.h>
#include "main_lib.h"
#include <math.h>



// Helper function for float comparisons with tolerance
static int float_equals(double a, double b, double tolerance) {
    return fabs(a - b) < tolerance;
}

static MunitResult test_new_coordinate1(const MunitParameter params[], void* data) {
    struct Coordinate c;
    c.x = 1;
    c.y = 2;
    c.z = 3;
    
    if (c.x != 1) {
        printf("FAIL: c.x = %d, expected 1\n", c.x);
        return MUNIT_FAIL;
    }
    printf("PASS: c.x = %d ✓\n", c.x);
    
    if (c.y != 2) {
        printf("FAIL: c.y = %d, expected 2\n", c.y);
        return MUNIT_FAIL;
    }
    printf("PASS: c.y = %d ✓\n", c.y);
    
    if (c.z != 3) {
        printf("FAIL: c.z = %d, expected 3\n", c.z);
        return MUNIT_FAIL;
    }
    printf("PASS: c.z = %d ✓\n", c.z);
    
    return MUNIT_OK;
}

static MunitResult test_new_coordinate2(const MunitParameter params[], void* data) {
    struct Coordinate c;
    c.x = 4;
    c.y = 2;
    c.z = 0;
    
    if (c.x != 4) {
        printf("FAIL: c.x = %d, expected 4\n", c.x);
        return MUNIT_FAIL;
    }
    printf("PASS: c.x = %d ✓\n", c.x);
    
    if (c.y != 2) {
        printf("FAIL: c.y = %d, expected 2\n", c.y);
        return MUNIT_FAIL;
    }
    printf("PASS: c.y = %d ✓\n", c.y);
    
    if (c.z != 0) {
        printf("FAIL: c.z = %d, expected 0\n", c.z);
        return MUNIT_FAIL;
    }
    printf("PASS: c.z = %d ✓\n", c.z);
    
    return MUNIT_OK;
}

static MunitResult test_new_coordinate3(const MunitParameter params[], void* data) {
    struct Coordinate c;
    c.x = 10;
    c.y = 20;
    c.z = 30;
    
    if (c.x != 10) {
        printf("FAIL: c.x = %d, expected 10\n", c.x);
        return MUNIT_FAIL;
    }
    printf("PASS: c.x = %d ✓\n", c.x);
    
    if (c.y != 20) {
        printf("FAIL: c.y = %d, expected 20\n", c.y);
        return MUNIT_FAIL;
    }
    printf("PASS: c.y = %d ✓\n", c.y);
    
    if (c.z != 30) {
        printf("FAIL: c.z = %d, expected 30\n", c.z);
        return MUNIT_FAIL;
    }
    printf("PASS: c.z = %d ✓\n", c.z);
    
    return MUNIT_OK;
}

static MunitResult test_new_coordinate4(const MunitParameter params[], void* data) {
    struct Coordinate c;
    c.x = 0;
    c.y = 6;
    c.z = 9;
    
    if (c.x != 0) {
        printf("FAIL: c.x = %d, expected 0\n", c.x);
        return MUNIT_FAIL;
    }
    printf("PASS: c.x = %d ✓\n", c.x);
    
    if (c.y != 6) {
        printf("FAIL: c.y = %d, expected 6\n", c.y);
        return MUNIT_FAIL;
    }
    printf("PASS: c.y = %d ✓\n", c.y);
    
    if (c.z != 9) {
        printf("FAIL: c.z = %d, expected 9\n", c.z);
        return MUNIT_FAIL;
    }
    printf("PASS: c.z = %d ✓\n", c.z);
    
    return MUNIT_OK;
}

int main() {
    MunitTest tests[] = {
        {"/create_coordinate1", test_new_coordinate1, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {"/create_coordinate2", test_new_coordinate2, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {"/create_coordinate3", test_new_coordinate3, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {"/create_coordinate4", test_new_coordinate4, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
        {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}  // null terminator
    };
    
    MunitSuite suite = {
        "coordinates",  // name
        tests,          // tests
        NULL,           // suites
        1,              // iterations
        MUNIT_SUITE_OPTION_NONE  // options
    };
    
    return munit_suite_main(&suite, NULL, 0, NULL);
}