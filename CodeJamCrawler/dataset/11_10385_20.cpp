#include <cstdio>
using namespace std;
void solve () {
  int i, N, Pd, Pg, D, j;
  scanf("%d%d%d", &N, &Pd, &Pg);
  if (Pg == 0 && Pd > 0) {
    printf("Broken\n");
    return;
  }
  if (Pg < 100 || Pd == 100) {
    for (i = 1; i <= N; i++) {
      if (i * Pd % 100 == 0) {
        printf("Possible\n");
        return;
      }
    }
  }
  printf("Broken\n");
}
int main() {
  int T, t;
  scanf("%d", &T);
  for (t = 1; t <= T; t++) {
    printf("Case #%d: ", t);
    solve();
  }
}
