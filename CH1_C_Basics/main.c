// 31/08/2025
// C Basics

#include <stdio.h>
#include "main_lib.h"

// --------------------------------L1 : Welcome To Memory Management --------------------------------

int main1() {
    printf("Starting the Sneklang interpreter...\n");
    return 0;
}

// --------------------------------L2 : C Program Structure --------------------------------

int main2() {
    printf("Program in C!\n");
    return 0;
}

// --------------------------------L3 : Interpreted Quiz --------------------------------

// -> 'starting' prints, then a stack trace due to an undefined function prints

// --------------------------------L4 : C is Compiled --------------------------------

int main4() {
  printf("starting sneklang tools\n");
  printf("finished sneklang tools\n");
  return 0;
}

// --------------------------------L5 : Comments --------------------------------

int main5() {
  /*
    Sneklang is for nvim enjoyers
    who want to write their own garbage
    collectors instead of using off-the-shelf
    solutions
  */
  printf("i use sneklang btw\n");
  printf("i use nvim btw\n");
  printf("i use arch btw\n");
  return 0;
}

// --------------------------------L6 : Basic Types --------------------------------

int main6() {
  int max_recursive_calls = 100;
  char io_mode = 'w';
  float throttle_speed = 0.2;

  // don't touch below this line
  printf("Max recursive calls: %d\n", max_recursive_calls);
  printf("IO mode: %c\n", io_mode);
  printf("Throttle speed: %f\n", throttle_speed);
  return 0;
}

// --------------------------------L7 : Strings --------------------------------

int main7() {
  char *will_never_hear_again = "Hey TJ, when is the memory course in C gonna be done?";

  // don't touch below this line
  printf("%s\n", will_never_hear_again);
  return 0;
}

// --------------------------------L8 : Printing Variables --------------------------------

int main8() {
  int sneklang_default_max_threads = 8;
  char sneklang_default_perms = 'r';
  float sneklang_default_pi = 3.141592;
  char *sneklang_title = "Sneklang";

  /*
    %d - digit (integer)
    %c - character
    %f - floating point number
    %s - string (char *)
  */

  // don't touch above this line

  printf(
    "Default max threads: %d\nCustom perms: %c\nConstant pi value: %f\nSneklang title: %s\n", 
    sneklang_default_max_threads, sneklang_default_perms,sneklang_default_pi,sneklang_title
    );

  return 0;
}

// --------------------------------L9 : Compilation {types} --------------------------------

// -> Python

// --------------------------------L10 : Variables --------------------------------

int main10() {
  int sneklang_int_size = 64;
  sneklang_int_size = 32;
  printf("Sneklang int size: %d bits\n", sneklang_int_size);
  return 0;
}

// --------------------------------L11 : Constants --------------------------------

// const int meaning_of_life = 42;

// --------------------------------L12 : Functions --------------------------------

int max_sneklang_memory(int max_threads, int memory_per_thread){
    return max_threads * memory_per_thread;
}

// don't touch below this line

void init_sneklang(int max_threads, int memory_per_thread) {
  printf("Initializing Sneklang\n");
  printf("Max threads: %d\n", max_threads);
  printf("Memory per thread: %d\n", memory_per_thread);
  int max_memory = max_sneklang_memory(max_threads, memory_per_thread);
  printf("Max memory: %d\n", max_memory);
  printf("====================================\n");
}

int main12() {
  init_sneklang(4, 512);
  init_sneklang(8, 1024);
  init_sneklang(16, 2048);
  return 0;
}

// --------------------------------L13 : Void --------------------------------

// -> void x = None;

// --------------------------------L14 : Unit Test --------------------------------

// Run test with : 
// gcc -o 1test_runner L14T_Unit_Test.c main.c -lmunit && ./1test_runner

float get_average(int x, int y, int z){
  return ((float)x + y + z)/3;
}

/*
The + operator adds two numbers: 1 + 2 is 3.

The / operator divides two numbers, however:
if both numbers are integers, integer division is performed. 
The result will be an integer.

if either number is a float, floating point division is performed. 
The result will be a float.
*/


// --------------------------------L15 : Math Operators --------------------------------

// Run Test :
// gcc -o 1test_runner L15T_Math_Op.c main.c -lmunit && ./1test_runner

float snek_score(
  int num_files,
  int num_contributors,
  int num_commits,
  float avg_bug_criticality
) {
  int size_fac = num_files * num_commits;
  int complex_fac = size_fac + num_contributors;
  return (float)(complex_fac * avg_bug_criticality);
}

/*
You can convert an integer to a float by casting it:

int x = 5;
float y = (float)x;
*/

// --------------------------------L16 : If Statements --------------------------------

char *get_temperature_status(int temp){
  if (temp < 70) {
    return "too cold";
  } 
  else if (temp > 90){
    return "too hot";
  } 
  else {
    return "just right";
  }
}

// --------------------------------L17 : Ternary --------------------------------

// f

// --------------------------------L18 : Type Sizes --------------------------------

// false

// --------------------------------L19 : Sizeof --------------------------------

#include <stdbool.h>
#include <stdint.h>

int main19() {
  // Use %zu is for printing `sizeof` result

  printf("sizeof(char)   = %zu\n", sizeof(char));
  printf("sizeof(bool)   = %zu\n", sizeof(bool));
  printf("sizeof(int)   = %zu\n", sizeof(int));
  printf("sizeof(float)   = %zu\n", sizeof(float));
  printf("sizeof(double)   = %zu\n", sizeof(double));
  printf("sizeof(size_t)   = %zu\n", sizeof(size_t));

  return 0;
}

// --------------------------------L20 : For loop --------------------------------

// Run test :
// gcc -o 1test_runner L20T_For_Loop.c main.c && ./1test_runner

void print_numbers(int start, int end){
  for (int i = start; i<=end; i++ ){
    printf("%d\n", i);
  }
}
  
// --------------------------------L21 : While loop --------------------------------

// Run test :
// gcc -o 1test_runner L21T_While_Loop.c main.c && ./1test_runner

void print_numbers_reverse(int start, int end){
  int x = start ;
  while (x >= end) {
    printf("%d\n", x);
    x--;
  }
}

// --------------------------------L22 : Do While loop --------------------------------

// Run test :
// gcc -o 1test_runner L22T_Do_While_Loop.c main.c && ./1test_runner

void print_numbers_reverse2(int start, int end) {
  do {
    printf("%d\n", start);
    start--;
  } while (start >= end);
}


// --------------------------------L23 : Pragma once and Header guards --------------------------------

// It prevents a header file from being included more than once, avoiding redefinition errors.

// ___m___a___i___n_______________________DRIVER___________________________________

// int main() {
//     main19();
//     return 0;
// }