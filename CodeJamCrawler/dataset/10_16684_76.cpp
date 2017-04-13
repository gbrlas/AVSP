#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int a;
  char str[5];
  int i;
  fgets(str, 10, stdin);
  a = atoi(str);
  for(i=0;i<a;i++) {
    int b,c;

    fscanf(stdin, "%d %d", &b, &c);
    if(c % (int)pow(2, b) == (int)pow(2,b) -1)
      printf("Case #%d: ON\n", i+1);
    else
      printf("Case #%d: OFF\n", i+1);
  }
}
