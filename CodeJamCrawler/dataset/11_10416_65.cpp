#include <cstdio>
#define MAXR 50
#define MAXC 50
using namespace std;
void solve () {
  int R, C, i, j;
  char lenta[MAXR][MAXC + 1];
  scanf("%d %d\n", &R, &C);
  for (i = 0; i < R; i++)
    scanf("%s\n", lenta[i]);
  for (i = 0; i < R; i++) {
    for (j = 0; j < C; j++) {
      if (lenta[i][j] == '#') {
        if (i == R - 1 || j == C - 1 || lenta[i][j + 1] != '#' || lenta[i + 1][j] != '#' || lenta[i + 1][j + 1] != '#')
          break;
        lenta[i][j] = '/';
        lenta[i][j + 1] = '\\';
        lenta[i + 1][j] = '\\';
        lenta[i + 1][j + 1] = '/';
      }
    }
    if (j != C)
      break;
  }
  if (i != R) {
    printf("Impossible\n");
  } else {
    for (i = 0; i < R; i++)
      printf("%s\n", lenta[i]);
  }
}
int main() {
  int T, t;
  scanf("%d", &T);
  for (t = 1; t <= T; t++) {
    printf("Case #%d:\n", t);
    solve();
  }
}
