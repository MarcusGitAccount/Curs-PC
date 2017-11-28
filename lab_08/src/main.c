#include "header.h"

uint32_t** pascals_triangle(uint32_t n) {
  uint32_t** triangle = (uint32_t**)malloc(sizeof(uint32_t*) * n);

  for (uint32_t index = 0; index < n; index++)  
    triangle[index] = (uint32_t*)malloc(sizeof(uint32_t) * (index + 1));
    
  for (uint32_t index = 0; index < n; index++) {
    triangle[index][0] = triangle[index][index] = 1;
    
    for (uint32_t j = 1; j < index; j++)
      triangle[index][j] = triangle[index - 1][j] + triangle[index - 1][j - 1];
  }
  
  return triangle;
}

void free_triangle(uint32_t** triangle, uint32_t size) {
  for (uint32_t index = 0; index < size; index++)
    free(triangle[index]);
    
  free(triangle);
}

void print_triangle(uint32_t** triangle, uint32_t size) {
  for (uint32_t index = 0; index < size; index++) {
    for (uint32_t j = 0; j <= index; j++)
      printf("%4u ", triangle[index][j]);
    printf("\n");
  }
}

int add(int a, int b) {
  return a + b;
}

int substract(int a, int b) {
  return a - b;
}

int (*choose(bool type))(int, int) {
  if (type)
    return add;
  return substract;
}

int main(void) {
  uint32_t   size = 4;
  uint32_t** triangle = pascals_triangle(size);
  int choosen = choose(true)(2, 3);
  
  print_triangle(triangle, size);
  free_triangle(triangle, size);
  puts("");
  printf("%d\n", choosen);
  
  return 0;
}