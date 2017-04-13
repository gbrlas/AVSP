#include <cstdio>
#include <cstring>

bool used[501];
int g[501][501]={0},match[501],depA[501],depB[501],arrA[501],arrB[501];

bool find(int v)
{
	for(int i=1;i<=g[v][0];++i)
		if(!used[g[v][i]])
		{
			used[g[v][i]]=true;
			if(match[g[v][i]]==-1||find(match[g[v][i]]))
			{
				match[g[v][i]]=v;
				return true;
			}
		}
	return false;
}

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("small.txt","w",stdout);
	int T,preTime,na,nb,n,hh,mm;
	scanf("%d",&T);
	for(int t=1;t<=T;++t)
	{
		scanf("%d\n%d %d",&preTime,&na,&nb);
		for(int i=1;i<=na;++i)
		{
			scanf("\n%d:%d",&hh,&mm);
			depA[i]=hh*60+mm;
			scanf("%d:%d",&hh,&mm);
			arrB[i]=hh*60+mm;
		}
		for(int i=1;i<=nb;++i)
		{
			scanf("\n%d:%d",&hh,&mm);
			depB[i]=hh*60+mm;
			scanf("%d:%d",&hh,&mm);
			arrA[i]=hh*60+mm;
		}
		memset(g,0,sizeof(g));
		for(int i=1;i<=na;++i)
			for(int j=1;j<=nb;++j)
				if(arrB[i]+preTime<=depB[j])
					g[i][++g[i][0]]=j+na;
		for(int i=1;i<=nb;++i)
			for(int j=1;j<=na;++j)
				if(arrA[i]+preTime<=depA[j])
					g[i+na][++g[i+na][0]]=j;
		memset(match,-1,sizeof(match));
		n=na+nb;
		for(int i=1;i<=n;++i)
		{
			memset(used,false,sizeof(used));
			find(i);
		}
		int ra=na,rb=nb;
		for(int i=1;i<=na;++i)
			if(match[i]!=-1)
				--ra;
		for(int i=1;i<=nb;++i)
			if(match[na+i]!=-1)
				--rb;
		printf("Case #%d: %d %d\n",t,ra,rb);
	}
	return 0;
}
