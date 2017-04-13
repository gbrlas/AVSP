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
typedef vector<PII> VPII;
typedef __int64 LL;
typedef unsigned __int64 ULL;

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

#define N 10//2020
vector<VI> reg;

void rec(const VI &a,const VPII &d)
{
	if(d.sz==0)
	{
		reg.pb(a);
		return;
	}
	PII p=d.back();
	int u=p.X,v=p.Y;//u<v
	bool flag=true;
	VI a0,a1;
	int i;
	for(i=0;i<a.sz;i++)
	{
		if(flag) a0.pb(a[i]); else a1.pb(a[i]);
		if(a[i]==u)
			flag=false,a1.pb(a[i]);
		if(a[i]==v)
			flag=true,a0.pb(a[i]);
	}
	VPII d0,d1;
	for(i=0;i<d.sz-1;i++)
	{
		int u=d[i].X;
		int v=d[i].Y;
		VI::iterator itu=lower_bound(all(a0),u);
		VI::iterator itv=lower_bound(all(a0),v);
		if(itu!=a0.end() && *itu==u && itv!=a0.end() && *itv==v)
			d0.pb(d[i]);
		else
			d1.pb(d[i]);
	}
	rec(a0,d0);
	rec(a1,d1);
}

int n;
int res;
VI ans;
VI mark;
void brute(int i,int c)
{
	int j;
	if(i==n)
	{
		for(i=0;i<reg.sz;i++)
		{
			int q[N]={0};
			for(j=0;j<reg[i].sz;j++)
				q[mark[reg[i][j]]]=1;
			for(j=0;j<c && q[j];j++);
			if(j<c) break;
		}
		if(i==reg.sz && res<c)
		{
			res=c;
			ans=mark;
		}
		return;
	}
	for(j=0;j<=c;j++)
	{
		mark[i]=j;
		brute(i+1,max(j+1,c));
		mark[i]=-1;
	}
}

int main()
{
	freopen("c1.in","r",stdin);
	freopen("c1.out","w",stdout);
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		printf("Case #%d: ",++tst);
		fprintf(stderr,"Case #%d:\n",tst);

		//Code
		int m,i;
		scanf("%d%d",&n,&m);
		VI a(n);
		for(i=0;i<n;i++) a[i]=i;
		VPII d(m);
		for(i=0;i<m;i++) scanf("%d",&d[i].X),d[i].X--;
		for(i=0;i<m;i++) scanf("%d",&d[i].Y),d[i].Y--;
		reg.cl;
		rec(a,d);
		res=0;
		ans=VI(n,-1);
		mark=VI(n,-1);
		brute(0,0);
		printf("%d\n",res);
		for(i=0;i<n;i++)
			printf("%d%c",ans[i]+1,i<n-1?' ':'\n');
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
