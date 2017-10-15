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

// 5.1
int bit_insertion(int n, int m, int i, int j) {
  for (int position = i; position <= j && m; position++, m >>= 1)
    n |= ((m & 1) << position);
  
  return n;
}

int bit_insertion_2(int n, int m, int i, int j) {
  // clear all the bits between i->j
  // 1110 1101, 2->5 => 1100 0001
  // create mask => 1100 0011
  
  int mask = ~0; // 1111 1111
  
  mask <<= (j + 1);       // 1100 0000
  mask |= (1 << i) - 1;   // 0000 0011
  n &= mask;              // 1100 0001
  m <<= i;  // move elements of m into position
  
  return n | m;
}

// 5.3
int flip_bit_to_win(int nbr) {
  int current, prev, max, zeroes;

  if (nbr == 0)
    return 1;
  
  max = prev = current = zeroes = 0;
  while (nbr) {
    printf("%d ", nbr & 1);
    if (nbr & 1) {
      zeroes = 0;
      current++;
    }
    else {
      if (prev + current > max)
        max = prev + current;
      prev = current;
      if (++zeroes > 1)  
        prev = 0;
    
      current = 0;
    }
    
    nbr >>= 1;
  }
  
  if (prev + current > max)
    max = prev + current;
  
  return max + 1;
}

// 5.5
int is_power_of_two(int nbr) {
  return (nbr & (nbr - 1)) == 0;
}

void test_5(int first, ...) {
  va_list ap;
  
  va_start(ap, first);
  for (int current = first; current > 0; current = va_arg(ap, int)) {
    printf("Number %5d is a power of 2: %s\n", current, is_power_of_two(current) == 1 ? "yes" : "no");
  }
  va_end(ap);
}

// 5.6
int flips_to_convert(int a, int b) {
  int flips = a ^ b; 
  int total = 0;
  // number  of set bits will determine the number of flips

  while (flips) {
    total++;
    flips &= (flips - 1);
  }
  
  return total;
}