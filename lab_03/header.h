#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct point{
  double x, y;
} point;

int ex_01(int start_1, int end_1, int start_2, int end_2);
unsigned long long int ex_02_model01(unsigned long long int size);
unsigned long long int ex_02_model02(unsigned long long int size);

#endif