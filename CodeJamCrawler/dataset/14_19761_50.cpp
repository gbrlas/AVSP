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
   int x0,y0,x1,y1;
}p[2005];
int head[10005],next[4000005],e[4000005],v[400005],d[30000001];
long long f[10005];
bool hash[10005];
int totm;

void add(int a,int b,int c)
{
   e[++totm]=b;
   next[totm]=head[a];
   head[a]=totm;
   v[totm]=c;
}

int main()
{
   freopen("a.in","r",stdin);
   freopen("a.out","w",stdout);
   int qq;
   cin>>qq;
   for (int tt=1;tt<=qq;tt++)
   {
      int w,h,b;
      printf("Case #%d: ",tt);
      totm=0;
      memset(head,0,sizeof(head));
      cin>>w>>h>>b;
      for (int i=1;i<=b;i++)
      {
         scanf("%d%d%d%d",&p[i].x0,&p[i].y0,&p[i].x1,&p[i].y1);
         add(1,i+1,p[i].x0);
         add(i+1,1,p[i].x0);
         add(i+1,b+2,w-1-p[i].x1);
         add(b+2,i+1,w-1-p[i].x1);
      }
      add(1,b+2,w);
      add(b+2,1,w);
      for (int i=1;i<b;i++)
         for (int j=i+1;j<=b;j++)
         {
            add(i+1,j+1,max(max(max(p[i].x0-p[j].x1-1,p[j].x0-p[i].x1-1),0),max(max(p[i].y0-p[j].y1-1,p[j].y0-p[i].y1-1),0)));
            add(j+1,i+1,max(max(max(p[i].x0-p[j].x1-1,p[j].x0-p[i].x1-1),0),max(max(p[i].y0-p[j].y1-1,p[j].y0-p[i].y1-1),0)));
         }
      int st=1,en=1;
      d[st]=1;
      hash[1]=1;
      for (int i=2;i<=b+2;i++)
         f[i]=1LL*oo*oo;
      while (st<=en)
      {
         int now=d[st++];
         hash[now]=0;
         for (int i=head[now];i;i=next[i])
            if (f[e[i]]>f[now]+v[i])
            {
               f[e[i]]=f[now]+v[i];
               if (!hash[e[i]])
               {
                  hash[e[i]]=1;
                  d[++en]=e[i];
               }
            }
      }
      cout<<f[b+2]<<endl;
   }
   return 0;
}
