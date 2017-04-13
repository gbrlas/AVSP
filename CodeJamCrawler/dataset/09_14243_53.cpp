#include<iostream>
#include<algorithm>
using namespace std;
struct dd{
	int a,b,c;
}s[10005];
int map[101][101];
int p[10005][2];
int used[101][101];
bool cmp(dd a,dd b)
{
	return a.c>b.c||(a.c==b.c && a.a<b.a);
}
int h,w;

void dfs(int x,int y,int v,int &z)
{
	int open=0,xx,yy,i,e;
	p[0][0]=x;p[0][1]=y;
	int a=100000,b=100000,c=100000,d=100000;
	int flag=0;
	while(1)
	{
		a=100000,b=100000,c=100000,d=100000;
		if(x>1) a=map[x-1][y];
		if(y>1) b=map[x][y-1];
		if(y<w) c=map[x][y+1]; 
		if(x<h) d=map[x+1][y];
		e=map[x][y];
		if(e>a) {e=a;xx=x-1;yy=y;}
		if(e>b) {e=b;xx=x;yy=y-1;}
		if(e>c) {e=c;xx=x;yy=y+1;}
		if(e>d) {e=d;xx=x+1;yy=y;}
		if(e==map[x][y]) {flag=1;break;}
		if(!used[xx][yy])
		{
			used[xx][yy]=z;
			open++;
			p[open][0]=xx;p[open][1]=yy;
			x=xx;y=yy;
		}
		else break;
	}
	if(!flag)
	{
		for(i=0;i<=open;i++)
		used[p[i][0]][p[i][1]]=used[xx][yy];
		z--;
	}
	
}
int main()
{
	int t,k,i,j,ww;
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
		scanf("%d%d",&h,&w);
		ww=0;
		for(i=1;i<=h;i++)
		 for(j=1;j<=w;j++)
		{
			scanf("%d",&map[i][j]);
			s[ww].a=i;s[ww].b=j;s[ww++].c=map[i][j];
		}
		sort(s,s+ww,cmp);
		memset(used,0,sizeof(used));
		int z=0;
		
		for(i=1;i<=h;i++)
		for(j=1;j<=w;j++)
		{
			if(!used[i][j])
			{
				z++;
				used[i][j]=z;
				dfs(i,j,map[i][j],z);
			}
		}
		printf("Case #%d:\n",k);
		for(i=1;i<=h;i++)
		{
			for(j=1;j<=w;j++)
			{
				if(j==1)
				{
					printf("%c",used[i][j]+'a'-1);
				}
				else
				{
					printf(" %c",used[i][j]+'a'-1);
				}
			}
			puts("");
		}
	}
	return 0;
}
