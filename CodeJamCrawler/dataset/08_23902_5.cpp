#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(i=0;i<n;i++)
#define F1(i,n) for(i=1;i<=n;i++)
const int inf = 1000000009;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;

int H, W, R;
int board[300][300] = {0};
int dp[300][300] = {0};

int main() {

	int tt, tn;
	cin >> tn;
	F1(tt,tn) {
		cin >> H >> W >> R;
		
		for (int i = 0; i < 300; i++)
			for (int j = 0; j < 300; j++)
				board[i][j] = dp[i][j] = 0;
		
		for (int i = 0; i < R; i++) {
			int r, c;
			cin >> r >> c;
			board[r + 3][c + 3] = 1;
		}
		dp[4][4] = 1;
		for (int j = 4; j <= W + 3; j++) {
			for (int i = 4; i <= H + 3; i++) {
				if (i == 4 && j == 4) continue;
				if (board[i][j] == 1) continue;
				dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j - 2]) % 10007;
		
			}
		}
		
		printf("Case #%d: %d\n", tt, dp[H + 3][W + 3]);
	}

	return 0;
}

