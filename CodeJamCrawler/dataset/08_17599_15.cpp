#include <iostream>

using namespace std;

const int dx[]={-2,-1},dy[]={-1,-2};
bool g[101][101];
int f[101][101];

int main()
{
	freopen("t.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,h,w,r,x,y;
	scanf("%d",&T);
	for(int t=1;t<=T;++t)
	{
		scanf("%d %d %d",&h,&w,&r);
		memset(g,false,sizeof(g));
		for(int i=0;i<r;++i)
		{
			scanf("%d %d",&x,&y);
			g[x][y]=true;
		}
		memset(f,0,sizeof(f));
		f[1][1]=1;
		for(int i=2;i<=h;++i)
			for(int j=2;j<=w;++j)
				if(!g[i][j])
					for(int k=0;k<2;++k)
					{
						int tx=i+dx[k],ty=j+dy[k];
						if(tx>0&&ty>0) f[i][j]=(f[i][j]+f[tx][ty])%10007;
					}
		printf("Case #%d: %d\n",t,f[h][w]);
	}
	return 0;
}
