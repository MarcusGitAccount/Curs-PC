#include "header.h"

/*
  1. Afiseaza numele citit de la tastatura a utilizatorului.
  2. Afiseaza media aritmetica a 3 numere cu precizie de 2 cifre.
  3. Afiseaza codul ascii 2 doua caractere citite de la stdin.
*/

void lab_prob_01() {
  char name[32];
  
  scanf("%s", name);
  printf("Name: %s\n", name);
}

void lab_prob_02() {
  int a, b, c;
  
  scanf("%d%d%d", &a, &b, &c);
  printf("Average: %.2f\n", (a + b + c) / 2.0f);
}

void lab_prob_03() {
  char ch1, ch2;

  scanf("%c %c", &ch1, &ch2);
  printf("Ascii code for %c: %d\n", ch1, (int)ch1);
  printf("Ascii code for %c: %d\n", ch2, (int)ch2);
}

void bit_functions_debugging() {
  printf("INT_MIN: %d\n", min_int());
  printf("INT_MAX: %d\n", max_int());
  printf("%d\n", get_bit(0xE5, 2)); // 1
  printf("%d\n", get_bit(0xE5, 3)); // 0
  printf("%d\n", set_bit(0xE5, 1)); //  0xE5 + 2 = 231
  printf("%d\n", clear_bits_left_to(0xE5, 4)); // 5
  printf("%d\n", clear_bits_to_right(0xE5, 4)); // 224
  printf("%d\n", clear_bit(1024, 10)); // 0
  printf("%d\n", toggle_bit(0, 10));   // 1024
}

int main(void) {
  char result[32] = {0};
  int  length = 0;
  
  stdin = fopen("stdin", "r");

  ex_01();
  ex_02();
  
  printf("Bit insertion: %d\n", bit_insertion(1024, 19, 2, 6));
  printf("Bit insertion: %d\n", bit_insertion_2(1024, 19, 2, 6));
  printf("Bit flip: %d\n", flip_bit_to_win(63 ^ 16 ^ 8));
  
  test_5(2, 3, 4, 128, 129, 1023, 1024);
  printf("Flips to convert 29 and 15: %d\n", flips_to_convert(29, 15));
  
  transform_subunitary(0.102034, result, &length);
  printf("%s %d\n", result, length);
  return 0;
}