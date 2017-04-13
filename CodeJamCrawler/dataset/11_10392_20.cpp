#include <cstdio>
using namespace std;
int gcd(int a, int b) {
  int c;
  while (b) {
    c = b;
    b = a % b;
    a = c;
  }
  return a;
}
void solve () {
  int i, N, Pd, Pg, j;
  scanf("%d%d%d", &N, &Pd, &Pg);
  if (Pg == 0 && Pd > 0) {
    printf("Broken\n");
    return;
  }
  if (Pg < 100 || Pd == 100) {
    if (100 / gcd(100, Pd) <= N) {
        printf("Possible\n");
        return;
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
