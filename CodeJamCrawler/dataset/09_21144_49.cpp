#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn=110;

int p[maxn][maxn], x[maxn];
bool g[maxn][maxn], s[maxn];
int task, cs=0, n, k;

bool path( int i ){
	for (int j=1; j<=n; j++)
	if ( !s[j] && g[i][j] ){
		s[j] = true;
		if ( !x[j] || path( x[j] ) ){
			x[j] = i; return true;
		}
	}
	return false;
}

int main(){
	freopen("C-large.in","r",stdin);
	freopen("a.out","w",stdout);
	for ( scanf("%d", &task); task--; ){
			scanf("%d%d", &n, &k);
			for (int i=1; i<=n; i++)
			for (int j=1; j<=k; j++)
				scanf("%d", p[i]+j);
			memset( g, 0, sizeof(g) );
			for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++){
				g[i][j] = true;
				for (int x=1; x<=k; x++)
				if ( p[i][x] <= p[j][x] ){
					g[i][j] = false;
					break;
				}
			}
			int ret = 0;
			memset( x, 0, sizeof(x) );
			for (int i=1; i<=n; i++){
				memset( s, 0, sizeof(s) );
				if ( path( i ) ) ret++;
			}
			printf("Case #%d: %d\n", ++cs, n-ret);
	} 
	return 0;
}
