#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <deque>
#define zero(a) (abs(a)<eps)
#define lowbit(a) ((a)&(-(a)))
#define abs(a) ((a)>0?(a):(-(a)))
#define cj(x1,y1,x2,y2) ((x1)*(y2)-(x2)*(y1))
#define dj(x1,y1,x2,y2) ((x1)*(x2)+(y1)*(y2))
#define dis(x1,y1,x2,y2) sqrt(((x2)-(x1))*((x2)-(x1))+((y2)-(y1))*((y2)-(y1)))
const double eps = 1e-9;
const int oo = 1000000000;
const double E = 2.7182818284590452353602874713527;
const double pi = 3.1415926535897932384626433832795;
using namespace std;

struct case1
{
   int x,l;
}p[10001];
int dis[10001],d[10000001];
bool hash[10001];

int main()
{
   freopen("a.in","r",stdin);
   freopen("a.out","w",stdout);
   int t;
   cin>>t;
   for (int q=1;q<=t;q++)
   {
      int n,x,st=1,en=0;
      cin>>n;
      for (int i=1;i<=n;i++)
         scanf("%d%d",&p[i].x,&p[i].l);
      cin>>x;
      memset(dis,0,sizeof(dis));
      dis[1]=p[1].x;
      d[++en]=1;
      while (st<=en)
      {
         int now=d[st++];
         hash[now]=0;
         for (int i=1;i<=n;i++)
            if (abs(p[i].x-p[now].x)<=dis[now])
            {
               int t=min(abs(p[i].x-p[now].x),p[i].l);
               if (t>dis[i])
               {
                  dis[i]=t;
                  if (!hash[i])
                  {
                     hash[i]=1;
                     d[++en]=i;
                  }
               }
            }
      }
      for (int i=1;i<=n;i++)
         if (x-p[i].x<=dis[i])
         {
            cout<<"Case #"<<q<<": YES"<<endl;
            goto end;
         }
      cout<<"Case #"<<q<<": NO"<<endl;
      end:;
   }
   return 0;
}
