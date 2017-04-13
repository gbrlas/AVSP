#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <deque>
#include <bitset>
#include <string>
#include <vector>
#include <sstream>
#define zero(a) (abs(a)<eps)
#define lowbit(a) ((a)&(-(a)))
#define abs(a) ((a)>0?(a):(-(a)))
#define dj(x1,y1,x2,y2) ((x1)*(x2)+(y1)*(y2))
#define cj(x1,y1,x2,y2) ((x1)*(y2)-(x2)*(y1))
#define dis(x1,y1,x2,y2) (((x2)-(x1))*((x2)-(x1))+((y2)-(y1))*((y2)-(y1)))
const double eps = 1e-9;
const double pi = acos(-1);
const int oo = 1000000000;
const int mod = 1000000007;
const double E = 2.7182818284590452353602874713527;
using namespace std;

struct case1
{
   int a,p;
}p[1005];
int x[1005],y[1005];

bool cmp(case1 a,case1 b)
{
   return a.a<b.a;
}

int main()
{
   freopen("a.in","r",stdin);
   freopen("a.out","w",stdout);
   int qq;
   cin>>qq;
   for (int tt=1;tt<=qq;tt++)
   {
      int n;
      printf("Case #%d: ",tt);
      cin>>n;
      for (int i=1;i<=n;i++)
      {
         scanf("%d",&p[i].a);
         p[i].p=i;
      }
      sort(p+1,p+n+1,cmp);
      for (int i=1;i<=n;i++)
      {
         x[i]=i-1;
         y[i]=n-i;
      }
      int ans=0;
      for (int i=1;i<=n;i++)
      {
         ans+=min(x[p[i].p],y[p[i].p]);
         for (int j=1;j<p[i].p;j++)
            y[j]--;
         for (int j=p[i].p+1;j<=n;j++)
            x[j]--;
      }
      cout<<ans<<endl;
   }
   return 0;
}
