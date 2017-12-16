#include "header.h"

void test_strlen() {
  char* tests[3] = {"Ana", "are mere", ""};
  
  for (unsigned int i = 0; i < 3; i++)
    printf("String: %s\nSize: %u\n", tests[i], str_len(tests[i]));
}

void test_strchr() {
  printf("%s\n", str_chr("Ana are mere", 'a'));
  printf("%s\n", str_chr("Ana nu are mere", 'z'));
}

/*void test_deletion() {
  char str[] = "Ana are mere";
  
 
  del_char(str, 1);
  del_char(str, 10);
  printf("After deleting characters from postions given: %s\n", str);

  printf("After deleting all the appearances of a character: %s\n", str);
  
  del_all(str, 'e');
  printf("After deleting all the appearances of a character: %s\n", str);
  
  del_all(str, 'r');
  printf("After deleting all the appearances of a character: %s\n", str);

  del_all(str, 'a');
  printf("After deleting all the appearances of a character: %s\n", str);
  
  del_all(str, 'A');
  printf("After deleting all the appearances of a character: %s\n", str);
  
  del_all(str, ' ');
  printf("After deleting all the appearances of a character: %s\n", str);
  
  del_all(str, 'n');
  printf("After deleting all the appearances of a character: %s\n", str);
  
  del_all(str, 'm');
  printf("After deleting all the appearances of a character: %s\n", str);
  
  del_all(str, 'a');
  printf("After deleting all the appearances of a character: %s\n", str);
}*/

void test_deletion_2() {
  char str[] = "Ana are mere multe, dar si pere deasemenea.";
  
  printf("Before:\n%s\n", str);
  del_all(str, &is_lower);
  printf("After:\n%s\n", str);
}

int main(int argc, char** argv) {
  // ctrl + k, ctrl + c => comment block
  // ctrl + k, ctrl + u => uncomment block
  // Home - get cursor to beggining of the line
  // End -  get cursor to the end of the line

  // test_strlen();
  // test_strchr();
  // test_deletion_2();
  
  // printf("Substr first: %s\n", sub_str1("not good", 4, 8));
  // printf("Substr first: %s\n", sub_str2("not good at all", 4, 4));

  // if (argc == 2) {  
  //   unsigned int size;
  //   char** split = separate_path(argv[1], &size);

  //   for (unsigned int i = 0; i < size; i++) {
  //     printf("%s\n", split[i]);
  //   }
  // }
  
  // char str[] = "for(int i=0";

  // del_substr(str, 4, 8);
  // del_substr(str, 0, 4);
  // printf("%s\n", str);


  // insert(str, 2, 'A');
  // insert(str, 2, 'A');
  // insert(str, 2, 'A');
  // insert(str, 2, 'A');
  // insert(str, 2, 'A');

  // char str[] = "c:\\Program Files\\CodeBlocks\\bin\\cb.exe";
  // char* delimiters = "\\.:";
 
  // char* piece = str_tok(str,  delimiters);
  // int i = 0;
  // while (piece != NULL) {
  //   printf("%s\n", piece);
  //   i++;
  //   piece = str_tok(NULL,  delimiters);
  // }

  problem_14();
  
  // int weights[] = {4, 2, 3, -1};
  // unsigned int size = 4;
  // unsigned int total = 1;

  // for (unsigned int digit = 0; digit < 10; digit++) {
  //   const int current = code_combinations(weights, size, digit);

  //   printf("Number of combinations for the given code and digit %u: %u\n", digit, current);
  //   total *= current;
  // }

  // printf("Number of total combinations for decimal digits: %u\n", total);

  // char a[50] = "Ana are mre";
  // char b[50] = "ba nu";
  // char* temp = a;

  // *a = *b;
  // *b = *temp;

  // printf("%s\n", a);
  // printf("%s\n", b);

  // int array[] = {2, -1, 5, 4, 3, 7, 10, 9};
  // unsigned int size = 8;

  // sort_numbers(array, 0, size - 1);
  // for (unsigned int i = 0; i < size; i++)
  //   printf("%d\n", array[i]);

  return 0;
}