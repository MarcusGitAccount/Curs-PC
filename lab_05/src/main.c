#include "header.h"

/*
  n din [0..10**15]
  1.) Cifra k din n de la dreapta la stânga.
  2.) Determinați dacă n e palindrom sau nu.
  3.) Implemntați funcția: suma div. lui n la puterea ka
      f(n, k)
  4.) Calculați a ^ b
  5.) Implementați funcția lui Euler:
      f(n) = numărul de nr comprime cu între [1..n]
      numere coprime între ele = nu au factori comune între ele
      => cmmdc dintre ele e 1
  6.) 
*/


typedef   signed     short int int16_t;
typedef   signed           int int32_t;
typedef   signed long long int int64_t;

typedef unsigned     short int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned long long int uint64_t;

int is_negative(long long nbr) {
  long long mask = 1LL << 63;
  
  if (nbr && (nbr | mask) == nbr)
    return 1;
  return 0;
}

uint64_t absolute_value(uint64_t nbr) {
  if (is_negative(nbr))
    return ~nbr + 1;
  return nbr;
}

long double power(int64_t a, int64_t b) {
  long double result = 1;
  char sign = b < 0 ? 1 : 0;
  
  if (a == 0 && b == 0) {
    printf("Error. 0 ^ 0.");
    return (1 << 31);
  }
  
  if (sign)
    b *= -1;
    
  while (b) {
    if (b & 1)
      result *= a;
      
    a = a * a;
    b >>= 1;
  }
  
  if (sign)
    return 1 / result;
  return result;
}

uint16_t cif(uint64_t n, short int k) {
  if (is_negative(k) || n == n % (int)power(10, --k))
    return -1;
    
  return (n / (int)power(10, k)) % 10;
}

uint16_t toggle_bit(uint16_t nbr, uint16_t position) {
  uint16_t mask = (uint16_t)1 << position;
  
  return nbr ^ mask;
}

uint16_t can_be_palindrome(uint64_t n) {
  uint16_t map = 0;
  uint16_t current;

  while (n) {
    current = n % 10;
    map = toggle_bit(map, current);
    n /= 10;
  }
  
  if (map == 0)
    return 1;
  return map & (map - 1) ? 0 : 1;
}

int main(void) {
  stdin = fopen("stdin", "r");
  
  hex_to_dec();
  print_limits_64_bits();
  printf("Geometric average: %lf\n", geometric_average_three(2, 2, 2));
  printf("Geometric average: %lf\n", mg(2, 2, 2));
  
  printf("Mobius up to 100:\n");
  for (size_t n = 1; n <= 100; n++) {
    printf("mobius(%3d) = %2d\n", n, mobius(n));
  }
  return 0;
}