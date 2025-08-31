// 31/08/2025
// C Basics

#include <stdio.h>
#include <munit.h>
#include <math.h>  // for fabs()
#include "main_lib.h"

// Helper function to compare floats with tolerance
static int float_equals(float a, float b, float tolerance) {
    return fabs(a - b) < tolerance;
}

// Test function 1 - Returns FAIL instead of ERROR
static MunitResult test_get_average(const MunitParameter params[], void* data) {
    float result = get_average(3, 4, 5);
    float expected = 4.0;
    float tolerance = 0.01;  // 2 decimal places tolerance
    
    if (!float_equals(result, expected, tolerance)) {
        printf("FAIL: get_average(3, 4, 5) = %.6f, expected %.6f\n", result, expected);
        return MUNIT_FAIL;  // Graceful failure, not abort
    }
    
    printf("PASS: get_average(3, 4, 5) = %.6f ✓\n", result);
    return MUNIT_OK;
}

// Test function 2 - Returns FAIL instead of ERROR
static MunitResult test_non_integer(const MunitParameter params[], void* data) {
    float result = get_average(3, 3, 5);
    float expected = 11.0 / 3.0;
    float tolerance = 0.01;
    
    if (!float_equals(result, expected, tolerance)) {
        printf("FAIL: get_average(3, 3, 5) = %.6f, expected %.6f\n", result, expected);
        return MUNIT_FAIL;
    }
    
    printf("PASS: get_average(3, 3, 5) = %.6f ✓\n", result);
    return MUNIT_OK;
}

// Test function 3 - Returns FAIL instead of ERROR
static MunitResult test_average_of_same(const MunitParameter params[], void* data) {
    float result = get_average(10, 10, 10);
    float expected = 10.0;
    float tolerance = 0.01;
    
    if (!float_equals(result, expected, tolerance)) {
        printf("FAIL: get_average(10, 10, 10) = %.6f, expected %.6f\n", result, expected);
        return MUNIT_FAIL;
    }
    
    printf("PASS: get_average(10, 10, 10) = %.6f ✓\n", result);
    return MUNIT_OK;
}

// Test function 4 - Returns FAIL instead of ERROR
static MunitResult test_average_of_big_numbers(const MunitParameter params[], void* data) {
    float result = get_average(1050, 2050, 2075);
    float expected = 1725.0;
    float tolerance = 0.01;
    
    if (!float_equals(result, expected, tolerance)) {
        printf("FAIL: get_average(1050, 2050, 2075) = %.6f, expected %.6f\n", result, expected);
        return MUNIT_FAIL;
    }
    
    printf("PASS: get_average(1050, 2050, 2075) = %.6f ✓\n", result);
    return MUNIT_OK;
}

// Example of a test that would show ERROR (real runtime error)
static MunitResult test_with_real_error(const MunitParameter params[], void* data) {
    // This would cause ERROR if uncommented:
    // int *p = NULL;
    // *p = 42;  // Segmentation fault - real ERROR
    
    // For now, just return OK
    printf("PASS: No real errors here ✓\n");
    return MUNIT_OK;
}

int main() {
    // Define test array
    MunitTest tests[] = {
        { "/get_average", test_get_average, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
        { "/get_average_float", test_non_integer, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
        { "/get_average_same", test_average_of_same, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
        { "/get_average_big", test_average_of_big_numbers, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
        { "/no_error", test_with_real_error, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
        { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }  // Terminator
    };

    // Define test suite
    MunitSuite suite = {
        "/get_average_suite",  // Suite name
        tests,                 // Test array
        NULL,                  // Sub-suites
        1,                     // Iterations
        MUNIT_SUITE_OPTION_NONE // Options
    };

    return munit_suite_main(&suite, NULL, 0, NULL);
}