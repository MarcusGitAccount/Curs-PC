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
unsigned int ex_02_model01(short int k);
unsigned int ex_02_model02(short int k);

#endif