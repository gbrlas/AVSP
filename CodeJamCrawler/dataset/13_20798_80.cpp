#include <iostream>
using namespace std;
int a[105][105];
int b[105][105];
int main()
{
	int t,z;
	scanf("%d",&t);
	for (z=1;z<=t;z++)
	{
		int i,j,k,l,n,m;
		scanf("%d %d",&n,&m);
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=m;j++)
			{
				scanf("%d",&a[i][j]);
				b[i][j]=100;
			}
		}
		for (i=1;i<=n;i++)
		{
			k=0;
			for (j=1;j<=m;j++)
			{
				k=max(k,a[i][j]);
			}
			for (j=1;j<=m;j++)
			{
				b[i][j]=min(b[i][j],k);
			}
		}
		for (i=1;i<=m;i++)
		{
			k=0;
			for (j=1;j<=n;j++)
			{
				k=max(k,a[j][i]);
			}
			for (j=1;j<=n;j++)
			{
				b[j][i]=min(b[j][i],k);
			}
		}
		bool f=1;
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=m;j++)
			{
				if (a[i][j]!=b[i][j])
				{
					f=0;
					break;
				}
			}
			if (!f) {break;}
		}
		if (f) {printf("Case #%d: YES\n",z);} else {printf("Case #%d: NO\n",z);}
	}
}