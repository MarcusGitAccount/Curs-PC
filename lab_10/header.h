#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include <string.h>

  unsigned int str_len(char* str);
  char* str_chr(char* str, char character);
  unsigned int find_char1(char* str, char character);
  unsigned int find_char2(char* str, char character);
  void del_char(char* str, unsigned int position);
  //void del_all(char* str, char character);
  void del_all(char* str, bool (*f)(char));
  bool is_lower(char c);
  bool is_upper(char c);
  void insert(char* str, unsigned int position, char character);
  char* sub_str1(char* str, unsigned int start, unsigned int end);
  char* sub_str2(char* str, unsigned int start, unsigned int length);
  
#endif