// 3 Sep 2025
// Structs

// #ifndef MAIN_LIB_H
// #define MAIN_LIB_H

#pragma once

// --------------------------------L1 : Structs --------------------------------

// struct Coordinate {
//   int x;
//   int y;
//   int z;
// };

// --------------------------------L2 : Intializers --------------------------------

//struct Coordinate new_coord(int x, int y, int z);

// --------------------------------L3 : Scaling Coordinate --------------------------------

//struct Coordinate scale_coordinate(struct Coordinate coord, int factor);

// --------------------------------L4 : Typedef --------------------------------

typedef struct
{
  int x;
  int y;
  int z;
} coordinate_t;

coordinate_t new_coord(int x, int y, int z);

coordinate_t scale_coordinate(coordinate_t coord, int factor);

// --------------------------------L6 : Struct Padding --------------------------------

typedef struct SneklangVar {
  char *name;
  int scope_level;
  int value;
  char type;
  char is_constant;
} sneklang_var_t;

// #endif
