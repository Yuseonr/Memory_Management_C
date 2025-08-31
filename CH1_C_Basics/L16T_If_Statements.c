// 31/08/2025
// C Basics

#include <munit.h>
#include "main_lib.h"
#include <stdio.h>
#include <string.h>  // for strcmp()


// Helper function to compare strings
static int string_equals(const char* actual, const char* expected) {
    if (actual == NULL && expected == NULL) return 1;
    if (actual == NULL || expected == NULL) return 0;
    return strcmp(actual, expected) == 0;
}

// Test function 1 - Returns FAIL instead of ERROR
static MunitResult test_cold(const MunitParameter params[], void* data) {
    char *result = get_temperature_status(50);
    const char *expected = "too cold";
    
    if (!string_equals(result, expected)) {
        printf("FAIL: get_temperature_status(50) = \"%s\", expected \"%s\"\n", 
               result ? result : "NULL", expected);
        return MUNIT_FAIL;  // Graceful failure, not abort
    }
    
    printf("PASS: get_temperature_status(50) = \"%s\" ✓\n", result);
    return MUNIT_OK;
}

// Test function 2 - Returns FAIL instead of ERROR
static MunitResult test_hot(const MunitParameter params[], void* data) {
    char *result = get_temperature_status(100);
    const char *expected = "too hot";
    
    if (!string_equals(result, expected)) {
        printf("FAIL: get_temperature_status(100) = \"%s\", expected \"%s\"\n", 
               result ? result : "NULL", expected);
        return MUNIT_FAIL;
    }
    
    printf("PASS: get_temperature_status(100) = \"%s\" ✓\n", result);
    return MUNIT_OK;
}

// Test function 3 - Returns FAIL instead of ERROR
static MunitResult test_just_right(const MunitParameter params[], void* data) {
    char *result = get_temperature_status(70);
    const char *expected = "just right";
    
    if (!string_equals(result, expected)) {
        printf("FAIL: get_temperature_status(70) = \"%s\", expected \"%s\"\n", 
               result ? result : "NULL", expected);
        return MUNIT_FAIL;
    }
    
    printf("PASS: get_temperature_status(70) = \"%s\" ✓\n", result);
    return MUNIT_OK;
}

// Test function 4 - Returns FAIL instead of ERROR
static MunitResult test_just_right2(const MunitParameter params[], void* data) {
    char *result = get_temperature_status(75);
    const char *expected = "just right";
    
    if (!string_equals(result, expected)) {
        printf("FAIL: get_temperature_status(75) = \"%s\", expected \"%s\"\n", 
               result ? result : "NULL", expected);
        return MUNIT_FAIL;
    }
    
    printf("PASS: get_temperature_status(75) = \"%s\" ✓\n", result);
    return MUNIT_OK;
}

int main() {
    // Define test array
    MunitTest tests[] = {
        { "/test_cold", test_cold, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
        { "/test_hot", test_hot, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
        { "/test_just_right", test_just_right, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
        { "/test_just_right2", test_just_right2, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
        { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }  // Null terminator
    };

    // Define test suite
    MunitSuite suite = {
        "/get_temperature_status_suite",  // Suite name
        tests,                            // Test array
        NULL,                             // Sub-suites
        1,                                // Iterations
        MUNIT_SUITE_OPTION_NONE          // Options
    };

    return munit_suite_main(&suite, NULL, 0, NULL);
}