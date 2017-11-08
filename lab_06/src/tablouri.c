#include "header.h"


float suma(float tablou[], size_t size) {
  float total  = 0;
  
  for (size_t index = 0; index < size; index++)
    total += tablou[index];
  
  return total;
}

void afisare(float tablou[], size_t size) {
  for (size_t index = 0; index < size; index++)
    printf("%f ", tablou[index]);
  
  printf("\n");
}

void reverse(float tablou[], size_t size) {
  size_t left  = 0;
  size_t right = size - 1;

  while (left < right) {
    float temp = tablou[left];
    
    tablou[left++]  = tablou[right];
    tablou[right--] = temp;
  }
}

float max_tablou(float tablou[], size_t size) {
  float max = 1 << 31;
  
  for (size_t index = 0; index < size; index++) {
    if (tablou[index] > max)
      max = tablou[index];
  }
  
  return max;
}