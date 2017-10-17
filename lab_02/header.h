#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

# define PI 3.14159265358979323846

double aproximate_pi(long long radius);
int min_int();
int max_int();
int get_bit(int nbr, int position);
int set_bit(int nbr, int position);
int clear_bit(int nbr, int position);
int clear_bits_left_to(int nbr, int position);
int clear_bits_to_right(int nbr, int position);
int toggle_bit(int nbr, int position);
int update_bit(int nbr, int position, int bit);
void ex_01();
void ex_02();
int bit_insertion(int n, int m, int i, int j);
int bit_insertion_2(int n, int m, int i, int j);
int flip_bit_to_win(int nbr);
int is_power_of_two(int nbr);
int flips_to_convert(int a, int b);
void test_5(int first, ...);
unsigned int pairwise_swap(unsigned int nbr);
int transform_subunitary(double nbr, char result[32], int *length);

#endif