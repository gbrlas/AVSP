#include<stdio.h>

long long ban[64];

int main()
{
	int t,p;
	int n,i;
	long long s,m;
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d",&n);
		scanf("%lld",&m);
		s=1LL<<n;
		ban[n]=1;
		for (i=n-1;i>=1;i--)
			ban[i]=ban[i+1]*2;
		long long high=s;
		long long low=1;
		long long mid;
		while (high>low)
		{
			mid=(low+high+1)/2;
			long long pai=0;
			long long hou=mid-1;
			i=1;
			while (hou>=1)
			{
				hou--;
				hou=hou/2;
				pai=pai+ban[i];
				i++;
			}
			if (pai+1<=m) low=mid;
			else high=mid-1;
		}
		printf("Case #%d: %lld",p,low-1);
		high=s;
		low=1;
		while (high>low)
		{
			mid=(low+high+1)/2;
			long long pai=s;
			long long hou=s-mid;
			while (hou>=1)
			{
				hou--;
				hou=hou/2;
				pai=pai/2;
			}
			if (pai<=m) low=mid;
			else high=mid-1;
		}
		printf(" %lld\n",low-1);
	}
	return 0;
}

