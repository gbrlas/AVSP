#include <stdio.h>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct data
{
    int w;
    bool f;
} a[200];

int cmp(data a,data b)
{
    return a.w<b.w;
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("a.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
       int n,s,p;
       scanf("%d%d%d",&n,&s,&p);
       for(int i=0;i<n;i++) 
       {
          scanf("%d",&a[i].w);
          int tmp=a[i].w%3;
          a[i].w/=3;
          int tt=a[i].w;
          if(tmp) a[i].w++;
          if(tmp==1||!tt) a[i].f=0; else a[i].f=1;
       }
       
       sort(a,a+n,cmp);
       
       int ans=0;
       for(int i=n-1;i>=0;i--)
       {
           if(a[i].w>=p) {ans++;continue;}
           if(!s) break;
           if(a[i].f&&a[i].w+1>=p)
           {
              s--;
              ans++;
           }
       }
       
       printf("Case #%d: %d\n",ca,ans);
    }
}
           
    
