// 31/08/2025
// C Basics

#include "main_lib.h"
#include <stdio.h>

void test(int start, int end){
  printf("Printing from %d to %d:\n", start, end);
  print_numbers_reverse2(start, end);
  printf("======================\n");
}

int main() {
  test(5, 1);
  test(1, 5);
}
