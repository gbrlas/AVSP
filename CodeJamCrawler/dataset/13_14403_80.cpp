/*
 * Language: C
 * Compiler: gcc 4.4.5-8
 */
#include <stdio.h>

int main() {
  int t, n, m, c, i, j, k;
  int a[10000];
  scanf("%d", &t);
  for (c = 1; c <= t; c++) {
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        scanf("%d", &a[i * m + j]);
      }
    }
    int all = 1;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        int nr = 1, mr = 1;
        for (k = 0; k < n; k++) {
          if (a[k * m + j] > a[i * m + j]) {
            nr = 0;
          }
        }
        for (k = 0; k < m; k++) {
          if (a[i * m + k] > a[i * m + j]) {
            mr = 0;
          }
        }
        if (!nr && !mr) {
          all = 0;
        }
      }
    }
    printf("Case #%d: %s\n", c, all ? "YES" : "NO");
  }
  return 0;
}
