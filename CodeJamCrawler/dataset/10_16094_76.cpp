#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<string>
using namespace std;
int times,n,m,t,total,re,ans1[600],ans2[600];
const int mx[]={-1,0,1,0};
const int my[]={0,1,0,-1};
char ch;
int map[600][600];
inline bool check(int x,int y,int z)
{
	int tx,ty;
	for (int a=x;a<x+z;++a)
	for (int b=y;b<y+z;++b)
	{
		if (map[a][b]==-1) return false;
		for (int c=0;c<4;++c)
		{
			tx=a+mx[c];
			ty=b+my[c];
			if ((tx>=x)&&(tx<=x+z-1)&&(ty>=y)&&(ty<=y+z-1))
			{
				if (map[tx][ty]==-1) return false;
				if (map[tx][ty]==map[a][b])
				{
					return false;
				}
			}
		}
	}
	return true;
}
int main()
{
	freopen("C-small-attempt.in","r",stdin);
	freopen("C-small-attempt.out","w",stdout);
	scanf("%d",&times);
	for (int z=1;z<=times;++z)
	{
		scanf("%d%d",&n,&m);
		for (int a=1;a<=n;++a)
		{
			for (int b=1;b<=m/4;++b)
			{
				scanf("%c",&ch);
				while ((!isalpha(ch))&&(!isdigit(ch))) scanf("%c",&ch);
				if (isalpha(ch))
				{
					t=ch-'A'+10;
				}else t=ch-'0';
				for (int c=0;c<4;++c)
				{
					map[a][b*4-c]=t%2;
					t/=2;
				}
			}
		}
	/*	for (int a=1;a<=n;++a)
		{
			for (int b=1;b<=m;++b)
			{
				printf("%d",map[a][b]);
			}
			printf("\n");
		}*/
	/*	for (int a=1;a<=n;++a)
		{
			f[a][0]=0;
			for (int b=1;b<=m;++b)
			{
				for (int c=0;c<4;++c)
				{
					tx=a+mx[c];
					ty=b+my[c];
					if ((tx>=1)&&(tx<=n)&&(ty>=1)&&(ty<=n))
					{
						if (map[tx][ty]==map[a][b])
						{
							use[a][b]=1;
							break;
						}
					}
				}
				f[a][b]=f[a][b-1];
			}
		}*/
		printf("Case #%d: ",z);
		total=0;
		for (int siz=min(n,m);siz>=1;--siz)
		{
			re=0;
			for (int a=1;a<=n-siz+1;++a)
			{
				for (int b=1;b<=m-siz+1;++b)
				{
					if (check(a,b,siz))
					{
				//		printf("[%d,%d,%d]",a,b,siz);
						re++;
						for (int c=a;c<a+siz;++c)
						for (int d=b;d<b+siz;++d) 
							map[c][d]=-1;
					}
				}
			}
			if (re)
			{
				total++;
				ans1[total]=siz;
				ans2[total]=re;
			}
		}
		printf("%d\n",total);
		for (int a=1;a<=total;++a)
		{
			printf("%d %d\n",ans1[a],ans2[a]);
		}
	}
}
