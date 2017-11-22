#include "header.h"


float suma(float tablou[], size_t size) {
  float total  = 0;
  
  for (size_t index = 0; index < size; index++)
    total += tablou[index];
  
  return total;
}

void afisare(float* tablou, int size) {
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

void afisare_int(int* array, int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", array[i]);
  printf("\n");
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
      if (array[i] > array[j])
        float_swap(&array[i], &array[j]);
 
}

/*
  void* malloc(size)
  void* calloc(size, sizeof);
  free
  malloc didn't work properly => return NULL
  malloc creates memory on the heap, not on the stack, like the static way
*/

float* merge(float* a, int n, float* b, int m) {
  unsigned int i, j, current;
  float* c = (float*)malloc((m + n) * sizeof(float));
  
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

  return c;  
}

bool is_prime(int nbr) {
  if (nbr < 2)
    return false;
  if (nbr == 2)
    return true;
  if ((nbr & 1) == 0)  
    return false;
  
  for (unsigned int factor = 3; factor * factor <= nbr; factor += 2)
    if (nbr % factor == 0)
      return false;
      
  return true;
}

int* first_n_primes(int n) {
  int* result = (int*)malloc(n * sizeof(int));
  unsigned int current = 2;
  unsigned int count   = 0;

  while (count < n) {
    if (is_prime(current))
      result[count++] = current; 
    
    current++;
  }
  
  return result;
}