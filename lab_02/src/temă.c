#include "header.h"

void ex_01() {
  printf("%f\n", PI);
}

void ex_02() {
  char nume[32], prenume[32];
  int  grupa, numar;
  
  scanf("%d %s %s %d", &grupa, nume, prenume,&numar);
  printf("D:\\student\\%d\\%s %s\\main%03d.c\n", grupa, nume, prenume, numar);
}