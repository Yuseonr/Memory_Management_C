// 31/08/2025
// C Basics

#include <munit.h>
#include "main_lib.h"
#include <math.h>  // for fabs()
#include <stdio.h>


// Helper function to compare floats with tolerance
static int float_equals(float a, float b, float tolerance) {
    return fabs(a - b) < tolerance;
}

// Test function 1 - Returns FAIL instead of ERROR
static MunitResult test_snek_score_1(const MunitParameter params[], void* data) {
    float result = snek_score(3, 4, 5, 0.1);
    float expected = 1.9;
    float tolerance = 0.01;  // 2 decimal places tolerance
    
    if (!float_equals(result, expected, tolerance)) {
        printf("FAIL: snek_score(3, 4, 5, 0.1) = %.6f, expected %.6f\n", result, expected);
        return MUNIT_FAIL;  // Graceful failure, not abort
    }
    
    printf("PASS: snek_score(3, 4, 5, 0.1) = %.6f ✓\n", result);
    return MUNIT_OK;
}

// Test function 2 - Returns FAIL instead of ERROR
static MunitResult test_snek_score_2(const MunitParameter params[], void* data) {
    float result = snek_score(10, 10, 10, 0.1);
    float expected = 11.0;
    float tolerance = 0.01;
    
    if (!float_equals(result, expected, tolerance)) {
        printf("FAIL: snek_score(10, 10, 10, 0.1) = %.6f, expected %.6f\n", result, expected);
        return MUNIT_FAIL;
    }
    
    printf("PASS: snek_score(10, 10, 10, 0.1) = %.6f ✓\n", result);
    return MUNIT_OK;
}

// Test function 3 - Returns FAIL instead of ERROR
static MunitResult test_snek_score_3(const MunitParameter params[], void* data) {
    float result = snek_score(105, 205, 207, 0.1);
    float expected = 2194.0;
    float tolerance = 0.01;
    
    if (!float_equals(result, expected, tolerance)) {
        printf("FAIL: snek_score(105, 205, 207, 0.1) = %.6f, expected %.6f\n", result, expected);
        return MUNIT_FAIL;
    }
    
    printf("PASS: snek_score(105, 205, 207, 0.1) = %.6f ✓\n", result);
    return MUNIT_OK;
}

int main() {
    // Define test array
    MunitTest tests[] = {
        { "/test_snek_score_1", test_snek_score_1, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
        { "/test_snek_score_2", test_snek_score_2, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
        { "/test_snek_score_3", test_snek_score_3, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
        { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }  // Null terminator
    };

    // Define test suite
    MunitSuite suite = {
        "/snek_score_suite",           // Suite name
        tests,                         // Test array
        NULL,                          // Sub-suites
        1,                             // Iterations
        MUNIT_SUITE_OPTION_NONE       // Options
    };

    return munit_suite_main(&suite, NULL, 0, NULL);
}