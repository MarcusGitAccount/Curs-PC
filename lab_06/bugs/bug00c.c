#include <stdlib.h>
#include <stdio.h>

//converts a hexadecimal number to decimal
//read the number until a new line is encountered

int toDecimal(char c){
  if ( 'a' <= c && c <= 'f' )
    return c-'a'+10;
  if ( 'A' <= c && c <= 'F' )
    return c-'A'+10;
  if ( '0' <= c && c <= '9' )
    return c-'0';
}

int main(void){
  char c='x';
  long long nr = 0;
  
  stdin = fopen("stdin", "r");
  while(c!='\n'){
    scanf("%c", &c);
    printf("%c %d %lld", c, toDecimal(c), nr);
    nr = 16*nr + toDecimal(c);
  }
  printf("\n%lld\n", nr / 16);
  return 0;
}
