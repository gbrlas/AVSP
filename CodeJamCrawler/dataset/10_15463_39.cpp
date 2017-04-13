#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
const int dx[]={-1,-1,-1,0,0,1,1,1};
const int dy[]={1,0,-1,1,-1,0,1,-1};
int n,l;
char a[60][60],t[60][60];
inline bool check()
{
	int i,j,k;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			if (a[i][j]!='.')
			{
				k=i;
				while (k<n)
				{
					if (a[k][j]=='.')return true;
					k++;
				}
			}
		}
	}
	return false;
}
inline void move()
{
	int i,j,k;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			if (a[i][j]!='.')
			{
				k=i+1;
				while (k<n&&a[k][j]=='.')
				{
					k++;
				}
				if (k==n||isalpha(a[k][j]))k--;
				swap(a[i][j],a[k][j]);
			}
		}
	}
}	
inline bool cc(int x,int y,char c)
{
	int i,j,k,tx,ty,aa=-1;
	for (k=0;k<8;k++)
	{
		tx=x;
		ty=y;
		int ss=0;
		while (tx>=0&&tx<n&&ty>=0&&ty<n&&a[tx][ty]==c)
		{
			ss++;
			tx+=dx[k];
			ty+=dy[k];
		}
		aa=max(aa,ss);
	}
	return aa>=l;
}
int main()
{
	freopen("C:\\Users\\daizhy\\Documents\\output.txt","w",stdout);
	int i,j,k,cas,ccc=0;
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d%d",&n,&l);
		memset(a,0,sizeof(a));
		memset(t,0,sizeof(t));
		for (i=0;i<n;i++)scanf("%s",t[i]);
		for (i=0;i<n;i++)
		{
			for (j=0;j<n;j++)
			{
				a[i][j]=t[n-j-1][i];
			}
		}
		while (check())
		{
			move();
		}
		int ww[200]={0};
		for (i=0;i<n;i++)
		{
			for (j=0;j<n;j++)
			{
				if (isalpha(a[i][j]))
				{
					char tmp=a[i][j];
					if (cc(i,j,tmp))ww[tmp]=1;
				}
			}
		}
		printf("Case #%d: ",++ccc);
		if (ww['R']==0&&ww['B']==0)puts("Neither");
		else if (ww['R']==0&&ww['B']==1)puts("Blue");
		else if (ww['R']==1&&ww['B']==0)puts("Red");
		else if (ww['R']==1&&ww['B']==1)puts("Both");
	}
	return 0;
}
/*
222
6 4
......
......
.R...R
.R..BB
.R.RBR
RB.BBB
*/
				
		
