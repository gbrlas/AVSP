#include <iostream>
using namespace std;

int dp[501][500];

int choose (int n, int k) {

//  printf("choose %d %d\n", n, k);
  int ans = 1;
  for (int i = 1; i <= k; ++i) {
    ans *= n-(k-i);
    ans /= i;
  }
  return ans%100003;
}

int calc (int num, int pos) {

  if (dp[num][pos] != -1)
    return dp[num][pos];
  int ans = 0;
  if (num < 1)
    ans = 0;
  else if (pos == 0)
    ans = 1;
  else if (num > pos+1) {
    for (int i = 0; i < pos; ++i) {
      if (num-pos+1 >= pos-i) {
        int tans = calc(pos+1, i)*choose(num-pos-2, pos-i-1);
//        printf("%d %d %d %d\n", num, pos, i, tans);
        ans = (ans+tans)%100003;
      }
    }
  }
  return dp[num][pos] = ans;
}

int main () {

  for (int i = 0; i < 501; ++i)
    for (int j = 0; j < 500; ++j)
      dp[i][j] = -1;
//  calc(6,3);

  for (int i = 2; i <= 500; ++i)
    for (int j = 1; j < 500; ++j)
      calc(i, j);

  int T, n;
  scanf("%d", &T);
  for (int c = 1; c <= T; ++c) {
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = (ans+dp[n][i])%100003;
//      printf("%d %d\n", i, dp[n][i]);
    }
    printf("Case #%d: %d\n", c, ans);
  }
  return 0;
}
