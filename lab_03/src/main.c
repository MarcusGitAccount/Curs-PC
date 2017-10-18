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

// switch cu zilele săptămânii
// Temă: de pe tablă

int main(void) {
  point a, b;
  
  stdin = fopen("stdin", "r");
  
  scanf("%lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y);
  printf("Distane between points: %f\n", distance(a, b));
  printf("%d\n", int_is_negative(-10));

  return 0;
}