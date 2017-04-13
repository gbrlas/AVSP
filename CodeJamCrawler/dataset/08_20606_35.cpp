#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=13;

int dp[maxn][1<<11], g[maxn];
int task, n, m, bit[maxn];
char ch;

bool BIT( int mask, int o ){
	if ( (mask&bit[o])!=0 ) return true;else return false;
}

bool check( int mask ){
	for (int i=0; i<m-1; i++)
	if ( BIT( mask,i ) && BIT( mask, i+1 ) ) return false;
	return true;
}
bool check2( int mask, int mask2 ){
	for (int i=0; i<m; i++){
	   if ( i<m-1 && BIT( mask,i ) && BIT( mask2, i+1 ) ) return false;
	   if ( i>0 && BIT( mask,i ) && BIT( mask2, i-1 ) ) return false;
	}
	return true;
}

int main(){
	freopen("C-small-attempt1.in","r",stdin);
	freopen("a.out","w",stdout);
    bit[0] = 1;
	for (int i=1; i<=11; i++)
		bit[i] = bit[i-1]<<1;
	scanf("%d\n", &task);
	for (int tk=1; tk<=task; tk++){
		scanf("%d%d\n", &n, &m);
		for (int i=1; i<=n; i++){
			g[i] = 0;
			for (int j=1; j<=m; j++){
				scanf("%c", &ch);
				g[i] = g[i]<<1;
				if ( ch=='x' ) g[i] += 1;
			}
			scanf("\n");
		}
		memset( dp, 0, sizeof(dp) );
		for (int mask=0; mask<(1<<m); mask++)
		if ( (mask&g[1])==0 && check(mask) ){
			dp[1][mask] = __builtin_popcount(mask);
		}

		for (int i=2; i<=n; i++)
		for (int mask=0; mask<(1<<m); mask++)if ( (mask&g[i])==0 && check(mask) ) 
		for (int mask2=0; mask2<(1<<m); mask2++)if ( (mask2&g[i-1])==0 && check(mask2) )
		if ( check2( mask, mask2 ) )
		  dp[i][mask] >?= dp[i-1][mask2]+__builtin_popcount(mask);

		int ret=0;
		for (int mask=0; mask<(1<<m); mask++)
			ret >?= dp[n][mask];
		printf("Case #%d: %d\n", tk, ret);
	}
	return 0;
}
