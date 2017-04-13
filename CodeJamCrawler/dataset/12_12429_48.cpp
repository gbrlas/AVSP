#include <stdio.h>
#include <algorithm>

const int N = 12800;
const int INF = 0x3f3f3f3f;

int n, D;
int d[N], l[N];
int f[N];

int main() {
  int T, tc = 0;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d %d", &d[i], &l[i]);
    scanf("%d", &D);
    l[n] = 0;
    d[n++] = D;

    int p = 1;
    for (int i = 1; i < n; i++)
      if (d[i] <= d[0] * 2) {
        f[i] = 0;
        p++;
      } else {
        f[i] = INF;
      }

    for (int i = 1; i < n; i++) if (f[i] < INF) {
      int j = f[i];
//      printf("f[%d] = %d\n", i, j);
      while (p < n && d[p] <= d[i] + std::min(d[i] - d[j], l[i]))
        f[p++] = i;
    }
    printf("Case #%d: %s\n", ++tc, f[n - 1] < INF ? "YES" : "NO");
  }
  return 0;
}
