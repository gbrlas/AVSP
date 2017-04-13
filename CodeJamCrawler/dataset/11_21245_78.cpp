#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#pragma comment(linker, "/STACK:16777216")
using namespace std;

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;

#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define inf 1000000000
#define eps 1e-9
#define PI 3.1415926535897932385
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) a.begin(),a.end()
#define fill(ar,val) memset(ar,val,sizeof ar)
#define MIN(a,b) if(a>(b)) a=(b)
#define MAX(a,b) if(a<(b)) a=(b)
#define sqr(x) ((x)*(x))
#define X first
#define Y second

clock_t start=clock();

#define N 444
int n,m;
VI a[N];
int t0[N],t1[N];
int bfs[N];
int len;

void add(int u,int T,int *t)
{
	if(t[u]>T)
	{
		t[u]=T;
		bfs[len++]=u;
	}
}

void BFS(int u,int *t)
{
	int i,k;
	for(i=0;i<n;i++)
		t[i]=inf;
	len=0;
	add(u,0,t);
	for(k=0;k<len;k++)
	{
		u=bfs[k];
		int T=t[u]+1;
		for(i=a[u].sz;i--;)
		{
			int v=a[u][i];
			add(v,T,t);
		}
	}
}

LL g[N];
int ans;

int bitcnt(LL x)
{
	int s=0;
	for(;x>0;x-=x&-x) s++;
	return s;
}

void rec(int u,LL mask)
{
	if(u==1)
	{
		MAX(ans,bitcnt(mask));
		return;
	}
	mask|=g[u];
	for(int i=a[u].sz;i--;)
	{
		int v=a[u][i];
		if(t0[v]==t0[u]+1 && t1[u]==t1[v]+1)
			rec(v,mask);
	}
}

int main()
{
	freopen("d1.in","r",stdin);
	freopen("d1.out","w",stdout);
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		printf("Case #%d: ",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
		scanf("%d%d",&n,&m);
		int i,u,v;
		for(i=0;i<n;i++)
			a[i].cl;
		while(m--)
		{
			scanf("%d,%d",&u,&v);
			a[u].pb(v);
			a[v].pb(u);
		}
		BFS(0,t0);
		BFS(1,t1);
		printf("%d ",t0[1]-1);

		for(u=0;u<n;u++)
		{
			g[u]=bit64(u);
			for(i=a[u].sz;i--;)
				g[u]+=bit64(a[u][i]);
		}
		ans=0;
		rec(0,0);
		printf("%d\n",ans-t0[1]);
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
