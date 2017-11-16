#include "header.h"

int main(void) {
  float a[] = {1, 3.5, 2, 9, 0};
  float n, m;
  
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
  printf("(m, n) after  swapping: (%f, %f)\n", m, n);
  
  return 0;
}