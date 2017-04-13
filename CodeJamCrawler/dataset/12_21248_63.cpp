#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#pragma comment(linker, "/STACK:266777216")
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<double> VD;
typedef pair<double,double> PDD;

const int inf=1000000000;
const LL INF=LL(inf)*inf;
const double eps=1e-9;
const double PI=2*acos(0.0);
#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset((ar),(val),sizeof (ar))
#define MIN(a,b) {if((a)>(b)) (a)=(b);}
#define MAX(a,b) {if((a)<(b)) (a)=(b);}
#define sqr(x) ((x)*(x))
#define X first
#define Y second

clock_t start=clock();

#define N 111
int h,n,m;
int a[N][N],b[N][N];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

PII move(int i,int j,int k,int h)
{
	int a1=a[i][j],b1=b[i][j];
	assert(a1+50<=b1);
	assert(h+50<=b1);
	int x=i+dx[k],y=j+dy[k];
	if(x<0 || x>=n || y<0 || y>=m) return mp(inf,inf);
	int a2=a[x][y],b2=b[x][y];
	if(a1+50>b2 || a2+50>b2 || a2+50>b1) return mp(inf,inf);
	int t1=0;
	if(h+50>b2) t1=h+50-b2,h=b2-50;
	int t2=h-a1<20?100:10;
	return mp(t1,t2);
}

int mark[N][N];

void dfs(int i,int j)
{
	if(mark[i][j]) return;
	mark[i][j]=1;
	for(int k=0;k<4;k++)
		if(move(i,j,k,h).X==0) dfs(i+dx[k],j+dy[k]);
}

int anst;
int t[N*N];
void dejkstra(int i0,int j0,int h0)
{
	priority_queue<PII> q;
	q.push(mp(0,m*i0+j0));
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			t[m*i+j] = i==i0 && j==j0?0:inf;
	for(;;)
	{
		if(q.sz==0) break;
		int u=q.top().Y;
		int tt=-q.top().X;
		q.pop();
		if(tt>t[u]) continue;
		if(t[u]>=anst) break;
		int h=h0-t[u];
		i=u/m;
		j=u%m;
		if(i==n-1 && j==m-1)
		{
			anst=t[u];
			break;
		}
		for(int k=0;k<4;k++)
		{
			PII mv=move(i,j,k,h);
			if(mv.X<inf && mv.Y<inf)
			{
				int x=i+dx[k],y=j+dy[k];
				int v=m*x+y;
				if(t[v]>t[u]+mv.X+mv.Y)
				{
					t[v]=t[u]+mv.X+mv.Y;
					q.push(mp(-t[v],v));
				}
			}
		}
	}
}

int main()
{
	freopen("b2.in","r",stdin);
	freopen("b2.out","w",stdout);
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		printf("Case #%d: ",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
		scanf("%d%d%d",&h,&n,&m);
		int i,j;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++) scanf("%d",&b[i][j]);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++) scanf("%d",&a[i][j]);
		fill(mark,0);
		dfs(0,0);
		anst=inf;
		for(i=n;i--;)
			for(j=m;j--;)
				if(mark[i][j]) dejkstra(i,j,h);
		printf("%.1lf\n",anst/10.+eps);
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
