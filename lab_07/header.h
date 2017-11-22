#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>

void  init(char** tabla);
void print(char** tabla);
void make_move(char** tabla, int start_linie, char start_col, int fin_linie, char fin_col);
#endif