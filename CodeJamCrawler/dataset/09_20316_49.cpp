#include <cstdio>
#include <cstring>

using namespace std;

int n,k;
int p[110][30];
bool g[110][110];
int ok[110][110];
int totg;
bool can;
int limit;

void dfs( int x ){
	if ( x==n ){
		can=true; return;
	}
	if ( totg<limit ){
		totg++; //tot[totg]=1; wh[totg][1]=x;
		for ( int j=0; j<n; j++ )
			if ( g[x][j] )
				ok[j][totg]++;		
		dfs(x+1);
		for ( int j=0; j<n; j++ )
			if ( g[x][j] )
				ok[j][totg]--;
		totg--;
	}
	for ( int i=1; i<=totg; i++ )
		if ( ok[x][i]==0 ){
			//tot[i]++; wh[i][tot[i]]=x;
			for ( int j=0; j<n; j++ )
				if ( g[x][j] )
					ok[j][i]++;
			dfs(x+1);
			if ( can ) return;
			for ( int j=0; j<n; j++ )
				if ( g[x][j] )
					ok[j][i]--;
			//tot[i]--;
		}
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
			for ( int j=i+1; j<n; j++ ){
				bool ok=false;
				for ( int t=0; t<k; t++ ){
					if ( p[i][t]==p[j][t] ){
						ok=true; break;
					}
					if ( t!=0 && ( p[i][t-1]>p[j][t-1] && p[i][t]<p[j][t]  ||  p[i][t-1]<p[j][t-1] && p[i][t]>p[j][t] ) ){
						ok=true; break;
					}
				}
				g[i][j]=g[j][i]=ok;
				//printf("%d %d %d\n", i, j, g[i][j]);
			}
		memset( ok, 0, sizeof( ok ) );
		can=false;
		for ( limit=1; limit<=n; limit++ ){
			dfs(0);
			if ( can ){
				printf("Case #%d: %d\n", T, limit);
				break;
			}
		}
	}
}

