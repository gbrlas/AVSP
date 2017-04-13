#include <stdio.h>
#include <stdlib.h>

int divide(int *v, int n, int soma, int c, int k, int sum) {
    int a=0, max=0, i;
    for(i=0;i<n;i++) {
         if(c) a=divide(v,n,soma^v[i],c-1,v[i]^k, sum-v[i]);
         else if ((soma^v[i])==(v[i]^k)) a=sum-v[i];
         if(a>max) max=a;
    }
    return max;
}         

int main(void) {
    int t, n, c[1000], i=0, j, soma=0, sum=0, x=0, tot=0;
    scanf(" %d",&t);
    while(i<t){
       tot=sum=x=soma=0;
       scanf(" %d", &n);
         for(j=0;j<n;j++) {
             scanf(" %d", &c[j]);
             soma^=c[j];
             tot+=c[j];
         }
         for(j=0; j<n/2;j++) {
              x=divide(c,n,soma,j, 0, tot);
              if(x>sum)sum=x;
         }
         if(sum) printf("Case #%d: %d\n",++i, sum);
         else  printf("Case #%d: NO\n",++i);          
    }
    return 0;
}
