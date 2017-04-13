#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn=50;

typedef int ARR[maxn][maxn];
ARR a[3], b[3];
int dep[3][maxn], dep1[3][maxn], mk[maxn];
int e[maxn][2];
bool fnd[maxn];
int task, n, m, x, y, Tsum;

int comp( int t1, int p1, int t2, int p2 ){
	if ( dep[t1][p1]>dep[t2][p2] ) return 1;
	if ( dep[t1][p1]<dep[t2][p2] ) return 2;
	int j;
	for (int i=1; i<=dep[t1][p1]; i++){
		j = comp( t1, a[t1][p1][i], t2, a[t2][p2][i] );
		if ( j!=0 ) return j;
	}
	return 0;
}
void Tsort( int t, int p ){
	for (int i=1; i<=dep[t][p]; i++)
		Tsort( t, a[t][p][i] );
	for (int i=1; i<=dep[t][p]-1; i++)
	for (int j=i+1; j<=dep[t][p]; j++)
	if ( comp( t, a[t][p][i], t, a[t][p][j] )==1 ){
		swap( a[t][p][i], a[t][p][j] );
	}
}

void dfs( int o, int x ){
	fnd[x] = true;
	Tsum++;
	for (int i=1; i<=dep1[o][x]; i++)
	if ( !fnd[ b[o][x][i] ] ){
		a[o][x][ ++dep[o][x] ] = b[o][x][i];
		dfs( o, b[o][x][i] );
	}
}

int main(){
	freopen("D-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d\n", &task);
	for (int tk=1; tk<=task; tk++){
		printf("Case #%d: ", tk);
		memset( dep1, 0, sizeof(dep1) );

		scanf("%d", &n);
		for (int i=0; i<n-1; i++)
			scanf("%d%d", e[i], e[i]+1);
		scanf("%d", &m);
		for (int i=0; i<m-1; i++){
			scanf("%d%d", &x, &y);
			b[2][x][ ++dep1[2][x] ] = y;
			b[2][y][ ++dep1[2][y] ] = x;
		}

		bool ok = false;
		int sum;
		for (int mask=0; mask<(1<<n); mask++)
		if ( __builtin_popcount(mask)==m )
		{
//			cout<<mask<<endl;
			sum = 0;
			memset( mk, 0, sizeof(mk) );
			for (int i=0; i<n; i++)
			if ( ( mask&(1<<i) )!=0 ){
				mk[i+1] = ++sum;
			}
			memset( dep1[1], 0, sizeof(dep1[1]) );

			for (int i=0; i<n-1; i++){
				x = mk[e[i][0]]; y = mk[e[i][1]];
				if ( x!=0 && y!=0 ){
					b[1][x][ ++dep1[1][x] ] = y;
					b[1][y][ ++dep1[1][y] ] = x;
				}
			}

			for (int i=1; i<=m; i++)
			for (int j=1; j<=m; j++)if ( !ok ){
				memset( dep, 0, sizeof(dep) );
				memset( fnd, 0, sizeof(fnd) );
				Tsum = 0;
				dfs( 1, i );
				if ( Tsum!=m ) break;
				memset( fnd, 0, sizeof(fnd) );
				dfs( 2, j );
				
				Tsort( 1, i );
				Tsort( 2, j );

				if ( comp( 1,i,2,j )==0 ){
					ok = true;
					break;
				}
			}
			if ( ok ) break;
		}
		if ( ok ) printf("YES\n");else printf("NO\n");
	}
	return 0;
}
