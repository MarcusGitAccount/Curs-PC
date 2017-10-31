#include "header.h"

int ex_01(int start_1, int end_1, int start_2, int end_2) {
  if (start_1 > end_1)
    end_1 += 24;
  if (start_2 > end_2)
    end_2 += 24;
    
  if (start_1 >= start_2 && start_1 < end_2)
    return 1;
  if (start_2 >= start_1 && start_2 < end_1)
    return 1;

  return 0;
}

unsigned long long ex_02_model01(unsigned long long int size) {
  unsigned long long int mask = 1LL << ((size << 1) ^ 1);
  
  
  mask |= (1LL << size);
  return mask; // 136, 129
}

unsigned long long int ex_02_model02(unsigned long long int size) {
  unsigned long long int mask = -1; // only ones
  
  mask <<= ((size << 1) ^ 1);
  mask ^= (1 << size);
  mask = ~mask;

  return  mask;
}