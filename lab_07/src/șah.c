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

void init(char tabla[][8]) {
  
}

void print(char tabla[][8]) {
  for (unsigned int i = 0; i < 8; i++) {
    for (unsigned int j = 0; j < 8; j++)
      printf("%c", tabla[i][j]);
    printf("\n");
  }
}b