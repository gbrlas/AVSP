#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=10010, INF=1000000000;

int dp[maxn][2], data[maxn][2];
int task, n, vl, x;

int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d", &task);
	for (int tk=1; tk<=task; tk++){
		scanf("%d%d", &n, &vl);
		for (int i=1; i<=(n-1)/2; i++)
			scanf("%d%d", &data[i][0], &data[i][1]);
		for (int i=(n-1)/2+1; i<=n; i++){
			scanf("%d", &x);
			dp[i][x] = 0; 
			dp[i][x^1] = INF;
		}

		for (int i=(n-1)/2; i>=1; i--){
			for (int x=0; x<=1; x++){
				dp[i][x] = INF;
				for (int y=0; y<=1; y++)
				for (int z=0; z<=1; z++){
					if ( data[i][0]==1 && ((y&z)==x) || data[i][0]!=1 && ((y|z)==x) )
						dp[i][x] = min( dp[i][x], dp[i*2][y]+dp[i*2+1][z] );  
					if ( data[i][1]==1 &&( data[i][0]==1 && ((y|z)==x) || data[i][0]!=1 && ((y&z)==x) ) )
						dp[i][x] = min( dp[i][x], dp[i*2][y]+dp[i*2+1][z]+1 );  					
				}
//				cout<<i<<' '<<x<<' '<<dp[i][x]<<endl;
			}
		}

		if ( dp[1][vl]>=INF )
			printf("Case #%d: IMPOSSIBLE\n", tk);else
			printf("Case #%d: %d\n", tk, dp[1][vl]);
	}
	return 0;
}
