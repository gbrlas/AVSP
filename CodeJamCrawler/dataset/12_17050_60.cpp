#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int T,N,S,p;
int A[105];
int dp[105][105];

int add(int a, int t) {
  if (t == 1) {
    return (a+2)/3 >= p;
  } else {
    if (a < 2) return a >= p;
    return (a+4)/3 >= p;
  }
}

int main() {
  scanf("%d ",&T);
  for (int TC = 1; TC <= T; TC++) {
    scanf("%d %d %d ",&N, &S, &p);
    for (int i = 1; i <= N; i++) scanf("%d ", A+i);
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) 
      dp[i][0] = dp[i-1][0] + add(A[i], 1);
    for (int k = 1; k <= S; k++)
      for (int i = 1; i <= N; i++)
        dp[i][k] = max(dp[i-1][k] + add(A[i], 1), dp[i-1][k-1] + add(A[i], 2));
    printf("Case #%d: %d\n",TC, dp[N][S]);
  }
  return 0;
}
