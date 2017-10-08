#include "header.h"

int main(void) {
  int nbr = 1100;
  
  printf("Checking if %d is prime: %d.\n", nbr, is_prime(nbr));
  printf("Sum of digits of number %d: %d.\n", nbr, sum_of_digits(nbr));
  return 0;
}