#include "header.h"

/*
  Cerințe:
  1.) Calculați cmmdc a nr întregi a și b, abs(a) și abs(b) < 10 ^ 7
  2.) Afișați toți divizorii unui număr întreg n, abs(n) < 10 ^ 7
  3.) Calculați a ^ b, abs(a), abs(b), abs(a ^ b) <= 10 ^ 10
*/

unsigned int ft_abs(int nbr) {
  // check if nbr is negativ
  int mask = 1 << 31; // MIN_INT
  
  if (nbr == (nbr | mask) && nbr)
    return ~nbr + 1; // complement by two
  return nbr;
}

unsigned int cmmdc(int a, int b) {
  unsigned int _a = ft_abs(a);
  unsigned int _b = ft_abs(b);
  unsigned int remaining = 0;
  
  while (_b) {
    remaining = _a % _b;
    _a = _b;
    _b = remaining;
  }
  
  return _a;
}

void print_denominators(int nbr) {
  unsigned int _nbr = ft_abs(nbr);
  
  if (nbr)
    printf("1 -1 ");
  
  for (int divider = 2; divider <= _nbr / 2; divider++)
    if (nbr % divider == 0)
      printf("%d %d ", divider, -divider);

  if (nbr)
    printf("%d %d ", nbr, -nbr);
}

long double _pow(long long a, long long b) {
  long double result = 1;
  char sign = b < 0 ? 1 : 0;
  // cazuri: b < 0
  if (a == 0)
    result = 0;
  
  b = ft_abs(b);
  while (b) {
    if (b & 1)
      result *= a;
    
    b /= 2;
    a = a * a;
  }
  
  if (sign)
    return 1 / result;
  return result;
}

void print_ascii_table() {
  for (short int c = 32; c < 128; c++)
    printf("%d: %c\n", c, (char)c);
}

short int nr_cifre(unsigned long long nbr) {
  short int count;

  for (count = 0; nbr > 0; nbr /= 10, count++);
  
  return count;
}

int main(void) {
  unsigned long long int nbr;
  unsigned int n;
  
  stdin = fopen("stdin", "r");
  
  if (scanf("%lld", &nbr) != 1) {
    printf("Error while reading input.\n");
    return -1;
  }
  
  printf("%lld has %d digits.\n", nbr, nr_cifre(nbr));
  printf("Cmmdc: %u\n", cmmdc(-24, 16));
  printf("Power: %Lf\n", _pow(0, 0));
  //print_ascii_table();
  
  scanf("%d", &n);
  printf("\nHomework solutions:\n\n");
  solve_a(n);
  solve_b(n);
  solve_c(n);
  solve_d(n);

  return 0;
}