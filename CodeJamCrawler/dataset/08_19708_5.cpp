#include<stdio.h>
#include<string.h>

bool u[101][101];
int f[101][101];

int main()
{
	int i,j,k;
	int t,p;
	int n,m;
	int a,b;
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small-attempt0.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d%d%d",&n,&m,&k);
		memset(u,true,sizeof(u));
		for (i=1;i<=k;i++)
		{
			scanf("%d%d",&a,&b);
			u[a][b]=false;
		}
		f[1][1]=1;
		for (j=2;j<=m;j++)
			f[1][j]=0;
		for (i=2;i<=n;i++)
		{
			f[i][1]=0;
			for (j=2;j<=m;j++)
				if (!u[i][j]) f[i][j]=0;
				else
				{
					f[i][j]=0;
					if (i>2&&j>1) f[i][j]=(f[i][j]+f[i-2][j-1])%10007;
					if (i>1&&j>2) f[i][j]=(f[i][j]+f[i-1][j-2])%10007;
				}
		}
		printf("Case #%d: %d\n",p,f[n][m]);
	}
	return 0;
}

