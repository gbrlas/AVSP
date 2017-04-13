#include <iostream>
using namespace std;

int g[1000];
int next[1000];
long long sum[1000];

int main () {

  int T, R, k, N;
  scanf("%d", &T);
  for (int c = 1; c <= T; ++c) {
    scanf("%d %d %d", &R, &k, &N);
    for (int i = 0; i < N; ++i)
      scanf("%d", g+i);
    long long s = 0;
    int n = 0;
    int added = 0;
    for (int i = 0; i < N; ++i) {
      if (added == 0) {
        s = 0;
        n = i;
      }
      while (s+g[n] <= k && (added == 0 || n != i)) {
        s += g[n];
        n = (n+1)%N;
        ++added;
//        printf(">%d %lld %d\n", i, s, n);
      }
      sum[i] = s;
      next[i] = n;
      s -= g[i];
      if (added > 0)
        --added;
//      printf("%d %lld %d\n", i, sum[i], next[i]);
    }
    long long ans = 0;
    n = 0;
    for (int i = 0; i < R; ++i) {
      ans += sum[n];
      n = next[n];
    }
    printf("Case #%d: %lld\n", c, ans);
  }
}
