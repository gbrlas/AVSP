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

int a[101][101],m1[101],m2[101];

int main()
{
   freopen("a.in","r",stdin);
   freopen("a.out","w",stdout);
   int q;
   cin>>q;
   for (int tt=1;tt<=q;tt++)
   {
      int n,m;
      bool flag=1;
      cin>>n>>m;
      for (int i=1;i<=n;i++)
         m1[i]=-oo;
      for (int i=1;i<=m;i++)
         m2[i]=-oo;
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
         {
            scanf("%d",&a[i][j]);
            m1[i]=max(m1[i],a[i][j]);
            m2[j]=max(m2[j],a[i][j]);
         }
      for (int i=1;i<=n;i++)
         for (int j=1;j<=m;j++)
            if (a[i][j]!=min(m1[i],m2[j]))
               flag=0;
      printf("Case #%d: %s\n",tt,flag?"YES":"NO");
   }
   return 0;
}
