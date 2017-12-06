#include "header.h"

int sum(int64_t n) {
  if (n < 10)
    return n;
  return n % 10 + sum(n / 10);
}

int k_cifre(int64_t n, int k) {
  if (n < 10)
    return k == 1;
  return 1 * k_cifre(n / 10, k - 1);
}

int max_in_array(float* array, int n) {  
  int prev;
  
  if (n == 1)
    return 0;

  prev = max_in_array(array, n - 1);

  if (array[n - 1] > array[prev])
    return n - 1;
  return prev;  
}

int max_in_array_2(float* array, int n) {  
  int position;

  if (n == 1)
    return 0;

  position = max_in_array_2(array + 1, n - 1);

  if (array[0] > array[position + 1])
    return 0;
  return position + 1;
}

bool is_sorted(float* array, int n) { 
  if (n == 1)
    return true;

  return (array[n - 1] > array[n - 2]) && is_sorted(array, n - 1);
}

// 5.) an - nr moduri în care se poate urca pe n trepte dacă se pot sări

int trepte(int n) {
  // wannabe fibonnaci
  if (n > 0 && n < 3)
    return n;
  return trepte(n - 1) + trepte(n - 2);
}

// 6.) câte șiruri de caractere există compuse din n char si doar din ABC și după A urmează B mereu
int siruri(int n) {
  if ( n == 1)
    return 3;
  if (n == 2)
    return 7;

  return siruri(n - 2) + 2 * siruri(n - 1);
}

int main(void) {
  float array[] = {1.0f, 2.5f, -2.0f, 99.0f, 12.0f, 34.0f, 100.0f};
  float tab[]   = {1.0f, 2.0f, 3.0f, 6.0f, 7.0f, 9.0f};

  printf("Teste problema 2: %d\n", k_cifre(1, 2));
  printf("Teste problema 2: %d\n", k_cifre(10, 2));
  printf("Teste problema 2: %d\n", k_cifre(100, 2));

  printf("Maximum in array:   %d\n", max_in_array(array, 7));
  printf("Maximum in array 2: %d\n", max_in_array_2(array, 7));

  printf("Is sorted: %d\n", is_sorted(array, 6));
  printf("Is sorted: %d\n", is_sorted(tab, 6));

  printf("%ld\n", &tab[3] - &tab[0]);
  return 0;
}