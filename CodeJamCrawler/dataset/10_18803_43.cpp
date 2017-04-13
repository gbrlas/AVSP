#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    freopen("A-small-attempt4.in","rt",stdin);
    freopen("A-small-attempt4.out","wt",stdout);
    int t,i,n,k,j,m,a,b;
    int bin[32];
    scanf("%d",&t);
    for (i=0;i<t;i++)  {
        scanf("%d", &n);
        scanf("%d", &k);
        for (j=0;j<32;j++) bin[j]=0;
        for (j=0;j<n;j++) {
             m=k/2;
             bin[j]=k-m*2;
             k=m;
        }
        a=1;
        for (b=0;b<n;b++) a=a*bin[b];        
        if (a==1) 
           printf("Case #%d: ON\n",i+1);
        else
           printf("Case #%d: OFF\n",i+1);
    }
    return 0;
}


