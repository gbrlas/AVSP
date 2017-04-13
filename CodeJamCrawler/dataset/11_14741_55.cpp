#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int t, c, d, n, i=0, j, a, k, l, m;
    char **op, **comb, lista[100];
    scanf(" %d", &t);
    while(i<t) {
         scanf(" %d", &c);
         if(c)
         comb=(char**)malloc(c*sizeof(char*));
         for(j=0; j<c; j++) {
             comb[j]=(char*)malloc(4*sizeof(char));
             scanf(" %s", comb[j]);
         }
         scanf(" %d", &d);
         if(d)
         op=(char**)malloc(d*sizeof(char*));
         for(j=0;j<d;j++) {
             op[j]=(char*)malloc(3*sizeof(char));
             scanf(" %s", op[j]);
         }
         scanf(" %d", &n);
           lista[0]='[';
         for(a=1, j=0;j<n;j++) {
           scanf(" %c", &lista[a]);
           lista[a+1]=',';
           lista[a+2]=' ';
           for(k=0; a>2 && k<c;k++) {
                if((comb[k][0]==lista[a] && comb[k][1]==lista[a-3]) || (comb[k][1]==lista[a] && comb[k][0]==lista[a-3]) ) {
                                          a-=3;
                                          lista[a]=comb[k][2];
                                          break;
                }
           }
           for(k=0;k<d;k++) {
               for(m=0, l=1;l<=a;l+=3)
                    if(op[k][0]==lista[l]){
                       m=1;
                       break;
                       }
               for(l=1;m==1 && l<=a; l+=3)
                     if(op[k][1]==lista[l]) 
                       m=2;
               if(m==2) {
                    a=-2;
                    break;
               }
           }
           a+=3;
         }
         if(a>2){
         lista[a-2]=']';
         lista[a-1]=0; 
         printf("Case #%d: %s\n", ++i, lista);
         }
         else printf("Case #%d: %s\n", ++i, "[]");
         for(j=0;j<c;j++) free(comb[j]);
         for(j=0;j<d;j++) free(op[j]);
         free(comb);
         free(op);
    }
    return 0;
}
    
