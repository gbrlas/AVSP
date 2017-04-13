//////////////////////////////////////////
//   Bismillahir Rahmanir Rahim        //
//   Author      : Shohan Ahmed Sijan //
//   Country     : Bangladesh        //
//   Algorithm   : 
//   Complexity  : %
//   University  : East West University //
/////////////////////////////////////////
#pragma warning(disable:4786)
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define Re(i,n) for(i=0;i<n;i++)
#define inf 999999999
#define PI acos(-1)
#define EPS 1e-12
#define sqrt(x) sqrt(abs(x))
#define P pair<int,int>
#define N 1000009

typedef  int I;

I Max(I a,I b)
{
	return a>b?a:b;
}
I Min(I a,I b)
{
	return a<b?a:b;
}

//................................
char grid[5][5],winp;
bool win,dott;
void dfsh(char t,I r, I c,I h)
{
	if(h==4)
	{
		win=true;
		winp=t;
	}
	if(win==true)return;
	if(r>0 && (grid[r-1][c]==t || grid[r-1][c]=='T') )dfsh(t,r-1,c,h+1);
}

void dfsv(char t,I r, I c,I h)
{
	if(h==4)
	{
		win=true;
		winp=t;
	}
	if(win==true)return;
	if(c>0 && (grid[r][c-1]==t || grid[r][c-1]=='T') )dfsv(t,r,c-1,h+1);
}

void dfsdr(char t,I r, I c,I h)
{
	if(h==4)
	{
		win=true;
		winp=t;
	}
	if(win==true)return;
	if(r>0 && c<3 && (grid[r-1][c+1]==t || grid[r-1][c+1]=='T') )dfsdr(t,r-1,c+1,h+1);
}

void dfsdl(char t,I r, I c,I h)
{
	if(h==4)
	{
		win=true;
		winp=t;
	}
	if(win==true)return;
	if(r>0 && c>0 && (grid[r-1][c-1]==t || grid[r-1][c-1]=='T') )dfsdl(t,r-1,c-1,h+1);
}
int main()
{
	freopen("A.in","r",stdin);
	freopen("Aout.txt","w",stdout);
	I i,j,test,cas=1;
	scanf("%d",&test);
	while(test--)
	{
		for(i=0;i<4;i++)
		scanf("%s",&grid[i]);
		win=dott=0;
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
			{
				if(grid[i][j]=='.')dott=true;
				else if(grid[i][j]=='T')
				{
					dfsh('X',i,j,1);
					dfsv('X',i,j,1);
					dfsdr('X',i,j,1);
					dfsdl('X',i,j,1);

					dfsh('O',i,j,1);
					dfsv('O',i,j,1);
					dfsdr('O',i,j,1);
					dfsdl('O',i,j,1);
				}
				else if(win==false)
				{
					dfsh(grid[i][j],i,j,1);
					dfsv(grid[i][j],i,j,1);
					dfsdr(grid[i][j],i,j,1);
					dfsdl(grid[i][j],i,j,1);
				}
			}
		if(win==true)printf("Case #%d: %c won\n",cas++,winp);
		else if(dott==true)printf("Case #%d: Game has not completed\n",cas++);
		else printf("Case #%d: Draw\n",cas++);
	}
	return 0;
}