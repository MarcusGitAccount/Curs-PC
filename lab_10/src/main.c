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

  if (argc == 3) {  
    char str[50] = "float x, y; float z; int x = 2";

    printf("Replacement before: %s\n", str);
    replace_str(str, argv[1], argv[2]);
    printf("Replacement after: %s\n", str);
  }
  
  // char str[] = "for(int i=0";

  // del_substr(str, 4, 8);
  // del_substr(str, 0, 4);
  // printf("%s\n", str);


  // insert(str, 2, 'A');
  // insert(str, 2, 'A');
  // insert(str, 2, 'A');
  // insert(str, 2, 'A');
  // insert(str, 2, 'A');
  return 0;
}