#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;
template <class T> void out(T x, int n){  for(int i = 1; i <= n; ++i)  cout << x[i] << ' ';    cout << endl;    }
template <class T> void out(T x, int n, int m){  for(int i = 1; i <= n; ++i)    out(x[i], m);    cout << endl;    }
#define OUT(x) (cout << #x << " = " << x << endl)
#define  Set(a,b)  memset(a,b,sizeof(a))
#define  LL long long
#define  eps 1e-8
#define  pi  acos(-1)
const int maxn = 5005,INF = 0x7fffffff;

int n,m,p_cur;
char str[maxn][20],p[maxn];
bool ok(char c)
{
      if(p[p_cur]!='(')
      {
          if(p[p_cur]==c) {p_cur++; return 1;}
          else {p_cur++;return 0;}
      }
      else
      {
          bool f=0;
          p_cur++;
          while(p[p_cur]!=')')
          {
                if(p[p_cur]==c) f=1;
                p_cur++;
          }
          p_cur++;
          if(f)  return 1;
          else return 0;
      }
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.out","w",stdout);
    int i,j,k,t,T,x,y,sum,index;
    int l,ans;
    while(cin>>l>>n>>m)
    {
         for(i=1;i<=n;i++)
            scanf("%s",str[i]+1);
         for(i=1;i<=m;i++)
         {
            scanf("%s",p+1);
            ans=0;
            for(j=1;j<=n;j++)
            {
                 p_cur=1;
                 for(k=1;k<=l;k++)
                    if(!ok(str[j][k]))  break;
                 if(k>l)   ans++;
            }
            printf("Case #%d: %d\n",i,ans);
         }
    }
    return 0;
}
