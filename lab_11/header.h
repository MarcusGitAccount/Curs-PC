#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include <math.h>

  typedef struct {
    double real, imag;
  } complex_t;

  typedef struct {
    double r, theta;
  } polar_t;

  # define PI 3.14159265358979323846

  void debug_nbr(complex_t nbr, bool endln);
  complex_t suma(complex_t a, complex_t b);
  complex_t produs(complex_t a, complex_t b);
  complex_t conjugata(complex_t nbr);
  double modul(complex_t nbr);
  double rad_to_degrees(double angle);
  double degrees_to_rad(double angle);
  polar_t to_polar(complex_t coords);
  complex_t to_carth(polar_t coords);

#endif