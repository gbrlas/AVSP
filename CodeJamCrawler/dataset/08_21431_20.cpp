#include<cstdio>
#include<algorithm>
using namespace std;

const int N=10001,INF=100000000;
int g[N],c[N],d[N][2];
//g[i]==1 <=> AND gate
int n;

inline int min3(int a, int b, int c)
{
     return min(a,min(b,c));
}

void go(int v)
{
    if(v>(n-1)/2) return;
    go(v*2); go(v*2+1);
    if(g[v]==1) //and
    {
	d[v][1]=d[v*2][1]+d[v*2+1][1];
	d[v][0]=min3(d[v*2][0]+d[v*2+1][1], d[v*2][1]+d[v*2+1][0], d[v*2][0]+d[v*2+1][0]);
	if(c[v]==1)
	{
	    d[v][1]=min3(d[v][1], d[v*2][1]+d[v*2+1][0]+1, d[v*2][0]+d[v*2+1][1]+1);
	    d[v][1]=min(d[v][1], d[v*2][1]+d[v*2+1][1]+1);
	    d[v][0]=min(d[v][0], d[v*2][0]+d[v*2+1][0]+1);
	}
    }
    else
    {
        d[v][1]=min3(d[v*2][1]+d[v*2+1][0], d[v*2][0]+d[v*2+1][1], d[v*2][1]+d[v*2+1][1]);
        d[v][0]=d[v*2][0]+d[v*2+1][0];	
	if(c[v]==1)
	{
	    d[v][1]=min(d[v][1],d[v*2][1]+d[v*2+1][1]+1);
	    d[v][0]=min(d[v][0], min3(d[v*2][1]+d[v*2+1][0]+1, d[v*2][0]+d[v*2+1][1]+1, d[v*2][0]+d[v*2+1][0]+1));
	}
    }
    d[v][0]=min(d[v][0],INF);
    d[v][1]=min(d[v][1],INF);
}

main()
{
    int t,v,cs=0;
    scanf("%d",&t);
    while(t--)
    {
	scanf("%d %d",&n,&v);
	for(int i=1; i<=(n-1)/2; i++)
	{
	    scanf("%d %d",&g[i],&c[i]);
	}
	for(int i=(n-1)/2+1; i<=n; i++)
	{
	    scanf("%d",&g[i]);
	    d[i][g[i]]=0; d[i][!g[i]]=INF;
	}
	go(1);
	int res=d[1][v];
	printf("Case #%d: ",++cs);
	if(res==INF) printf("IMPOSSIBLE\n");
	else printf("%d\n",res);
    }
    return 0;
}
