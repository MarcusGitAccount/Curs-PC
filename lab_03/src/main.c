#include "header.h"

int set_bit(int nbr, int position) {
  // set bit at position
  return nbr | (1 << position);
}

int reset_bit(int nbr, int position) {
  return nbr & ~(1 << position);
}

int int_is_negative(int nbr) {
  int mask = 1 << 31;
  
  return nbr == (nbr | mask) && nbr != 0;
}

double distance(point a, point b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main(void) {
  point a, b;
  
  stdin = fopen("stdin", "r");
  
  scanf("%lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y);
  printf("Distane between points: %f\n", distance(a, b));
  printf("-10 is negative: %d\n", int_is_negative(-10));
  printf("Test for ex 1.0 from homework: %d\n", ex_01(13, 15, 14, 16));
  printf("Test for ex 1.0 from homework: %d\n", ex_01(23,  1, 21, 23));
  printf("Test for ex 1.0 from homework: %d\n", ex_01(1,  2,  1, 2));
  printf("Test for ex 1.0 from homework: %d\n", ex_01(23, 6,  1, 2));
  printf("Test for ex 2.1 from homework: %llu\n", ex_02_model01(20));
  printf("Test for ex 2.2 from homework: %llu\n", ex_02_model02(20));

  return 10;
}