#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
int ans=0,m[1200],p;
int solve(int now,int k)
{
	if (now==p)return m[k];
	int x=solve(now+1,k<<1);
	int y=solve(now+1,(k<<1)+1);
	if (x==0||y==0)
	{
		ans++;
		return 0;
	}
	return min(x-1,y-1);
}
int main()
{
	freopen("C:\\Users\\daizhy\\Documents\\output.txt","w",stdout);
	int i,j,k,cas,cc=0;
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d",&p);
		int lim=1<<p;
		for (i=0;i<lim;i++)
		{
			scanf("%d",m+i);
		}
		for (i=0;i<lim-1;i++)
		{
			scanf("%*d");
		}
		ans=0;
		solve(0,0);
		printf("Case #%d: %d\n",++cc,ans);
	}
	return 0;
}
