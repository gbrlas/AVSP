#include <stdio.h>
#include <string.h>

int use[101][256];
int v[101];
const int inf=100000000;

int myabs(int a)
{
	return a>0?a:-a;
}

int mymin(int a,int b)
{

	return a>b?b:a;
}

int finduse(int a,int b,int m)
{
	if(m==0)
	{
		if(a==b)
			return 0;
		else
			return inf;
	}
	if(myabs(a-b)%m==0)
		return myabs(a-b)/m;
	else
		return myabs(a-b)/m+1;
}
int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("small.out","w",stdout);
	int ins,del;
	int n,m;
	int cases;
	int icases;
	int i,j,k;
	scanf("%d",&cases);
	icases=1;
	
	while(icases<=cases)
	{
		scanf("%d %d %d %d",&del,&ins,&m,&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&v[i]);
			for(j=0;j<=255;j++)
				use[i][j]=inf;
		}
		for(i=0;i<=255;i++)
		{
			use[0][i]=myabs(v[0]-i);
			use[0][i]=mymin(del+ins,use[0][i]);
			if(m==0 && v[0]!=i)
				continue;
			use[0][i]=mymin(ins*finduse(v[0],i,m),use[0][i]);
		}
		for(i=1;i<n;i++)
		{
			for(j=0;j<=255;j++)
			{
				use[i][j]=mymin(use[i-1][j]+del,use[i][j]);
				for(k=0;k<=255;k++)
				{
					if(myabs(j-k)>m)
						continue;
					use[i][j]=mymin(use[i-1][k]+myabs(v[i]-j),use[i][j]);
					use[i][j]=mymin(use[i-1][k]+del+ins,use[i][j]);
				}
				if(m==0 && v[i]!=j)
					continue;
				for(k=0;k<=255;k++)
				{
					if(myabs(v[i]-k)>m)
						continue;
					use[i][j]=mymin(use[i-1][k]+ins*finduse(v[i],j,m),use[i][j]);
				}
			}
		}
		int ans=inf;
		for(i=0;i<=255;i++)
			ans=mymin(ans,use[n-1][i]);
		printf("Case #%d: %d\n",icases,ans);
		icases++;
	}
	return 0;
}