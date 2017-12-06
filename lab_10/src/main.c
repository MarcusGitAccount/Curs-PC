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

int main(void) {
  test_strlen();
  test_strchr();
  test_deletion_2();
  
  printf("Substr first: %s\n", sub_str1("not good", 4, 8));
  printf("Substr first: %s\n", sub_str2("not good at all", 4, 4));
  return 0;
}