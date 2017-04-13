#include <cstdio>
#define MAXN 1000
using namespace std;
void solve () {
  long long N, L, H, i, fr[MAXN], j;
  scanf("%lld %lld %lld", &N, &L, &H);
  for (i = 0; i < N; i++) {
    scanf("%lld", fr + i);
  }
  if (L == 1) {
    printf("1\n");
  } else {
    for (i = L; i <= H; i++) {
      for (j = 0; j < N; j++) {
        if (i % fr[j] != 0 && fr[j] % i != 0)
          break;
      }
      if (j == N) {
        printf("%lld\n", i);
        return;
      }
    }
    printf("NO\n");
  }
}
int main() {
  int T, t;
  scanf("%d", &T);
  for (t = 1; t <= T; t++) {
    printf("Case #%d: ", t);
    solve();
  }
}
