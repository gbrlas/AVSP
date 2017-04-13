#include <stdio.h>
#include <stdlib.h>

int maxNormal(int tot) {
 if(tot==0) return(0);
 if(tot==1) return(1);
 if(tot==30) return(10);
 return((tot+2)/3);
}

int maxSurprise(int tot) {
 if(tot==0) return(0);
 if(tot==1) return(1);
 if(tot==2) return(2);
 if(tot==29) return(10);
 if(tot==30) return(10);
 return((tot+4)/3);
}

int main(void) {
 int cases, googlers, surprises, p, total, count, i, j;
 scanf("%d\n", &cases);
 //printf("Cases: %d\n", cases);
 for(i=0;i<cases;i++) {
  count=0;
  scanf("%d", &googlers);
  scanf(" %d", &surprises);
  scanf(" %d", &p);
  //printf("googlers: %d surprises: %d p: %d\n", googlers, surprises, p);
  for(j=0;j<googlers;j++) {
   scanf(" %d", &total);
   //printf("Googler %d, total %d\n", j+1, total);
   if(maxNormal(total)>=p) {
    count++;
    continue;
   } else if((surprises)&&(maxSurprise(total)>=p)) {
    surprises--;
    count++;
    continue;
   }
  }
  printf("Case #%d: ", i+1);
  printf("%d\n", count);
 } 
 return(0);
}
