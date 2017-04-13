#include <stdio.h>
const int maxn=50;
int a[maxn][maxn],v[maxn],i,j,k,n,m,p,q,t,ans;
void dfs(int i,int j)
{
	v[i]=j;
	if (j==1)
	{
		m=0;
		for (j=1;j<n;j++)
		{
			for (k=1;k<i;k++)
				if (a[j][v[k]]==1) break;
			if (k<i) m++;
		}
		if (m>ans) 
			ans=m;
	} else
	for (int h=1;h<n;h++)
		if ((a[h][j]==1)&&(a[h][1]==a[j][1]-1)) dfs(i+1,h);
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	for (int count_t=1;count_t<=t;++count_t)
	{
		scanf("%d%d",&n,&m);
		for (i=0;i<n;i++)
			for (j=0;j<n;j++) 
				if (i!=j) a[i][j]=maxn;
				else a[i][j]=0;
		for (i=0;i<m;i++)
		{
			scanf("%d,%d",&j,&k);
			a[j][k]=1;
			a[k][j]=1;
		}
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				for (k=0;k<n;k++)
					if (a[j][k]>a[j][i]+a[i][k])
						a[j][k]=a[j][i]+a[i][k];
		ans=0;
		dfs(1,0);
		printf("Case #%d: %d %d\n",count_t,a[0][1]-1,ans-a[0][1]+1);
	}
}