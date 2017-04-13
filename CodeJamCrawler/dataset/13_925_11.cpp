#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
#define asdf 50000000000000LL
#define qwer 10000000000000000LL 
LL r,t;
LL sqr(LL x)
{
  return x*x;
}
bool ok(LL n)
{
               LL a1,an;
               a1=2*r+1; an=2*r+4*n-3;
               long long tmp=n*r*2+n*(2*n-1);
               if(tmp<0)return false;
               return tmp<=t;
     
}
int main()
{
    int T;
    freopen("1.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    for(int cas=1;cas<=T;++cas)
    {
            scanf("%I64d%I64d",&r,&t);
            LL L=1,R=1000000000,n;
            if(r>=asdf)R=20000;
            if(r>=qwer)R=50;
            while(R-L>1)
            {
               n=L+(R-L)/2;
               if(ok(n))L=n;
               else R=n-1;
            }
            while(ok(n) && ok(n+1))++n;
            while(!ok(n) && n>0)--n;
            printf("Case #%d: %I64d\n",cas,n);
    }
    return 0;
}
