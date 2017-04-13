#define _CRT_SECURE_NO_WARNINGS

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
#include <complex>
#pragma comment(linker, "/STACK:266777216")
using namespace std;

#define assert(f) { if(!(f)) { fprintf(stderr,"Assertion failed: "); fprintf(stderr,#f); fprintf(stderr,"\n"); exit(1); } }

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<double> VD;
typedef pair<double,double> PDD;

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

const int MAXN = 101010;
const int INF = 1000000000;
 
struct edge {
	int a, b, cap, flow;
  edge(int a_,int b_,int c_,int f_):a(a_), b(b_), cap(c_), flow(f_) {}
};
 
int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];

void init() {
  e.cl;
  for(int i=0;i<n;i++) g[i].cl;
}

void addEdge (int a, int b, int cap) {
	edge e1(a, b, cap, 0);
	edge e2(b, a, 0, 0);
	g[a].push_back ((int) e.size());
	e.push_back (e1);
	g[b].push_back ((int) e.size());
	e.push_back (e2);
}
 
bool bfs() {
	int qh=0, qt=0;
	q[qt++] = s;
	memset (d, -1, n * sizeof d[0]);
	d[s] = 0;
	while (qh < qt && d[t] == -1) {
		int v = q[qh++];
		for (size_t i=0; i<g[v].size(); ++i) {
			int id = g[v][i],
				to = e[id].b;
			if (d[to] == -1 && e[id].flow < e[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}
 
int dfs (int v, int flow) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
		int id = g[v][ptr[v]],
			to = e[id].b;
		if (d[to] != d[v] + 1)  continue;
		int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
		if (pushed) {
      //printf("%d<-%d\n",e[id].b,e[id].a);
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}
 
int dinic() {
	int flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, n * sizeof ptr[0]);
		while (int pushed = dfs (s, INF))
			flow += pushed;
	}
	return flow;
}

/*int n,s,t;
#define N 111
int c[N][N],f[N][N];
int mark[N];
VI a[N];

void init() {
  fill(c,0);
  fill(f,0);
  for(int i=0;i<n;i++) a[i].cl;
}

void addEdge(int u,int v,int cuv) {
  a[u].pb(v);
  a[v].pb(u);
  c[u][v]=cuv;
  c[v][u]=cuv;
}

bool dfs(int u) {
  if(u==t) return true;
  if(!mark[u]) return false;
  mark[u]=1;
  for(int i=a[u].sz;i--;) {
    int v=a[u][i];
    if(f[u][v]<c[u][v] && dfs(v)) {
      f[u][v]++;
      f[v][u]--;
      return true;
    }
  }
  return false;
}

int dinic() {
  int res=0;
  while(true) {
    fill(mark,0);
    if(!dfs(s)) break;
    res++;
  }
  return res;
}*/

int w,h,b;

int grid[111][555]={0};

struct rect {
  int x1,y1,x2,y2;
  void read() {
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
  }
  void fillGrid() {
    for(int x=x1;x<=x2;x++)
      for(int y=y1;y<=y2;y++)
        grid[x][y]=1;
  }
} rct[1010];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int brute() {
  int m=w*h;
  n = 2*m+2;
  s = n-1, t=n-2;
  init();
  fill(grid,0);
  for(int i=0;i<b;i++)
    rct[i].fillGrid();
  for(int i=0;i<w;i++) {
    if(!grid[i][0]) addEdge(s,i,1);
    if(!grid[i][h-1]) addEdge(i+w*(h-1)+m,t,1);
  }
  for(int i=0;i<w;i++) {
    for(int j=0;j<h;j++) if(!grid[i][j]) {
      int u = i+w*j;
      addEdge(u,u+m,1);
      for(int k=0;k<4;k++) {
        int x = i+dx[k];
        int y = j+dy[k];
        if(0<=x && x<w && 0<=y && y<h && !grid[x][y]) {
          int v = x+w*y;
          addEdge(u+m,v,1);
        }
      }
    }
  }
  return dinic();
}

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int TST,tst=0;
	for(scanf("%d",&TST);TST--;)
	{
		printf("Case #%d: ",++tst);
		fprintf(stderr,"Case #%d:\n",tst);
    scanf("%d%d%d",&w,&h,&b);
    for(int i=0;i<b;i++)
      rct[i].read();
    int ans = brute();
    printf("%d\n",ans);
	}
	fprintf(stderr,"time=%.3lfsec\n",0.001*(clock()-start));
	return 0;
}
