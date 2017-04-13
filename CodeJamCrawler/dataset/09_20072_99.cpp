#include<stdio.h>
#include<algorithm>

using namespace std;

struct dat
{
	int x,y;
	int v;
};

bool operator < (dat a,dat b)
{
	return a.v>b.v;
}

dat a[10001];
int f[10001];

int find(int x)
{
	if (f[x]==x) return f[x];
	else
	{
		f[x]=find(f[x]);
		return f[x];
	}
}

int map[101][101];
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
char pp[101][101];

int main()
{
	int t,p;
	int n,m;
	int i,j,k;
	int l;
	int xx,yy;
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d%d",&n,&m);
		l=0;
		for (i=1;i<=n;i++)
			for (j=1;j<=m;j++)
			{
				scanf("%d",&map[i][j]);
				l++;
				a[l].x=i;
				a[l].y=j;
				a[l].v=map[i][j];
			}
		sort (a+1,a+l+1);
		for (i=1;i<=l;i++)
			f[i]=i;
		for (i=1;i<=l;i++)
		{
			k=4;
			int vv=a[i].v;
			for (j=0;j<4;j++)
			{
				xx=a[i].x+dx[j];
				yy=a[i].y+dy[j];
				if (xx>=1&&xx<=n&&yy>=1&&yy<=m&&map[xx][yy]<vv)
				{
					vv=map[xx][yy];
					k=j;
				}
			}
			if (k==4) continue;
			xx=a[i].x+dx[k];
			yy=a[i].y+dy[k];
			j=find((a[i].x-1)*m+a[i].y);
			k=find((xx-1)*m+yy);
			if (j<=k) f[k]=j;
			else f[j]=k;
		}
		printf("Case #%d:\n",p);
		char p1='a';
		for (i=1;i<=n;i++)
			for (j=1;j<=m;j++)
			{
				k=find((i-1)*m+j);
				if (k==(i-1)*m+j) 
				{
					pp[i][j]=p1;
					p1++;
				}
				else 
				{
					if (k%m==0)
					{
						xx=k/m;
						yy=m;
					}
					else
					{
						xx=k/m+1;
						yy=k%m;
					}
					pp[i][j]=pp[xx][yy];
				}
			}
		for (i=1;i<=n;i++)
		{
			for (j=1;j<m;j++)
				printf("%c ",pp[i][j]);
			printf("%c\n",pp[i][m]);
		}
	}
	return 0;
}



