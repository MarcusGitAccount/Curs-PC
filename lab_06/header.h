#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

float suma(float tablou[], size_t size);
float max_tablou(float tablou[], size_t size);
void reverse(float tablou[], size_t size);
void afisare(float* tablou, int size);
void afisare_int(int* tablou, int size);
void float_swap(float* a, float* b);
void reverse_array(float* array, size_t size);
void reverse_array_2(float* array, size_t size);
float* merge(float* a, int n, float* b, int m);
bool is_prime(int nbr);
int* first_n_primes(int n);

#endif