#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn=110;
const int mv[4][2]={ -1,0, 0,-1, 0,1, 1,0 };

bool g[maxn][maxn][4];
int d[maxn][maxn], fnd[maxn][maxn];
int task, n, m;

void dfs( int x, int y, int cl ){
	fnd[x][y] = cl;
	int fx, fy;
	for (int k=0; k<4; k++){
		fx = x+mv[k][0];
		fy = y+mv[k][1];
		if ( fnd[fx][fy]==-1 && g[x][y][k] )
			dfs( fx, fy, cl );
	}
}

int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d", &task);
	for (int tt=1; tt<=task; tt++){
		scanf("%d%d", &n, &m);
		for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			scanf("%d", d[i]+j);
		memset( g, 0, sizeof(g) );
		for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++){
			int p=d[i][j], pl, fx, fy;
			for (int k=0; k<4; k++){
				fx = i+mv[k][0];
				fy = j+mv[k][1];
				if ( 1<=fx && fx<=n && 1<=fy && fy<=m ){
					if ( d[fx][fy]<p ) 
						p = d[fx][fy], pl = k;
				}
			}
			if ( p==d[i][j] ) continue;
			g[i][j][pl] = true;
			fx = i+mv[pl][0];
			fy = j+mv[pl][1];
			if ( pl==0 ) g[fx][fy][3] = true;else
			if ( pl==1 ) g[fx][fy][2] = true;else
			if ( pl==2 ) g[fx][fy][1] = true;else g[fx][fy][0] = true;
		}

		memset( fnd, 255, sizeof(fnd) );
		int color = 0;
		for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
		if ( fnd[i][j]==-1 ){
			dfs( i, j, color++ );
		}
		printf("Case #%d:\n", tt);
		for (int i=1; i<=n; i++, printf("\n"))
		for (int j=1; j<=m; j++){
			if ( j!=1 ) printf(" ");
			printf("%c", char('a'+fnd[i][j]));
		}
	}
	return 0;
}
