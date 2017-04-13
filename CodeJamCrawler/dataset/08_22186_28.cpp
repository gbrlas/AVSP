#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

int N, P, K;
const int mod = 30031;
int dp[1011][(1<<12)];

int main() {
	int tcase;
	scanf("%d", &tcase);
	for(int zz=1; zz<=tcase; zz++) {
		scanf("%d%d%d", &N, &K, &P);
		//printf("N,K,P = %d %d %d\n", N, K, P);
		memset(dp, 0, sizeof(dp));
		int pod = (1<<K)-1;
		pod <<= (P-K+1);
		//printf("pod = %d\n", pod);
		dp[0][pod] = 1;
		for(int i=0; i<N; i++) {
			for(int j=0; j<(1<<P+1); j++) if(dp[i][j]!=0) {
				if(j & (1<<P)) {
					int ns =((j&(~(1<<P)))); 
					for(int w=P-1; w>=0; w--) if((j & (1<<w))==0) {
						int nns = ns | (1<<w);
						nns <<= 1;
						dp[i+1][nns] = (dp[i+1][nns] + dp[i][j] ) % mod;
					}
				} /*else {
					for(int k=P-1; k>=0; k++) if(j & (1<<k)) {
						for(int w=k-1; w>=0; --w) {
							int ns = (((j&(~(1<<k)))) | (1<<w)) << 1;
							dp[i+1][ns] = (dp[i+1][ns] + dp[i][j]) % mod;
						}
						break;
					}
				}*/
			}
		}
		printf("Case #%d: %d\n", zz, dp[N-K][pod]);
	}
}
