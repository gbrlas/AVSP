#include <iostream>

using namespace std;

int n,m,ans,path[2002],mark[2002];
bool like[2002][2][2002],sat[2002];

void search(int d)
{
	if(d>n)
	{
		memset(sat,false,sizeof(sat));
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				if(like[i][path[i]][j])
					sat[j]=true;
		for(int j=1;j<=m;++j)
			if(!sat[j])
				return;
		int r=0;
		for(int i=1;i<=n;++i) r+=path[i];
		if(r<ans)
		{
			ans=r;
			memcpy(mark,path,sizeof(path));
		}
	}
	else
	{
		path[d]=0;
		search(d+1);
		path[d]=1;
		search(d+1);
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T,num,x,y;
	scanf("%d",&T);
	for(int t=1;t<=T;++t)
	{
		memset(like,false,sizeof(like));
		scanf("%d %d",&n,&m);
		for(int i=1;i<=m;++i)
		{
			scanf("%d",&num);
			for(int j=0;j<num;++j)
			{
				scanf("%d %d",&x,&y);
				like[x][y][i]=true;
			}
		}
		ans=INT_MAX;
		search(1);
		if(ans==INT_MAX) printf("Case #%d: IMPOSSIBLE\n",t);
		else
		{
			printf("Case #%d:",t);
			for(int i=1;i<=n;++i) printf(" %d",mark[i]);
			putchar('\n');
		}
	}
	return 0;
}
