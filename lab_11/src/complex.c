#include "header.h"

void debug_nbr(complex_t nbr, bool endln) {
  printf("Real: %2.lf\nImaginar: %2.lf\n", nbr.real, nbr.imag);

  if (endln)
    printf("\n");
}

complex_t suma(complex_t a, complex_t b) {
  complex_t result = {a.real + b.real, a.imag + b.imag};

  return result;
}

complex_t produs(complex_t a, complex_t b) {
  complex_t result;

  result.real = a.real * b.real - a.imag * b.imag;
  result.imag = a.imag * b.real + a.real * b.imag;

  return result;
}

complex_t conjugata(complex_t nbr) {
  complex_t result = {nbr.real, -nbr.imag};

  return result;
}

double modul(complex_t nbr) {
  return sqrt(nbr.real * nbr.real + nbr.imag * nbr.imag);
}

double rad_to_degrees(double angle) {
  return angle * 180 / PI;
}

double degrees_to_rad(double angle) {
  return angle * PI / 180;
}

polar_t to_polar(complex_t coords) {
  const double theta = atan2(coords.imag, coords.real);
  const double r = modul(coords);
  
  return (polar_t){r, theta};
}

complex_t to_carth(polar_t coords) {
  return (complex_t){coords.r * cos(coords.theta), coords.r * sin(coords.theta)};
}

complex_t moivre(complex_t a, double b) {
  polar_t result = to_polar(a);

  result.r = pow(result.r, b);
  result.theta *= b;

  return to_carth(result);
}
// ridicare la n => moivrep