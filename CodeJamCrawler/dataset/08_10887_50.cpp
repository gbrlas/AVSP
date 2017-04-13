#include<stdio.h>
#include<string.h>
#define maxn 220

bool g[maxn][maxn];
bool visit[maxn];
int pre[maxn];
int t[maxn][2];
int cc,n,m;

bool Dfs(int d,int nv2)
{
	int i,k;
	for(i=0;i<nv2;i++)
	{
		if(g[d][i]&&!visit[i])
		{
			visit[i]=1;
			k=pre[i];
			pre[i]=d;
			if(k==-1||Dfs(k,nv2)) return true;
			pre[i]=k;
		}
	}
	return false;
}

void Bimatch(int nv1,int nv2)
{
	int i;
	memset(pre,-1,sizeof(pre));
	for(i=0;i<nv1;i++)
	{
		memset(visit,0,sizeof(visit));
		Dfs(i,nv2);
	}

	int c1,c2;
	c1=c2=0;
	for(i=0;i<n;i++) 
		if(pre[i]==-1) c1++;
	for(i=n;i<n+m;i++)
		if(pre[i]==-1) c2++;

	printf("%d %d\n",c1,c2);
	
}

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);

	int cases,cas=1;
	
	int a,b,c,d;
	int i,j;

	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%d %d %d",&cc,&n,&m);

		for(i=0;i<n+m;i++)
		{
			scanf("%d:%d %d:%d",&a,&b,&c,&d);
			t[i][0]=a*60+b;
			t[i][1]=c*60+d;
		}

		memset(g,0,sizeof(g));
		for(i=0;i<n;i++)
		{
			for(j=n;j<n+m;j++) 
				if(t[i][1]+cc<=t[j][0]) g[i][j]=1;
		}
		for(i=n;i<n+m;i++)
		{
			for(j=0;j<n;j++)
				if(t[i][1]+cc<=t[j][0]) g[i][j]=1;
		}

		printf("Case #%d: ",cas++);
		Bimatch(n+m,n+m);
		
	}
	return 0;
}


	


