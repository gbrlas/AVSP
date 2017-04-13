#include <stdio.h>
#include <stdlib.h>

int isRecycledPair(int c, int d) {
 char cc[10], cd[10], ctemp[10], tempChar;
 int len=0, i, j;
 if(c>=d) return(0);
 sprintf(cc, "%d", c);
 sprintf(cd, "%d", d);
 do {
  ctemp[len]=cc[len];
  len++;
 } while(cc[len-1]!='\0');
 len--;
 for(i=0;i<len;i++) {
  tempChar = ctemp[0];
  for(j=0;j<len-1;j++) {
   ctemp[j]=ctemp[j+1];
  }
  ctemp[len-1]=tempChar;
  if(strncmp(ctemp, cd, len)==0) return(1);
 }
 return(0);
}

int main(void) {
 int cases, a, b, n, m, count;
 int i;
 scanf("%d\n", &cases);
 for(i=0;i<cases;i++) {
  count=0;
  printf("Case #%d: ", i+1);
  scanf("%d %d\n", &a, &b);
  for(n=a;n<b;n++) {
   for(m=n+1;m<=b;m++) {
    //printf("Pair (%d,%d): %s\n", n, m, isRecycledPair(n,m)?"Yes!":"No.");
    if(isRecycledPair(n,m)) count++;
   }
  }
  printf("%d\n", count);
 } 
 return(0);
}
