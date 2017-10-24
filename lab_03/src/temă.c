#include "header.h"

int ex_01(int start_1, int end_1, int start_2, int end_2) {
  if (start_1 > end_1)
    end_1 += 24;
  if (start_2 > end_2)
    end_2 += 24;
    
  if (start_1 > start_2 && start_1 < end_2)
    return 1;
  if (start_2 > start_1 && start_2 < end_1)
    return 1;

  return 0;
}

unsigned int ex_02_model01(short int size) {
  unsigned int mask = 1 << (2 * size + 1);
  
  mask |= (1 << size);
  return mask;
}

unsigned int ex_02_model02(short int size) {
/*  
  int mask = 1 << (2 * k + 1);

  mask -= 1;
  return mask ^ (1 << k);
*/

  //all ones, without the bit sign
  unsigned int mask = ~(1 << 31);    
  //get only the needed one, except the middle bit
  mask >>= (sizeof(int) * 8 - 1) - (2 * size + 1);               
  // clear the middle bit
  mask ^= (1 << size);
  return  1;
}