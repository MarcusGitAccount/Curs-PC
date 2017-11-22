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

// swap 2 float variables
void float_swap(float* a, float* b) {
  float temp = *a;
  
  *a = *b;
  *b = temp;
}

// reverse array 2
void reverse_array(float* array, size_t size) {
  // a <=> &a[0]
  
  size_t left  = 0;
  size_t right = size - 1;

  while (left < right)
    float_swap(&array[left++], &array[right--]);
}

void reverse_array_2(float* array, size_t size) {
  for (size_t index = 0; index < size / 2; index++)
    float_swap(&array[index], &array[size - index - 1]);
}

void sort(float* array, int size) {
  for (int i = 0; i < size - 1; i++)
    for (int j = i + 1; j < size; j++)
      if (aarray[i] > array[j])
        float_swap(&array[i], &array[j]);
 
}

int merge(float* a, int n, float* b, int m, float* c) {
 // sort(a, n);
 // sort(b, m);
 
  unsigned int i, j, current;
  
  current = i = j = 0;
  
  while (i < n && j < m) {
    if (a[i] <= b[j])
      c[current++] = a[i++];
    else 
      c[current++] = b[j++];
  }
  
  while (i < n)
    c[current++] = a[i++];
  
  while (j < m)
    c[current++] = b[j++];
  
  // error handling
  if (current - 1 != n + m)
    return 0;
  return 1;  
}