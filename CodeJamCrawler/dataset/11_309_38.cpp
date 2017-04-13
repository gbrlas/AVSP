#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

typedef long long int64;
const int maxn=510;

int64 a[maxn][maxn],b[maxn][maxn],c[maxn][maxn];

struct data
{
	int64 x,y;
};

data f[maxn][maxn],g[maxn][maxn],h[maxn][maxn],le,ri,mi;

int n,m,q;
char z;

bool check(int ans)
{
	if (ans==2) return true;
	int x,y;
	int64 tmp;
	for (int i=1; i<=n-ans+1; i++) for (int j=1; j<=m-ans+1; j++) {
		x=i+ans-1; y=j+ans-1;
		le.x=h[x][y].x-h[i-1][y].x-h[x][j-1].x+h[i-1][j-1].x;
		le.x=le.x-g[i][j].x-g[x][y].x-g[i][y].x-g[x][j].x;
		le.y=h[x][y].y-h[i-1][y].y-h[x][j-1].y+h[i-1][j-1].y;
		le.y=le.y-g[i][j].y-g[x][y].y-g[i][y].y-g[x][j].y;
		mi.x=i+x-1; mi.y=j+y-1;
		tmp=c[x][y]+c[i-1][j-1]-c[i-1][y]-c[x][j-1]-a[i][j]-a[x][y]-a[x][j]-a[i][y];
		ri.x=mi.x*tmp; ri.y=mi.y*tmp;
		if ((le.x==ri.x)&&(le.y==ri.y)) return true;
	}
	return false;
}

int main()
{
	int t=0,tt,tmp; cin>>tt;
	while (++t<=tt) {
		cin>>n>>m>>q;
		tmp=min(n,m);
		for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
			cin>>z;
			a[i][j]=z-'0'; a[i][j]+=q;
			f[i][j].x=i*2+1; f[i][j].y=j*2+1;
			g[i][j].x=f[i][j].x*a[i][j]; g[i][j].y=f[i][j].y*a[i][j];
			h[i][j].x=g[i][j].x+h[i-1][j].x+h[i][j-1].x-h[i-1][j-1].x;
			h[i][j].y=g[i][j].y+h[i-1][j].y+h[i][j-1].y-h[i-1][j-1].y;
			c[i][j]=a[i][j]+c[i-1][j]+c[i][j-1]-c[i-1][j-1];
		}
		while (!(check(tmp))) --tmp;
		printf("Case #%d: ",t);
		if (tmp==2) printf("IMPOSSIBLE\n"); else printf("%d\n",tmp);
	}
	return 0;
}
