#include <cstdio>
using namespace std;
void solve () {
  int N, i, min, x, a, sum;
  scanf("%d %d", &N, &x);
  min = x;
  sum = x;
  for (i = 1; i < N; i++) {
    scanf("%d", &a);
    if (min > a)
      min = a;
    x ^= a;
    sum += a;
  }
  if (x)
    printf("NO\n");
  else
    printf("%d\n", sum - min);
}
int main() {
  int T, t;
  scanf("%d", &T);
  for (t = 1; t <= T; t++) {
    printf("Case #%d: ", t);
    solve();
  }
}
