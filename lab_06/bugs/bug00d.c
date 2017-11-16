#include <stdlib.h>
#include <stdio.h>

//converts a hexadecimal number with k<=10 digits to decimal

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
  int k = 0;
  long long nr = 0;
  
  stdin = fopen("stdin", "r");
  scanf("%d",&k);
  printf("Number of digits: %d\n", k);
  for(int i=0; i<k; i++){
    scanf(" %c",&c);
    printf("%c %d %lld\n", c, toDecimal(c), nr);
    nr = 16*nr + toDecimal(c);
  }
  printf("\n%lld\n", nr);
  return 0;
}
