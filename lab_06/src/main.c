#include "header.h"

int main(void) {
  float a[] = {1, 3.5, 2, 9, 0};
  
  printf("Suma tabloului: %f\n", suma(a, 5));
  afisare(a, 5);
  reverse(a, 5);
  afisare(a, 5);
  return 0;
}