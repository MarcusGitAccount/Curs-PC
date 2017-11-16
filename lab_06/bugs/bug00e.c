#include <stdlib.h>
#include <stdio.h>

//converts a hexadecimal number to decimal
//read the number until a new line is encountered

int toDecimal(char c){
    int ret = 0;
    if ( 'a' <= c && c <= 'f' )
        ret = c-'a'+10;
    else if ( 'A' <= c && c <= 'F' )
        ret = c-'A'+10;
    else
        ret = c-'0';
    return ret;
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
