#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 10010;
int op[MAXN];
int val[MAXN];
int change[MAXN];
int opt[MAXN][2];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t,it;
	scanf("%d",&t);
	for (it=0;it<t;it++)
	{		
		int n,v;
		scanf("%d%d",&n,&v);
		for (int i=0;i<(n-1)/2;i++)
			scanf("%d%d",&op[i],&change[i]);
		for (int i=(n-1)/2;i<n;i++)
		{
			scanf("%d",&val[i]);
			opt[i][val[i]]=0;
			opt[i][1-val[i]]=10010;
		}
		for (int i=(n-1)/2-1;i>=0;i--)
		{
			int and0,and1,or0,or1;
			and0=min(opt[2*i+1][0]+opt[2*i+2][1],opt[2*i+1][1]+opt[2*i+2][0]);
			and0=min(and0,opt[2*i+1][0]+opt[2*i+2][0]);
			and1=opt[2*i+1][1]+opt[2*i+2][1];
			or0=opt[2*i+1][0]+opt[2*i+2][0];
			or1=min(opt[2*i+1][0]+opt[2*i+2][1],opt[2*i+1][1]+opt[2*i+2][0]);
			or1=min(or1,opt[2*i+1][1]+opt[2*i+2][1]);
			if (!change[i])
			{
				if (op[i]==0)
				{
					opt[i][0]=or0;
					opt[i][1]=or1;
				}
				else
				{
					opt[i][0]=and0;
					opt[i][1]=and1;
				}
			}
			else
			{
				if (op[i]==0)
				{
					opt[i][0]=min(or0,and0+1);
					opt[i][1]=min(or1,and1+1);
				}
				else
				{
					opt[i][0]=min(and0,or0+1);
					opt[i][1]=min(and1,or1+1);
				}
			}
		}
		int ans=opt[0][v];
		if (ans<=10000)
			printf("Case #%d: %I64d\n",it+1,ans);
		else
			printf("Case #%d: IMPOSSIBLE\n",it+1);
	}
	return 0;
}