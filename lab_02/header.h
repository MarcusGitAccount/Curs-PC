#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>

# define PI 3.14159265358979323846

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

#endif