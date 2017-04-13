#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    freopen("C-small-attempt0.in","rt",stdin);
    freopen("C-small-attempt0.out","wt",stdout);
    int t,i,r,k,n,j,cost,m,sum,s,p,a;
    scanf("%d",&t);
    for (i=0;i<t;i++) {
        scanf("%d",&r);
        scanf("%d",&k);
        scanf("%d",&n);
        int g[n];
        for (j=0;j<n;j++) scanf("%d",&g[j]);
        cost=0;
        s=0;
        a=0;
        for (m=0;m<r;m++) {
            sum=0;
            p=1;
            while (p==1) {
                  a=a+1;
                  sum=sum+g[s];
                  if (sum>k) {
                        p=0;
                        a=0;
                  }
                  else if (s==n-1) {
                       cost=cost+g[s];
                       s=0;
                  }
                  else {
                       cost=cost+g[s];
                       s=s+1;
                  }
                  if (a==n) {
                            p=0;
                            a=0;
                  }
            }
        }
        printf("Case #%d: %d\n", i+1, cost);
        cost=0;
    }
                  
                       
                       
                             

    return 0;
}


