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

int main()
{
   freopen("b.in","r",stdin);
   freopen("b.out","w",stdout);
   int q;
   cin>>q;
   for (int tt=1;tt<=q;tt++)
   {
      int n;
      long long p,a1=0,a2=0;
      cin>>n>>p;
      printf("Case #%d: ",tt);
      if (p==(1LL<<n))
      {
         cout<<(1LL<<n)-1<<' '<<(1LL<<n)-1<<endl;
         continue;
      }
      for (int i=1;i<=n;i++)
         if ((1LL<<i)<=p)
            a2+=(1LL<<n-i);
      p=(1LL<<n)-p;
      for (int i=1;i<=n;i++)
         if ((1LL<<i)<=p)
            a1+=(1LL<<n-i);
      a1=(1LL<<n)-2-a1;
      cout<<a1<<' '<<a2<<endl;
   }
   return 0;
}
