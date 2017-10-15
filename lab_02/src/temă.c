#include "header.h"

void ex_01() {
  int radius, x, y;
  double perimetru, arie;
  const double pi = aproximate_pi(1000);
  
  scanf("%d %d %d", &x, &y, &radius);
  perimetru = 2 * pi * radius;
  arie = pi * radius * radius;
  
  printf("Aria: %.2f\n", arie);
  printf("Perimetrul: %.2f\n", perimetru);
}

void ex_02() {
  char nume[32], prenume[32];
  int  grupa, numar;
  
  scanf("%d %s %s %d", &grupa, nume, prenume,&numar);
  printf("D:\\student\\%d\\%s %s\\main%03d.c\n", grupa, nume, prenume, numar);
}