#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <string.h>
#include <memory.h>
using namespace std;
template <class T> void OUT(T x, int n){  for(int i = 1; i <= n; ++i)  cout << x[i] << ' ';    cout << endl;    }
template <class T> void OUT(T x, int n, int m){  for(int i = 1; i <= n; ++i)    out(x[i], m);    cout << endl;    }
template <class T> void checkmod(T& a,T m){ a=(a%m+m)%m;}
#define  eps 1e-8
#define  LL long long
inline LL mod(LL x, LL y) { return x - floor(1.0 * x / y+eps) * y; }
#define  out(x) (cout << #x << " = " << x << endl)
#define  Set(a,b)  memset(a,b,sizeof(a))
#define  Sqr(x) ((x) * (x))
#define  pi  acos(-1.0)
const int maxn = 10005,INF = 0x7fffffff;

int n,m;
int list[maxn],flag[maxn];
int min_v;
int exist[maxn];
void solve(int sum,int c)
{
//   OUT(flag,m);
//   cout<<min_v<<endl;;
   if(c==m)
   {
      if(sum<min_v)  min_v=sum;
      return ;
   }
   if(sum>min_v) return ;
   for(int i=1;i<=m;i++)
      if(flag[i]==0)
      {
          int j=list[i]-1,v=0;
          while(j>=1&&exist[j]==0)  v++,j--;
          j=list[i]+1;
//          out(j);
          while(j<=n&&exist[j]==0)  v++,j++;
//          out(j);
          flag[i]=1;
          exist[list[i]]=1;
//          out(v);
          solve(sum+v,c+1);
          flag[i]=0;
          exist[list[i]]=0;
      }
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.out","w",stdout);
    int i,j,k,t,T,x,y,sum,index;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=m;i++)
            scanf("%d",list+i);
        min_v=INF;Set(flag,0);Set(exist,0);
        solve(0,0);
        printf("Case #%d: %d\n",t,min_v);
    }
    return 0;
}
