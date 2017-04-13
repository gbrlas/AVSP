#include <stdio.h>

int main(void) {
  int t;
  scanf("%d\n", &t);
  int e;
  int r, k, n, g[1000];

  for (int i = 0; i < t; i++) {
    e = 0;
    scanf("%d %d %d", &r, &k, &n);
    for (int j = 0; j < n; j++)
      scanf("%d", &g[j]);

    int p = 0;
    for (int j = 0; j < r; j++) {
      int s = k, prim = p;
      do {
	s -= g[p];
	p = (p+1)%n;
      } while (s >= g[p] && p != prim);
      e += k-s;
    }

    printf("Case #%d: %d\n", i+1, e);
  }
  return 0;
}
