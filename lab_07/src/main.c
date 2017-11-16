#include "header.h"

void print_adressess(float* array, unsigned int size) {
  printf("\nAddresses for array's elments:\n");
  for (unsigned int index = 0; index < size; index++)
    printf("%p\n", array + index);
}

void min_max(float* array, unsigned int size, float* min, float* max) {
  *min = *max = *array;

  for (unsigned int index = 0; index < size; index++) {
    if (*min > array[index])
      *min = array[index];
    if (*max < array[index])
      *max = array[index];
  }
}

void transform_seconds_interval(size_t interval, size_t* hour, size_t* min, size_t *sec) {
  *hour = interval / 3600;
  *min  = interval % 3600;
  *sec  = interval % 60;
}

void print_transformed_interval(size_t interval, size_t hour, size_t min, size_t sec) {
  char plural_sufix = 'a';

  printf("\n%lu sec = ", interval);
  
  if (interval == 0) {
    printf("0 ore 0 min 0 sec\n");
    return ;
  }
  
  if (hour) {
    if (hour > 1)
      plural_sufix = 'e';
    
    printf("%lu or%c ", hour, plural_sufix);
  }
  
  if (min >= 60) {
    printf("%lu min ", interval / 60);
  }
  
  if (sec)
    printf("%lu sec", interval);
}

float get_middle(float* first, float* last) {
  #ifdef DEBUG
    printf("%p\n", first);
    printf("%p\n", last);
    printf("%ld\n", last - first);
  #endif
  
  unsigned long int distance = last - first;
  
  distance /= 2;
  return *(first + distance);
}

int main(void) {
  float array[] = {1.0, -2.4, 4.5, 5, 6, 9.7};
  float minim, maxim;
  size_t hour, min, sec;
  
  print_adressess(array, 5);
  min_max(array, 5, &minim, &maxim);
  
  printf("\nMin and max of the array: (%f, %f)\n", minim, maxim);
  
  transform_seconds_interval(3670, &hour, &min, &sec);
  print_transformed_interval(3670, hour, min, sec);
  
  transform_seconds_interval(3600 * 2, &hour, &min, &sec);
  print_transformed_interval(3600 * 2, hour, min, sec);
  
  transform_seconds_interval(3600, &hour, &min, &sec);
  print_transformed_interval(3600, hour, min, sec);
  
  transform_seconds_interval(3599, &hour, &min, &sec);
  print_transformed_interval(3599, hour, min, sec);
  
  transform_seconds_interval(60, &hour, &min, &sec);
  print_transformed_interval(60, hour, min, sec);

  transform_seconds_interval(61, &hour, &min, &sec);
  print_transformed_interval(61, hour, min, sec);
  
  transform_seconds_interval(120, &hour, &min, &sec);
  print_transformed_interval(120, hour, min, sec);
  
  transform_seconds_interval(121, &hour, &min, &sec);
  print_transformed_interval(121, hour, min, sec);
  
  transform_seconds_interval(59, &hour, &min, &sec);
  print_transformed_interval(59, hour, min, sec);
  
  transform_seconds_interval(0, &hour, &min, &sec);
  print_transformed_interval(0, hour, min, sec);
  
  printf("\nMiddle element of the given array: %f\n", get_middle(array, array + 5));
  return 0;
}