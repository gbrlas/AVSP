#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 20;
int n, m;
int a[N][N];

int solve(int x1, int x2, int y1, int y2) {
  int cx = x1 + x2;
  int cy = y1 + y2;
  int vx = 0;
  int vy = 0;
  for (int i = x1; i <= x2; i++)
    for (int j = y1; j <= y2; j++) if (!((i == x1 || i == x2) && (j == y1 || j == y2))) {
      vx += (i * 2 - cx) * a[i][j];
      vy += (j * 2 - cy) * a[i][j];
    }
  return !vx && !vy;
}

int main() {
  int T, ca = 0; scanf("%d", &T);
  while (T--) {
    scanf("%d %d %*d", &n, &m);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        scanf("%1d", &a[i][j]);

    int ans = -1;
    for (int p = min(m, n); ans == -1 && p >= 3; p--) {
      for (int i = 0; ans == -1 && i + p - 1 < n; i++)
        for (int j = 0; ans == -1 && j + p - 1 < m; j++)
          if (solve(i, i + p - 1, j, j + p - 1))
            ans = p;
    }

    printf("Case #%d: ", ++ca);
    if (ans == -1)
      puts("IMPOSSIBLE");
    else
      printf("%d\n", ans);
  }
  return 0;
}
