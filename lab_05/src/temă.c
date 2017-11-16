#include "header.h"

void hex_to_dec() {
  int nbr;
  
  scanf("%x", &nbr);
  printf("Read number: %x\n", nbr);
  printf("From hex to dec: %d\n", nbr);
}

void print_limits_64_bits() {
  long long int          lower = (1LL << 63);
  unsigned long long int upper = ~0ULL;

  printf("Upper bound: %llu\n", upper);
  printf("Lower bound: %lld\n", lower);
}

double geometric_average_three(size_t a, size_t b, size_t c) {
  return pow(a * b * c, (float)1 / 3);
}

int mobius(size_t nbr) {
  size_t count_primes = 0;
  
  if (nbr == 1)
    return 1;
  
  if (nbr % 2 == 0) {
    count_primes++;
    nbr /= 2;
    if (nbr % 2 == 0)
      return 0;
  }

  for (size_t factor = 3; factor <= nbr && nbr; factor += 2) {
    if (nbr % factor == 0) {
      count_primes++;
      nbr /= factor;
      if (nbr % factor == 0)
        return 0;
    }
  }
  
  if (count_primes & 1)
    return -1;

  return 1;
}

int power(int a, int n, int modulo) {
  int result = 1;

  if (a == 0 && b == 0) {
    printf("0 ^ 0 nedeterminare.\n");
    return (1 << 31);
  }
  
  a %= modulo;
  while (n) {
    if (n & 1)
      result = (result * a) % modulo;
    
    n /= 2;;
    a = (a * a) % modulo;
  }
  
  return result;
}