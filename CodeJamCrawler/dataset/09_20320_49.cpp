#include <cstdio>
#include <cstring>

using namespace std;

int n,k;
int p[110][30];
int from[110];
bool g[110][110];
bool use[110];
int ans;

bool dfs( int x ){
	for ( int i=0; i<n; i++ )
		if ( ! use[i] && g[x][i] ){
			use[i]=true;
			if ( from[i]==-1 || dfs( from[i] ) ){
				from[i]=x; return true;
			}
		}
	return false;
}

int main(){
	int test=0;
	scanf("%d", &test);
	for ( int T=1; T<=test; T++ ){
		scanf("%d %d", &n, &k);
		for ( int i=0; i<n; i++ )
			for ( int j=0; j<k; j++ )
				scanf("%d", &p[i][j]);
		memset( g, false, sizeof( g ) );
		for ( int i=0; i<n; i++ )
			for ( int j=0; j<n; j++ ){
				bool ok=true;
				for ( int t=0; t<k; t++ )
					if ( p[i][t]>=p[j][t] ){
						ok=false; break;
					}
				g[i][j]=ok;
				//printf("%d %d %d\n", i, j, g[i][j]);
			}
		memset( from, -1, sizeof( from ) );
		ans=0;
		for ( int i=0; i<n; i++ ){
			memset( use, false, sizeof( use ) );
			if ( dfs(i) )
				ans++;
		}
		printf("Case #%d: %d\n", T, n-ans);
	}
}
