#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
  int tcase;
  scanf("%d", &tcase);
  for(int zz=0; zz<tcase; zz++) {
    int best = 10000000;
    int n, m, V;
    scanf("%d%d", &n, &V);
    int dp[n+11][2];
    int can[n+11];
    int val[n+11];
    memset(can, 0, sizeof(can));
    memset(dp, 63, sizeof(dp));
    for(int i=1; i<=n; i++) {
      scanf("%d", &val[i]);
      if(i+i<=n) {
	scanf("%d", &can[i]);
      }
    }

    for(int i=n; i>=1; i--) for(int v = 0; v<2; v++) {
	if(i+i>n) {
	  if(v == val[i]) dp[i][v] = 0;
	  else dp[i][v] = n+10000;
	  continue;
	}
	for(int s=0; s<4; s++) {
	  int left=  s&1;
	  int ri = (s&3)>>1;
	  if(val[i] == 1) {
	    //AND gate
	    if((left & ri) == v) dp[i][v] = min(dp[i][v], dp[i+i][left] + dp[i+i+1][ri]);
	  } else if((left | ri) == v) dp[i][v] = min(dp[i][v], dp[i+i][left]+dp[i+i+1][ri]);
	}
	if(can[i] == 1) {
	  for(int s=0; s<4; s++) {
	    int left=  s&1;
	    int ri = (s&3)>>1;
	    if(val[i] == 0) {
	      //AND gate
	      if((left & ri) == v) dp[i][v] = min(dp[i][v], 1+dp[i+i][left] + dp[i+i+1][ri]);
	    } else if((left | ri) == v) dp[i][v] = min(dp[i][v], 1+dp[i+i][left]+dp[i+i+1][ri]);
	  }
	
	}
      }
    
    best = dp[1][V];
    if(best > n) printf("Case #%d: IMPOSSIBLE\n", zz+1);
    else printf("Case #%d: %d\n", zz+1, best);
  }
}
