#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=200, BASE=10007;
const int mv[2][2]={ -2,-1, -1,-2 };

int g[maxn][maxn], fnd[maxn][maxn];
int task, n, m, num, x, y;

int main(){
	freopen("D-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d", &task);
	for (int tk=1; tk<=task; tk++){
		scanf("%d%d%d", &n, &m, &num);
		memset( g, 0, sizeof(g) ); g[1][1] = 1;
		memset( fnd, 0, sizeof(fnd) );
		for (int i=1; i<=num; i++){
			scanf("%d%d", &x, &y);
			fnd[x][y] = true;
		}

		for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
		if ( !fnd[i][j] ){
			for (int k=0; k<=1; k++)
			if ( i+mv[k][0]>=1 && j+mv[k][1]>=1 && !fnd[i+mv[k][0]][j+mv[k][1]] ) 
				(g[i][j]+=g[i+mv[k][0]][j+mv[k][1]] )%=BASE;
		}
		printf("Case #%d: %d\n", tk, g[n][m]);
	}
	return 0;
}
