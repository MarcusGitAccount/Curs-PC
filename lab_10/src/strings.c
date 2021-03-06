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

int find_char(char* str, char character) {
  unsigned int index = 0;
  
  // printf("Have to find: %c in \"%s\" \n", character, str);
  while (str[index] != character && str[index] != 0)
    index++;
  
  // printf("Position: %c\n", str[index]);
  if (str[index] == '\0')
    return -1;
  return index;
}

int find_char_rev(char* str, char character) {
  int index = str_len(str);
  
  while (str[index] != character && index >= 0)
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
  unsigned int size  = str_len(str);

  for (unsigned int i = size; i > position; i--)
    str[i] = str[i - 1];

  str[position] = character;
  str[size + 1] = '\0';
}

char* sub_str1(char* str, unsigned int start, unsigned int end) {
  char* result = malloc(start - end);
  unsigned int index = start;
  
  if (start >= end || start < 0 || end < 0)
    return NULL;
  
  while (index < end) {
    result[index - start] = str[index];
    index++;
  }
  
  result[index] = '\0';
  return  result;
}

char* sub_str2(char* str, unsigned int start, unsigned int length) {
  return sub_str1(str, start, start + length);
}

int str_str(char* source, char* substr) {
  unsigned int index, i, j;

  index = 0;
  while (source[index] != '\0') {
    if (source[index] == substr[0]) {
      i = index;
      j = 0;

      while (source[i] != 0 && substr[j] != 0 && source[i] == substr[j]) {
        i++;
        j++;
      }

      if (substr[j] == '\0')
        return index;
    }

    index++;
  }

  return -1;
}

int str_cmp(char* first, char* second) {
  unsigned int i, j;

  i = j = 0;
  while (first[i] != '\0' && second[j] != '\0' && first[i] == second[j]) {
    i++, j++;
  }

  return first[i] - second[j];
}

char* str_cat(char* first, char* second) {
  unsigned int size_first  = str_len(first);
  unsigned int size_second = str_len(second);
  unsigned int index = 0;
  char* result = malloc(size_first + size_second - 1);

  for (unsigned int i = 0; i < size_first; i++)
    result[index++] = first[i];
  for (unsigned int i = 0; i <= size_second; i++)
    result[index++] = second[i];

  return result;
}

void del_substr(char* str, unsigned int start, unsigned int end) {
  if (start >= end)
    return;

  while (str[end] != 0) {
    str[start++] = str[end++];
  }

  str[start] = '\0';
}

void replace_str(char* destination, char* target, char* replace) {
  int last, next;
  unsigned int t_size = str_len(target);
  unsigned int r_size = str_len(replace);
  unsigned int i, j, padding_right;

  next = last = str_str(destination, target);
  while (next != -1) {
    i = j = 0;
    while (i < t_size && j < r_size) {
      destination[i + last] = replace[j];
      i++;
      j++;
    }

    padding_right = 0;
    last += i;
    while (i < t_size) {
      del_char(destination, last);
      i++;
      padding_right++;
    }
    while (j < r_size) {    
      insert(destination, last, replace[j]);
      last++;
      j++;
    }

    // float int
    last += padding_right;
    next = str_str(destination + last, target);
    last = last + next;
  }
}

char* str_tok(char* str, char* delimiters) {
  static char* str_left = NULL;
  unsigned int i, j, start;
  char* result;

  if (str != NULL) {
    const unsigned int size = str_len(str);
    unsigned int index;

    free(str_left);
    str_left = malloc(size);

    for (index = 0; index < size; index++)
      str_left[index] = str[index];
    str_left[index] = '\0';
  }

  // printf("Current: %s\n", str_left);
  if (str_left == NULL)
    return NULL;

  i = 0;
  while (find_char(delimiters, str_left[i]) != -1 && str_left[i] != 0)
    i++;

  start = i;
  while (find_char(delimiters, str_left[i]) == -1 && str_left[i] != 0)
    i++;

  result = sub_str1(str_left, start, i);
  for (j = i; str_left[j] != '\0'; j++)
    str_left[j - i] = str_left[j];
  str_left[j - i] = '\0';

  if (*str_left == '\0')
    str_left = NULL;

  return result;
}

char** separate_path(char* path, unsigned int* total) {
  char delimiters[] = "\\.:";
  char** result; 
  char*  current;
  unsigned int size = 0;

  for (unsigned int i = 0; path[i] != 0; i++) {
    if (find_char(delimiters, path[i]) > -1)
      size++;
  }

  if (size == 0) {
    size = *total = 1;
    result = malloc(sizeof(char**) * 1);
    result[0] = path;

    return result;
  }

  result = malloc(sizeof(char**) * size);   
  current = str_tok(path, delimiters);
  for (unsigned int i = 0; i < size; i++) {
    result[i] = current;
    current = str_tok(NULL, delimiters);
  }
  
  *total = size;
  return result;
}

void sort_strings(char** array, int left, int right) {
  int start, end;
  char* pivot = array[(left + right) / 2];

  start = left;
  end = right;

  while (start <= end) {
    while (str_cmp(array[start], pivot) < 0)
      start++;
    while (str_cmp(pivot, array[end]) < 0)
      end--;

    if (start <= end) {
      char* temp = array[start];

      array[start] = array[end];
      array[end] = temp;
      start++;
      end--;
    }

    if (end > left)
      sort_strings(array, left, end);
    if (start < right)
      sort_strings(array, start, right);
  }
}

void problem_14() {
  unsigned int size;
  char** array;

  scanf("%u", &size);

  array = malloc(sizeof(char*) * size);
  for (unsigned i = 0; i < size; i++) {
    array[i] = malloc(75);
    scanf("%s", array[i]);
  }

  sort_strings(array, 0, size - 1);

  for (unsigned i = 0; i < size; i++) {
    printf("%d: %s\n", i, array[i]);
  }

  for (unsigned int i = 0; i < size; i++)
    free(array[i]);
  free(array);
}

unsigned int code_combinations(int* weights, unsigned int size, unsigned int digit) {
  int current;

  if (size == 0)
    return (digit == 0) ? 1 : 0;

  current = weights[size - 1];
  return code_combinations(weights, size - 1, digit) + code_combinations(weights, size - 1, digit - current);
}