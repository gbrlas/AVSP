//#include<stdafx.h>
#include <stdlib.h>
#include<cstring>
#include<iostream>
using namespace std;
typedef struct node
{
    int x;
    int y;
}node;
char map[110][110];
int xmap[110][110];
bool vist[110][110];
int N,M;
char nowchar;

node xmin(int x,int y,int N,int W,int E,int S)
{
    node p;
    if(N<=W&&N<=E&&N<=S)
    {
        p.x=x-1;
        p.y=y;
        return p;
    }
    if(W<=E&&W<=S)
    {
        p.x=x;
        p.y=y-1;
        return p;
    }
    if(E<=S)
    {
        p.x=x;
        p.y=y+1;
        return p;
    }
    p.x=x+1;
    p.y=y;
    return p;
}
char dfs(int x,int y)
{
    node lmin=xmin(x,y,xmap[x-1][y],xmap[x][y-1],xmap[x][y+1],xmap[x+1][y]);
    if(xmap[lmin.x][lmin.y]>=xmap[x][y])
    {
        if(vist[x][y]==true)
            return map[x][y];
        map[x][y]=nowchar;
        vist[x][y]=true;
        nowchar++;
    }
    else if(vist[lmin.x][lmin.y]==true)
    {
        map[x][y]=map[lmin.x][lmin.y];
		vist[x][y]=true;
    }
    else
    {
		vist[x][y]=true;
        map[x][y]=dfs(lmin.x,lmin.y);
    }
    return map[x][y];
}
int main()
{
    int T,i,j,xx;
	freopen("B-small-attempt5.in","r",stdin);
	freopen("bb.out","w",stdout);
    scanf("%d",&T);
    for(xx=1;xx<=T;xx++)
    {
        scanf("%d %d",&N,&M);
		for(i=0;i<=N+1;i++)
		{
			for(j=0;j<=M+1;j++)
			{
				xmap[i][j]=INT_MAX;
			}
		}
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=M;j++)
            {
                scanf("%d",&xmap[i][j]);
            }
        }
        memset(vist,0,sizeof(vist));
        nowchar='a';
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=M;j++)
            {
                if(vist[i][j]==false)
                {
                    dfs(i,j);
                }
            }
        }
        printf("Case #%d:\n",xx);
        for(i=1;i<=N;i++)
        {
            printf("%c",map[i][1]);
            for(j=2;j<=M;j++)
            {
                printf(" %c",map[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}