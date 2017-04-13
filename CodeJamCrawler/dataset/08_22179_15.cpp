#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

const int mod = 10007;

int dp[111][111];
int W, H, R;
bool nie[111][111];

int main() {
  int tcase;
  scanf("%d", &tcase);
  for(int zz=0; zz<tcase; zz++) {
    scanf("%d%d%d", &H, &W, &R);
    memset(nie, 0, sizeof(nie));
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<R; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      nie[x][y] = true;
    }
    dp[1][1] = 1;
    for(int i=1; i<=H; i++) for(int j=1; j<=W; j++) {
	if(i+1 <= H && j+2 <= W && !nie[i+1][j+2])
	  dp[i+1][j+2] = (dp[i+1][j+2] + dp[i][j]) % mod;
	if(i+2 <= H && j+1 <= W && !nie[i+2][j+1])
	  dp[i+2][j+1] = (dp[i+2][j+1] + dp[i][j]) % mod;

      }
    printf("Case #%d: %d\n", zz+1, dp[H][W]);
  }
}
