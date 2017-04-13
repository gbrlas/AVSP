#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <cmath>

__int64 hh[500005];
int a[1005];
int cnt;
int tmp[1005];

bool isf(__int64 n)
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

void dfs(int n,int k)
{
     if(2*k>=n)
     {
        __int64 num=0;
        for(int i=0;i<n;i++) num=num*10+tmp[i];
        __int64 num2=num*num;
        if(isf(num2)) hh[cnt++]=num2;
        return;
     }       
     
     for(int i=k==0?1:0;i<3;i++)
     {
        tmp[k]=i;
        tmp[n-k-1]=i;
        dfs(n,k+1);
     }
}
         

void init()
{
     cnt=0;
     for(int i=1;i<=10000;i++)
     {
            int j=i*i;
            if(isf(i)&&isf(j))  hh[cnt++]=j;
     }
     
     for(int i=5;i<10;i++) dfs(i,0);
}

int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    
    init();
    
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        __int64 a,b;
        scanf("%lld%lld",&a,&b);
        
        int i=0;
        while(hh[i]<a) i++;
        int ans=0;
        while(hh[i]<=b)
        {
        //   printf("%I64d %I64d\n",hh[i],(__int64)sqrt(hh[i]));
           ans++;i++;
        }
        
        
        printf("Case #%d: %d\n",ca,ans);
    }
}
        
