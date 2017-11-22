#include "header.h"

/*
  p - pion
  r - turn
  b - nebun
  n - cal
  q - regină
  k - rege
  
  literă mică => piesă neagră
  literă mare => piesă albă
  
  linii   = [8 .. 1]
  coloane = [a .. h]
  
  Efectuare mișcare pe tabla, funcție:
  Exemplu: a1 -> c2
*/

void init(char** tabla) {
  // set middle
  for (int i = 2 ; i < 6; i++)
    for (int j = 0; j < 8; j++)
      tabla[i][j] = '0';
      
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

void print(char** tabla) {
  for (unsigned int i = 0; i < 8; i++) {
    for (unsigned int j = 0; j < 8; j++)
      printf("%c ", tabla[i][j]);
    printf("\n");
  }
}

void make_move(char** tabla, int start_linie, char start_col, int fin_linie, char fin_col) {
  start_linie = 8 - start_linie;
  fin_linie   = 8 - fin_linie;
  
  int linie = (int)start_linie - 'a';
  int col   = (int)start_col   - 'a';
  
  tabla[fin_linie][fin_col] = tabla[linie][col];
  tabla[linie][col] = '0';
}

int find(char** tabla, char piece, char* cols, int* rows) {
  unsigned int index = 0;
  
  for (unsigned int i = 0; i < 8; i++) {
    for (unsigned int j = 0; j < 8; j++) {
      if (tabla[i][j] == piece) {
        rows[index] = i;
        cols[index] = j;
        
        index++;
      }
    }
  }
}