#include <stdlib.h>
stdin = fopen("stdin", "r");

//converts a hexadecimal number to decimal
//read the number until a new line is encountered
#include <stdio.h>

int toDecimal(char c){
  if ( 'a' <= c && c <= 'f' )
    return c-'a'+10;
  if ( 'A' <= c && c <= 'F' )
    return c-'A'+10;
  if ( '0' <= c && c <= '9' )
    return c - 48;
}

int main(void){
  char c='x';
  long long nr = 0;
  while(1){
    scanf("%c",&c);
    if (c=='\n')
        break;
    nr = 16*nr + toDecimal(c);
  }
  printf("\n%lld\n", nr);
  return 0;
}
