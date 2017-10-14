#include "header.h"

int max_int()  {
  return 1 << 31;
}

int min_int() {
  return ~(1 << 31);
}

int get_bit(int nbr, int position) {
  return (nbr & (1 << position)) > 0;
}

int set_bit(int nbr, int position) {
  return (nbr | (1 << position));
}

int clear_bit(int nbr, int position) {
  return (nbr & ~(1 << position));
}

int clear_bits_left_to(int nbr, int position) {
  return (nbr & ((1 << position) - 1));  
}

int clear_bits_to_right(int nbr, int position) {
  int mask = -1 << (position + 1);
  
  return nbr & mask;
}

int toggle_bit(int nbr, int position) {
  return (nbr ^ (1 << position));
}

int update_bit(int nbr, int position, int bit) {
  int mask = ~(1 << bit);
  
  return (nbr & mask) | (bit << position);
}

/* ------ */
