#include "header.h"

int main(void) {
  polar_t polar = to_polar((complex_t){2, 120});

  printf("R: %lf\n", polar.r);
  printf("Theta: %lf\n", (polar.theta));

  debug_nbr(to_carth(polar), true);
  return 0;
}