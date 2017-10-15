// Aproximare PI
#include "header.h"

double aproximate_pi(long long radius){
  double area;

  area = 0;
  for (long long x = -radius; x <= radius; x++)
    for (long long y = -radius; y <= radius; y++)
      if (x * x + y * y <= radius * radius)
        area++;

  return area / (radius * radius);
}