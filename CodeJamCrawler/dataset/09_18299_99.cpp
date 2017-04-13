#define N 0
#define W 1
#define E 2
#define S 3
#include<stdio.h>
#include<string.h>
int a[102][102];
bool p[102][102][4];
int fx[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
int f[4]={S,E,W,N};
char z[102][102];
void dfs(const int &i,const int &j)
{
	for(int k=0;k<4;k++)if(p[i][j][k]&&!z[i+fx[k][0]][j+fx[k][1]])
	{
		z[i+fx[k][0]][j+fx[k][1]]=z[i][j];
		dfs(i+fx[k][0],j+fx[k][1]);
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int x=1;x<=t;x++)
	{
		int h,w;
		scanf("%d%d",&h,&w);
		memset(a,0x7f,sizeof(a));
		for(int i=1;i<=h;i++)for(int j=1;j<=w;j++)scanf("%d",a[i]+j);
		memset(p,0,sizeof(p));
		for(int i=1;i<=h;i++)for(int j=1;j<=w;j++)
		{
			int l=0;
			for(int k=1;k<4;k++)if(a[i+fx[k][0]][j+fx[k][1]]<a[i+fx[l][0]][j+fx[l][1]])l=k;
			if(a[i+fx[l][0]][j+fx[l][1]]<a[i][j])p[i][j][l]=p[i+fx[l][0]][j+fx[l][1]][f[l]]=true;
		}
		memset(z,0,sizeof(z));
		char y='a';
		for(int i=1;i<=h;i++)for(int j=1;j<=w;j++)if(!z[i][j])
		{
			z[i][j]=y++;
			dfs(i,j);
		}
		printf("Case #%d:\n",x);
		for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=w;j++)putchar(z[i][j]),putchar(' ');
			putchar('\n');
		}
	}
}
