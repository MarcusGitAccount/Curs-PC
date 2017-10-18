#include "header.h"

int set_bit(int nbr, int position) {
  // set bit at position
  return nbr | (1 << position);
}

int reset_bit(int nbr, int position) {
  return nbr & ~(1 << position);
}

int int_is_negative(int nbr) {
  return nbr & (1 << 31);
}



int main(void) {
  printf("%d\n", int_is_negative(-10));
  return 0;
}