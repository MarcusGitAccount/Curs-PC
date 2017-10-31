#include "header.h"

void scanf_try(int expected, int result) {
  if (result != result) {
    printf("Error while reading input data.\n");
    printf("Expected number of characters: %d\n", expected);
    printf("Number of read characters:     %d\n", result);
    exit(SCANF_ERROR_CODE);
  }
}

void ideal_weight() {
  float result = 0;
  int height, age;
  char sex;
  
  scanf_try(scanf("%d %d %c", &height, &age, &sex), 3);
  
  if (sex != 'm' && sex != 'f') {
    printf("Invalid sex\n");
    exit(0);
  }
  
  result = 50 + 0.75 * (height - 150) + (age - 20) / 4.f;
  if (sex == 'f')
    result -= 10;
  
  printf("Ideal weight: %.2f\n", result);
}

void greatest_fraction() {
  int a, b, c, d;
  double first, second;
  
  scanf_try(scanf("%d, %d, %d, %d", &a, &b, &c, &d), 4);
  first = (double)a / b;
  second = (double)c / d;
  
  printf("%d %d %d %d\n", a, b, c, d);
  if (c == 0 || d == 0) {
    printf("Error: division by zero\n");
    return ;
  }
  
  if (second > first) {
    printf("Result: second\n");
    return ;
  }
  else if (second < first) {
    printf("Result: second\n");
    return ;
  }
  
  printf("Result: equal\n");
}

int main(void) {
  int vector[10];
  
  stdin = fopen("stdin", "r");
  ideal_weight();
  greatest_fraction();
  
  for (int i = 0; i < 10; i++)
    scanf("%d", &vector[i]);
  for (int i = 0; i < 10; i++)
    printf("%d ", vector[i]);
    
  printf("\n");
  return 0;
}