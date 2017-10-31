#include "header.h"

const char available[45] = "********************************************"; 

int is_negative(int nbr) {
  int mask = 1 << 31;
  
  if (nbr != 0 && (nbr | mask) == nbr)
    return 1;
  return 0;
}

unsigned int _ft_abs(int nbr) {
  if (is_negative(nbr))
    return ~nbr + 1;
  return nbr;
}

void print_line(int padding_left, int middle, int padding_right) {
  printf("%*s",  padding_left,  "");
  printf("%.*s", middle, available);
  printf("%*s",  padding_right, "");
  printf("\n");
}

void solve_a(unsigned int n) {
  for (int step = 0; step < n; step++)
    print_line(0, n, 0);

  printf("\n");
}

void solve_b(unsigned int n) {
  for (int step = n - 1; step >= 0; step--)
    print_line(step, n - step, 0);

  printf("\n");
}

void solve_c(int n) {
  unsigned int actual_step;
  
  for (int step = -n + 1; step < n; step++) {
    actual_step = _ft_abs(step);
    print_line(actual_step, 2 * n - 1 - 2 * actual_step, actual_step);
  }

  printf("\n");
}

void solve_d(int n) {
  int padding;
  
  if (n == 0)
    return;

  print_line(n, 1, n);
  for (int step = -n + 1; step < n; step++) {
    padding = step ? 1 : 0;
    print_line(padding, 2 * n + 1 - 2 * padding, padding);
  }

  print_line(n, 1, n);
}