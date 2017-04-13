# include <stdio.h>
# include <string.h>

int C,N,M;
int g[10005][15];

void Output(int t[])
{
	int i;
	for(i=1;i<=N;i++)
		printf(" %d",t[i]);
	printf("\n");
}
void solve()
{	
	int i,j,k,cnt;
	int taste[15];
	for(i=0;i<(1<<N);i++)
	{
		for(j=0;j<N;j++)
			if(i&(1<<j))
				taste[j+1]=1;
			else
				taste[j+1]=0;
		for(j=1;j<=M;j++)
		{
			cnt=0;
			for(k=1;k<=N;k++)
				if(g[j][k]==taste[k])
					cnt++;
			if(cnt==0)
				break;
		}
		if(j==M+1)
		{
			Output(taste);
			return ;
		}
	}
	printf(" IMPOSSIBLE\n");
}
	
int main()
{
	int i,j,t,num,fla,yn;
	scanf("%d",&C);
	for(t=1;t<=C;t++)
	{
		scanf("%d%d",&N,&M);
		memset(g,-1,sizeof(g));
		for(i=1;i<=M;i++)
		{
			scanf("%d",&num);
			for(j=0;j<num;j++)
			{
				scanf("%d%d",&fla,&yn);
				g[i][fla]=yn;
			}
		}
		printf("Case #%d:",t);
		solve();
	}
	return 0;
}
