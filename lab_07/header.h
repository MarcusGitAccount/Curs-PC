#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>

# define  KRED "\x1B[31m"
# define  KGRN "\x1B[32m"
# define  KYEL "\x1B[33m"
# define  KBLU "\x1B[34m"
# define  KMAG "\x1B[35m"
# define  KCYN "\x1B[36m"
# define  KWHT "\x1B[37m"
# define RESET "\033[0m"

  typedef   signed          char  int8_t;
  typedef   signed     short int int16_t;
  typedef   signed           int int32_t;
  typedef   signed long long int int64_t;
  
  typedef unsigned          char  uint8_t;
  typedef unsigned     short int uint16_t;
  typedef unsigned           int uint32_t;
  typedef unsigned long long int uint64_t;

# define EMPTY_PIECE ('0')

  void swap_u8(uint8_t* a, uint8_t* b);
  void swap_u32(uint32_t* a, uint32_t* b);
  void convert_position(uint8_t* col, int* row);
  bool get_player(uint8_t** tabla, uint8_t col, int row);
  bool in_bounds(uint8_t** tabla, uint8_t col, int row);
  bool check_basic_moving(uint8_t** tabla, uint8_t c1, int r1, uint8_t c2, int r2);
  bool move_rook(uint8_t** tabla, uint8_t c1, int r1, uint8_t c2, int r2);
  bool move_pawn(uint8_t** tabla, uint8_t c1, int r1, uint8_t c2, int r2);
  
  void  init(uint8_t** tabla);
  void print(uint8_t** tabla);
  void make_move(uint8_t** tabla, int start_linie, uint8_t start_col, int fin_linie, uint8_t fin_col);

#endif