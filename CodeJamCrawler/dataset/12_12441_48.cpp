#include <stdio.h>
#include <algorithm>
using namespace std;

struct girl {
  int r, i, x, y;
};

bool rcmp(girl a, girl b) {
  return a.r > b.r;
}

bool icmp(girl a, girl b) {
  return a.i < b.i;
}

const int N = 1024;

int n, w, h;
girl a[N];

int main() {
  int T, tc = 0;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d %d", &n, &w, &h);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i].r);
      a[i].i = i;
    }
    sort(a, a + n, rcmp);

    int i = 0, x = 0, y = 0;
    while (i < n) {
      int i1 = i;
      while (i < n && x <= w) {
        a[i].x = x;
        a[i].y = y;
        if (y > h) puts("ooops");
        x += a[i].r + a[i + 1].r;
        i++;
      }
      if (i >= n) break;
      y += a[i1].r + a[i].r;
      x = 0;
    }

    sort(a, a + n, icmp);
    printf("Case #%d:", ++tc);
    for (int i = 0; i < n; i++)
      printf(" %d %d", a[i].x, a[i].y);
    puts("");
  }
  return 0;
}

