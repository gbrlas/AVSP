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

int s[1001];

int main()
{
   freopen("a.in","r",stdin);
   freopen("a.out","w",stdout);
   int qq;
   cin>>qq;
   for (int tt=1;tt<=qq;tt++)
   {
      int n,x;
      printf("Case #%d: ",tt);
      cin>>n>>x;
      memset(s,0,sizeof(s));
      for (int i=1;i<=n;i++)
      {
         int a;
         scanf("%d",&a);
         s[a]++;
      }
      int ans=0;
      for (int i=x;i>=0;i--)
         while (s[i])
         {
            int j=min(i,x-i);
            while ((j==i&&s[j]==1||!s[j])&&j>0)
               j--;
            s[i]--;
            if (j)
               s[j]--;
            ans++;
         }
      cout<<ans<<endl;
   }
   return 0;
}
