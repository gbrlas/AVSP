#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

#define size(x) int((x).size())
#define foreach(i,c) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
typedef long long I64; typedef unsigned long long U64;
const double EPS=1e-12;
const int INF=999999999;
typedef vector<int> VI;
typedef vector<string> VS;

const int MAXN=10010;

int n,n2;
int gate[MAXN];
bool can[MAXN];
int value[MAXN];
int f[MAXN][2];

int com(int u,int v)
{
	int &res=f[u][v];
	if(res!=-1) return res;
	
	res=-2;
	if(value[u]>=0) {
		if(v==value[u]) res=0;
		return res;
	}

	for(int lv=0;lv<=1;lv++) {
		int lw=com(u*2,lv);
		if(lw<0) continue;

		for(int rv=0;rv<=1;rv++) {
			int rw=com(u*2+1,rv);
			if(rw<0) continue;

			for(int i=0;i<=1;i++) {
				if(!can[u] && i!=gate[u]) continue;
				
				int vv;
				if(i==1) vv=lv&rv; else vv=lv|rv;
				if(v!=vv) continue;

				int w=lw+rw;
				if(i!=gate[u]) w++;
				if(res<0 || w<res) res=w;
			}
		}
	}
	return res;
}

void solve()
{
	int V;

	scanf("%d%d",&n,&V);
	n2=(n-1)/2;

	for(int i=1;i<=n2;i++) {
		int g,c;
		scanf("%d%d",&g,&c);
		gate[i]=g;
		can[i]=c;
	}

	memset(value,-1,sizeof(value));
	for(int i=n2+1;i<=n;i++) scanf("%d",&value[i]);

	memset(f,-1,sizeof(f));
	int ans=com(1,V);
	if(ans<0) printf("IMPOSSIBLE"); else printf("%d",ans);
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++) {
		printf("Case #%d: ",i);
		solve();
		printf("\n");
	}

	return 0;
}
