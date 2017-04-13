#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=110, maxm=1010;

char data[maxn][200], data2[maxm][200];
int dp[maxn][maxm];
int n, m, task;

int main() {
	freopen("A-small-attempt1.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&task);
	for(int tk=1; tk<=task; tk++){
		scanf("%d\n", &n);
		memset( dp, 0x7f, sizeof(dp) );
		for (int i=1; i<=n; i++){
			gets( data[i] );
			dp[0][i] = 1;
		}
		scanf("%d\n", &m);
		for (int i=1; i<=m; i++) gets( data2[i] );
		
		for (int i=1; i<=m; i++)
		for (int j=1; j<=n; j++)
		if ( strcmp( data2[i], data[j] ) ){
             for (int k=1; k<=n; k++)
                 dp[i][j] = min( dp[i][j], dp[i-1][k]+(j!=k?1:0) );
        }
		
		int ret = m+10;
		for (int i=1; i<=n; i++)
			ret = min( ret, dp[m][i] );
		printf("Case #%d: %d\n", tk, ret-1);
	}
	return 0;
}
