#include "header.h"

int main(void) {
  float a[] = {-1.5, 5};      // size = 2
  float b[] = { 1, 6, 10};    // size = 3
  /*float n, m;
  
  printf("Suma tabloului: %f\n", suma(a, 5));
  afisare(a, 5);
  reverse(a, 5);
  afisare(a, 5);
  reverse_array(a, 5);
  afisare(a, 5);
  reverse_array_2(a, 5);
  afisare(a, 5);
  
  n = 10;
  m = 67;
  
  printf("(m, n) before swapping: (%f, %f)\n", m, n);
  float_swap(&m, &n);
  printf("(m, n) after  swapping: (%f, %f)\n", m, n);*/
  
  float* merge_result = merge(a, 2, b, 3);
  int*   first_primes = first_n_primes(500000);
  
  afisare(merge_result, 5);
  afisare_int(first_primes, 500000);
  return 0;
}