// 3 sep 2025
// Structs

#include <stdio.h>
#include "main_lib.h"

// --------------------------------L1 : Structs --------------------------------

// Run with : 
// gcc -o 1test_runner L1T_Structs.c main.c -lmunit && ./1test_runner

/*
struct Coordinate {
  int x;
  int y;
  int z;
};
*/

// --------------------------------L2 : Intializers --------------------------------

// RUN WITH :
// gcc -o 1test_runner L2T_Initializer.c main.c -lmunit && ./1test_runner   

// struct Coordinate new_coord(int x, int y, int z) {
//   struct Coordinate c = {
//     .x = x,
//     .y = y,
//     .z = z
//   };
//   return c;
// }

// --------------------------------L3 : Scaling Coordinate --------------------------------

// RUN WITH :
// gcc -o 1test_runner L3T_Scaling_Coordinat.c main.c -lmunit && ./1test_runner

// struct Coordinate scale_coordinate(struct Coordinate coord, int factor) {
//   struct Coordinate new_coord = {
//     new_coord.x = coord.x * factor,
//     new_coord.y = coord.y * factor,
//     new_coord.z = coord.z * factor
//   };
//   return new_coord;
// }

// --------------------------------L4 : Typedef --------------------------------

coordinate_t new_coord(int x, int y, int z) {
   coordinate_t coord = {.x = x, .y = y, .z = z};

  return coord;
}

coordinate_t scale_coordinate(coordinate_t coord, int factor) {
  coordinate_t scaled = coord;
  scaled.x *= factor;
  scaled.y *= factor;
  scaled.z *= factor;

  return scaled;
}

// --------------------------------L5 : Sizeof --------------------------------

// False

// --------------------------------L6 : Struct Padding --------------------------------

// typedef struct SneklangVar {
//   char type;
//   char *name;
//   int value;
//   char is_constant;
//   int scope_level;
// } sneklang_var_t;

// int main1(){
//   int x = sizeof(sneklang_var_t);
//   printf("%d", x);
//   return 0;
// }

// ___m___a___i___n_______________________DRIVER___________________________________

// int main() {
//     main1();
//     return 0;
// }