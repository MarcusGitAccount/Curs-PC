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
  
  int mask = ~0;          // 1111 1111
  
  mask <<= (j + 1);       // 1100 0000
  mask |= (1 << i) - 1;   // 0000 0011
  n &= mask;              // 1100 0001
  m <<= i;                // move elements of m into position
  
  return n | m;           // merge m into n's cleared positions
}

// 5.2 print double
int transform_subunitary(double nbr, char result[32], int *length) {
  // length = -1 => ERROR CODE
  unsigned int index = 0;
  
  if (nbr < 0 || nbr >= 1)
    return -1;
  if (nbr == 0)
    return 0;
  
  while (nbr > 0) {
    printf("%f ", nbr);
    if (*length >= 32)
      return -1;
      
    nbr *= 2;
    if (nbr > 0)
      result[index++] = (nbr--, '1');
    else
      result[index++] = '0';
    *length++;
  }
  
  return 1;
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

// 5.4
unsigned int next_biggest(unsigned int nbr) {
  // findd the first non trailing zero
  // (the first zero that is not followed by other zeroes)
  // only works with unsigned values because we need logical right shifts
  // 11010110
  
  unsigned int auxiliar, mask;
  int position, set_bits_count, bit;

  position = set_bits_count = 0;
  auxiliar = nbr;
  
  while (auxiliar >= 0) {
    bit = auxiliar & 1;
    set_bits_count = bit;
    
    if (bit == 0 && set_bits_count > 0)
      break ;
    auxiliar >>= 1;
  }
  
  if (!auxiliar)
    return (1 << 31); // MIN_INT -> error code
    
  // set the first non traling zero bit => 1101 1110
  nbr |= 1 << position; 
  // clear all the bits on the right of position => 1101 1000
  mask = ~0 << (position - 1); // 1101 1000
  nbr &= mask; 
  nbr |=  (1 << --set_bits_count)
  
  return nbr;
}

// previous
unsigned int next_smallest(unsigned int nbr) {
  /*
    Count the number of trailing ones, cound the zeroes
    following them and the position of the first non
    trailing one
  */
  unsigned int mask, auxiliar;
  int position, trailing_set, trailing_notset;
  
  auxiliar = nbr;
  position = trailing_set = trailing_notset = 0;
  
  while (auxiliar & 1) {
    trailing_set++;
    auxiliar >>= 1;
  }
  
  if (auxiliar == 0)
    return (1 << 31); // error code
    
  while (auxiliar & 1 == 0) {
    trailing_notset++;
    position++;
    auxiliar >>= 1;
  }
  
  // clear bits after and including the position
  mask = ~0;
  mask <<= (position + 1);
  // get trailig_set + 1 set bitss starting two positions 
  // after 'position'
  mask = (1 << (trailing_set + 1)) - 1;
  mask <<= (trailing_notset - 1);
  nbr |= mask;

  return nbr;
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

// 5.7
unsigned int pairwise_swap(unsigned int nbr) {
  // this only works with unigned int
  // because we need to perform a logial shift to the right
  // working with 32 bit integers
  
  unsigned int odd  = nbr & 0x55555555; // 0101 0101 x 4 times (4 bytes, duh)
  unsigned int even = nbr & 0xAAAAAAAA; // 1010 1010 x 4 times (4 bytes, duh)
  
  odd  <<= 1; // swtich obb bits to even positions
  even >>= 1; // viceversa
  
  return odd | even; // combine them
}

// 5.8
void draw_line(unsigned char screen[64], int width, int x1, int x2, int y) {
  int offset_left, offset_right;
  int start_left, start_right;
  unsigned char start_mask, end_mask; 
  
  // first_left  = x1 + (8 - x1 % 8 - 1);
  // first_right = x2 - (x2 % 8);
 
  start_left  = x1 / 8;
  offset_left = x1 % 8;
  if (offset_left == 0) // beginning of byte
    start_left++;
    
  start_right  = x2 / 8;
  offset_right = x2 % 8;
  if (offset_right == 7) // end of byte
    start_right--;
    
  for (int index = start_left; index <= start_right; index)
    screen[width / 8 * y + index] = 0xFF;
    
  start_mask = 0xFF >> (x1 % 8);
  end_mask   = 0xFF << (7 - x % 8);
  
  if (x1 / 8 == x2 / 8) {
    // in the same byte
    unsigned char mask = start_mask & end_mask;
    screen[width / 8 * y + x1  / 8] |= mask;
  }
  else {
    if (offset_left != 0)
      screen[width / 8 * y + offset_left - 1] |= start_mask;
    if (offset_right != 7)
      screen[width / 8  *y  + offset_right + 1] |= end_mask;
  }
}