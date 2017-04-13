#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

struct Node
{
	int p,n;
}node[220];
int C,D;

bool cmp(const Node &a,const Node &b)
{
	return a.p<b.p;
}

bool check(long long t)
{
	long long l=node[0].p-t-D;
	for(int i=0;i<C;i++)
	{
		l+=D;
		if(node[i].p-t>l)
			l=node[i].p-t;
		long long tmp=l+(node[i].n-1)*D;
		if(tmp-node[i].p>t)
			return false;
		l=tmp;
	}
	return true;
}

bool check2(double t)
{
	double l=node[0].p-t-D;
	for(int i=0;i<C;i++)
	{
		l+=D;
		if(node[i].p-t>l)
			l=node[i].p-t;
		double tmp=l+(node[i].n-1)*D;
		if(tmp-node[i].p>t)
			return false;
		l=tmp;
	}
	return true;
}

int main()
{
	int T;
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		scanf("%d%d",&C,&D);
		for(int i=0;i<C;i++)
			scanf("%d%d",&node[i].p,&node[i].n);
		sort(node,node+C,cmp);

		long long low=0,high=100001;
		double ans=0;
		if(check(0))
			ans=0;
		else
		{
			while(low<=high)
			{
				long long mid=(low+high)/2;
				if(check(mid))
				{
					high=mid-1;
					ans=mid;
				}
				else
					low=mid+1;
			}
		}
		if(check2(ans-0.5))
			ans=ans-0.5;
		printf("Case #%d: %.1lf\n",tt,ans);
	}
	return 0;
}
