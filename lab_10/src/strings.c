#include "header.h"

unsigned int str_len(char* str) {
  unsigned int index;
  
  index = 0;
  while (str[index])
    index++;

  return index;
}

char* str_chr(char* str, char character) {
  unsigned index = 0;
  
  while (str[index] != character && str[index] != 0)
    index++;
  
  return str + index;
}

unsigned int find_char1(char* str, char character) {
  unsigned index = 0;
  
  while (str[index] != character)
    index++;
  
  if (str[index] == 0)
    return -1;
  return index;
}

unsigned int find_char2(char* str, char character) {
  unsigned index = str_len(str);
  
  while (str[index] != character)
    index--;
  
  if (index < 0)
    return -1;
  return index;
}

void del_char(char* str, unsigned int position) {
  if (str[position] == 0 || position < 0)
    return;
  
  while (str[position] != 0) {
    str[position] = str[position + 1];
    position++;
  }
}

void del_all(char* str, bool (*check)(char)) {
  unsigned int index = 0;
  
  while (str[index] != 0) {
    if (check(str[index]) == true) {
      del_char(str, index);
      index--;
    }
    index++;
  }
}

bool is_lower(char c) {
  if (c >= 'a' && c <= 'z')
    return true;
  return false;
}

bool is_upper(char c) {
  if (c >= 'A' && c <= 'B')
    return true;
  return false;
}

void insert(char* str, unsigned int position, char character) {
  unsigned int index = position; 
  
  while (str[index] != 0) {
    str[index + 1] = str[index];
    index++;
  }
  
  str[position] = character;
}

char* sub_str1(char* str, unsigned int start, unsigned int end) {
  char* result = malloc(start - end);
  unsigned int index = start;
  
  if (start >= end || start < 0 || end < 0)
    return NULL;
  
  while (index < end) {TT
    result[index - start] = str[index];
    index++;
  }
  
  result[index] = '\0';
  return  result;
}

char* sub_str2(char* str, unsigned int start, unsigned int length) {
  return sub_str1(str, start, start + length);
}

unsigned int str_str(char* source, char* substr) {
  a
  
  return -1;
}