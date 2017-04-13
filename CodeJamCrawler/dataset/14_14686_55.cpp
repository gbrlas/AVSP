#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int t; scanf("%d",&t);
	for(int cc=1;cc<=t;cc++)
	{
		printf("Case #%d: ",cc);
		double nao[1005],ken[1005];
		int n; scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%lf",&nao[i]);
		for(int i=1;i<=n;i++) scanf("%lf",&ken[i]);
		sort(nao+1,nao+n+1,greater<double>());
		sort(ken+1,ken+n+1,greater<double>());
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				bool ok=true;
				for(int k=j;k<=n;k++)
				{
					if(nao[k-j+1] < ken[k]) ok=false;
				}
				if(ok)
				{
					printf("%d ",n-j+1);
					goto nxt;
				}
			}
		}
		printf("%d ",0);
		nxt:;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				bool ok=true;
				for(int k=j;k<=n;k++)
				{
					if(ken[k-j+1] < nao[k]) ok=false;
				}
				if(ok)
				{
					printf("%d\n",j-1);
					goto nxt2;
				}
			}
		}
		printf("%d\n",n);
		nxt2:;
	}
}