#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

const int N=1010;
int T;
int n;
int a[N],b[N];
int f[N][N];
struct Node
{
  int key,no;
  bool operator < (const Node &A) const
  {
    return key<A.key;
  }
}node[N];
int tr[N];
int pre[N],back[N];

int lowbit(int x)
{
  return x&(-x);
}

void Add(int now,int del)
{
  while (now<=n)
    {
      tr[now]+=del;
      now+=lowbit(now);
    }
}

int Solve(int now)
{
  int res=0;
  while (now>0)
    {
      res+=tr[now];
      now-=lowbit(now);
    }
  return res;
}

int main()
{
  scanf("%d",&T);
  for (int ii=1;ii<=T;ii++)
    {
      scanf("%d",&n);
      for (int i=1;i<=n;i++)
	{
	  scanf("%d",&a[i]);
	  node[i].key=a[i]; node[i].no=i;
	}
      sort(node+1,node+n+1);
      for (int i=1;i<=n;i++) b[node[i].no]=i;
      memset(tr,0,sizeof(tr));
      for (int i=1;i<=n;i++)
	{
	  pre[i]=Solve(b[i]);
	  Add(b[i],1);
	}
      memset(tr,0,sizeof(tr));
      for (int i=n;i>=1;i--)
	{
	  back[i]=Solve(b[i]);
	  Add(b[i],1);
	}
      f[0][0]=0;
      int ans=2000000000;
      for (int i=1;i<=n;i++)
	for (int j=0;j<=i;j++)
	  {
	    int a,b;
	    a=b=2000000000;
	    if (j) a=f[j-1][i-j]+node[i].no-pre[node[i].no]-1;
	    if (i-j) b=f[j][i-j-1]+n-node[i].no-back[node[i].no];
	    f[j][i-j]=min(a,b);
	    if (i==n) ans=min(ans,f[j][i-j]);
	  }
      printf("Case #%d: %d\n",ii,ans);
    }
  return 0;
}
