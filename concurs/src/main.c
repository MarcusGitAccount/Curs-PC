#include "header.h"

int main(void) {
  unsigned long long int UPPER_BOUND= ~0; 
  
  printf("%llu\n", UPPER_BOUND / 64);
  return 0;
}