#include "header.h"

/*
  p - pion / pawn
  r - turn / rook
  b - nebun / bishop
  n - cal / knight
  q - regină / queen
  k - rege / king
  
  literă mică => piesă neagră
  literă mare => piesă albă
  
  linii   = [8 .. 1]
  coloane = [a .. h]
  
  Efectuare mișcare pe tabla, funcție:
  Exemplu: a1 -> c2
*/

void swap_u8(uint8_t* a, uint8_t* b) {
  uint8_t temp = *a;

  *a = *b;
  *b = temp;
}

void swap_u32(uint32_t* a, uint32_t* b) {
  uint32_t temp = *a;

  *a = *b;
  *b = temp;
}

void convert_position(uint8_t* col, int* row) {
  *col -= 'a';
  *row  = 8 - *row;
}

void init(uint8_t** tabla) {
  // set middle
  for (int i = 2 ; i < 6; i++)
    for (int j = 0; j < 8; j++)
      tabla[i][j] = EMPTY_PIECE;
      
  // set pawns
  for (int j = 0; j < 8; j++) {
    tabla[1][j] = 'p';
    tabla[6][j] = 'P';
  }
  
  tabla[0][0] = tabla[0][7] = 'r';
  tabla[7][0] = tabla[7][7] = 'R';
  
  tabla[0][1] = tabla[0][6] = 'n';
  tabla[7][1] = tabla[7][6] = 'N';
  
  tabla[0][2] = tabla[0][5] = 'b';
  tabla[7][2] = tabla[7][5] = 'B';
  
  tabla[0][3] = 'q';
  tabla[7][3] = 'Q';
  tabla[0][4] = 'k';
  tabla[7][4] = 'K';
  
}

void print(uint8_t** tabla) {
  for (uint8_t i = 0; i < 8; i++) {
    printf("%d |  ", 8 - i);
    
    for (uint8_t j = 0; j < 8; j++)
      printf("%c ", tabla[i][j]);

    printf("\n");
  }
  
  printf("  |_ ");
  for (uint8_t i = 0; i < 8; i++)
    printf("_ ");
  printf("\n     a ");
  
  for (uint8_t i = 1; i < 8; i++)
    printf("%c ", 'a' + i);
  printf("\n");
}

void find(uint8_t** tabla, uint8_t piece, uint8_t* cols, int* rows) {
  unsigned int index = 0;
  
  for (unsigned int i = 0; i < 8; i++) {
    for (unsigned int j = 0; j < 8; j++) {
      if (tabla[i][j] == piece) {
        rows[index] = i;
        cols[index++] = j;
      }
    }
  }
}

uint8_t to_lower(uint8_t c) {
  if (c >= 'A' && c <= 'Z')
    c += 32;
  return c;
}

bool is_valid_move(uint8_t **tabla, uint8_t c1, int r1, uint8_t c2, int r2) {
  uint8_t piece;
  
  piece = to_lower(tabla[8 - r1][c1 - 'a']);
  
  printf("Piece: %c\n", piece);
  
  if (piece == 'p')
    return move_pawn(tabla, c1, r1, c2, r2);
  if (piece == 'r')
    return move_rook(tabla, c1, r1, c2, r2);

  return true; 
}


void make_move(uint8_t** tabla, int start_linie, uint8_t start_col, int fin_linie, uint8_t fin_col) {
  if (!is_valid_move(tabla, start_col, start_linie, fin_col, fin_linie)) {
    printf("%sInvalid move. Game stops here.%s\n", KRED, RESET);
    exit(1) ;
  }
  
  printf("Hello there\n");
  convert_position(&start_col, &start_linie);
  convert_position(&fin_col,   &fin_linie);
 
  tabla[fin_linie][fin_col] = tabla[start_linie][start_col];
  tabla[start_linie][start_col] = EMPTY_PIECE;
}

