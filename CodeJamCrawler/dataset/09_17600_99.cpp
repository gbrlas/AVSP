#include <iostream>

using namespace std;

const int dx[]={-1,0,0,1},dy[]={0,-1,1,0};

int r,c,id,h[111][111],ans[111][111];

void dfs(int x,int y)
{
	int lowestH=INT_MAX,lowestID=-1;
	for(int i=0;i<4;++i)
	{
		int tx=x+dx[i],ty=y+dy[i];
		if(tx>-1&&ty>-1&&tx<r&&ty<c&&h[tx][ty]<h[x][y]&&h[tx][ty]<lowestH)
		{
			lowestH=h[tx][ty];
			lowestID=i;
		}
	}
	if(lowestID==-1) ans[x][y]=id++;
	else
	{
		int tx=x+dx[lowestID],ty=y+dy[lowestID];
		if(ans[tx][ty]) ans[x][y]=ans[tx][ty];
		else
		{
			dfs(tx,ty);
			ans[x][y]=ans[tx][ty];
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int cc;
	scanf("%d",&cc);
	for(int z=1;z<=cc;++z)
	{
		scanf("%d%d",&r,&c);
		memset(ans,0,sizeof(ans));
		id=1;
		for(int i=0;i<r;++i)
			for(int j=0;j<c;++j)
				scanf("%d",&h[i][j]);
		for(int i=0;i<r;++i)
			for(int j=0;j<c;++j)
				if(!ans[i][j])
					dfs(i,j);
		printf("Case #%d:\n",z);
		for(int i=0;i<r;++i)
		{
			for(int j=0;j+1<c;++j) printf("%c ",'a'-1+ans[i][j]);
			printf("%c\n",'a'-1+ans[i][c-1]);
		}
	}
	return 0;
}

