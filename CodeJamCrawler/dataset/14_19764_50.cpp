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

string a[10];
int s[10],p[201][26];
int n,m,ans,cnt,tot;

void ins(int now,string t)
{
   char c=t[0];
   if (!p[now][c])
      p[now][c]=++tot;
   if (t.size()>1)
      ins(p[now][c],t.substr(1,t.size()-1));
}

void dfs(int now)
{
   if (now>n)
   {
      int ss=0;
      for (int i=1;i<=m;i++)
      {
         memset(p,0,sizeof(p));
         tot=1;
         for (int j=1;j<=n;j++)
            if (s[j]==i)
               ins(1,a[j]);
         ss+=tot;
         if (tot==1)
            return;
      }
      if (ss>ans)
      {
         ans=ss;
         cnt=0;
      }
      if (ss==ans)
         cnt++;
   }
   else
      for (int i=1;i<=m;i++)
      {
         s[now]=i;
         dfs(now+1);
      }
}

int main()
{
   freopen("a.in","r",stdin);
   freopen("a.out","w",stdout);
   int qq;
   cin>>qq;
   for (int tt=1;tt<=qq;tt++)
   {
      printf("Case #%d: ",tt);
      cin>>n>>m;
      for (int i=1;i<=n;i++)
         cin>>a[i];
      ans=cnt=0;
      dfs(1);
      cout<<ans<<' '<<cnt<<endl;
   }
   return 0;
}
