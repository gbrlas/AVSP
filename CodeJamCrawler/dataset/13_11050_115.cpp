#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <cmath>

int a[1005];

bool isf(int n)
{
     int u=0;
     while(n>0)
     {
         a[u++]=n%10;
         n=n/10;
     }
     bool r=1;
     for(int i=0;i<u;i++)
       if(a[i]!=a[u-1-i]){r=0;break;}
     return r;
}

int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        
        int cnt=0;
        for(int i=a;i<=b;i++)
        {
            int j=(int)sqrt(i);
            if(j*j==i)
            {
               if(isf(i)&&isf(j)) cnt++;
            }
        }
        
        printf("Case #%d: %d\n",ca,cnt);
    }
}
        
