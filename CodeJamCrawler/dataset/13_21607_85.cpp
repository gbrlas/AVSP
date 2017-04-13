#include<stdio.h>

int a[101][101];

int main()
{
	int t,p;
	int n,m;
	int i,j,k;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d%d",&n,&m);
		for (i=1;i<=n;i++)
			for (j=1;j<=m;j++)
				scanf("%d",&a[i][j]);
		bool flag=true;
		for (i=1;i<=n;i++)
			for (j=1;j<=m;j++)
			{
				bool ff=false;
				for (k=1;k<=m;k++)
					if (a[i][k]<a[i][j]) break;
				if (k==m+1) ff=true;
				for (k=1;k<=n;k++)
					if (a[k][j]<a[i][j]) break;
				if (k==n+1) ff=true;
				if (ff)
				{
					for (k=1;k<=m;k++)
						if (a[i][k]>a[i][j]) break;
					if (k==m+1) ff=false;
					for (k=1;k<=n;k++)
						if (a[k][j]>a[i][j]) break;
					if (k==n+1) ff=false;
					if (ff) flag=false;
				}
			}
		if (flag) printf("Case #%d: YES\n",p);
		else printf("Case #%d: NO\n",p);
	}
	return 0;
}
