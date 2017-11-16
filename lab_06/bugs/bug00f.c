#include <stdlib.h>
#include <stdio.h>

//converts a hexadecimal number to decimal
//read the number until a new line is encountered

int toDecimal(char c){
  switch(c){
    case 'a':
    case 'A': return 10;
    case 'b':
    case 'B': return 11;
    case 'c':
    case 'C': return 12;
    case 's':
    case 'D': return 13;
    case 'e':
    case 'E': return 14;
    case 'f':
    case 'F': return 15;
    default: return c-'0';
  }
}

int main(void){
  char c='x';
  long long nr = 0;
  
  stdin = fopen("stdin", "r");
  while(1){
    scanf("%c", &c);
    if (c=='\n')
        break;
    nr = 16*nr + toDecimal(c);
  }
  printf("\n%lld\n", nr);
  return 0;
}
