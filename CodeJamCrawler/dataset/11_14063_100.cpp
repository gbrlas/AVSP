#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 105;
int x[2], next[2], n;
int p[N], k[N];

int sign(int x) {
  return x < 0 ? -1 : x > 0;
}

int main() {
  int T, t = 0; scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      char r;
      scanf(" %c %d", &r, &p[i]);
      k[i] = (r == 'B');
    }

    x[0] = x[1] = 1;
    int res = 0;
    for (int s = 0; s < n; s++) {
      next[0] = next[1] = -1;
      for (int i = s; i < n; i++)
        if (next[k[i]] == -1)
          next[k[i]] = p[i];
      int a = k[s], b = !a;
      while (x[a] != next[a]) {
        x[a] -= sign(x[a] - next[a]);
        x[b] -= sign(x[b] - next[b]);
        res++;
      }
      // a press button
      x[b] -= sign(x[b] - next[b]);
      res++;
    }
    printf("Case #%d: %d\n", ++t, res);
  }
  return 0;
}
