#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 2048;
const int LIM = 1000000000;

ll udiv(ll x, ll y) {
  return (x + y - 1) / y;
}

ll ddiv(ll x, ll y) {
  return x / y;
}

int n;
int a[N];
int q[N], s, t;
int y[N];

int main() {
  int T, tc = 0;
  scanf("%d", &T);
  while (T--) {
    printf("Case #%d:", ++tc);

    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
      scanf("%d", &a[i]);
      a[i]--;
    }

    y[n - 1] = y[n - 2] = LIM / 2;

    s = t = n;
    q[--s] = n - 1;
    q[--s] = n - 2;

    int ok = 1;
    for (int i = n - 3; i >= 0; i--) {
      int j = a[i];
      int z;
      for (z = s; z < t; z++)
        if (q[z] == j)
          break;
      if (z == t) {
        ok = 0;
        goto finish;
      }
//      printf("i=%d\n", i);
//      printf("j=%d\n", j);
      ll lb, ub;
      int j1, j2;
      if (z == s) {
        lb = 0;
        j1 = q[z];
        j2 = q[z + 1];
        ub = udiv((ll)(i - j1) * (y[j2] - y[j1]) + (ll)y[j1] * (j2 - j1), j2 - j1) - 1;
        y[i] = ub;
        y[i] = max(ub - N, (lb + ub) / 2);
      } else if (z == t - 1) {
        ub = LIM;
        j1 = q[z - 1];
        j2 = q[z];
        lb = ddiv((ll)(i - j1) * (y[j2] - y[j1]) + (ll)y[j1] * (j2 - j1), j2 - j1) + 1;
        y[i] = lb;
        y[i] = min(lb + N, (lb + ub) / 2);
      } else {
        j1 = q[z];
        j2 = q[z + 1];
        ub = udiv((ll)(i - j1) * (y[j2] - y[j1]) + (ll)y[j1] * (j2 - j1), j2 - j1) - 1;
        j1 = q[z - 1];
        j2 = q[z];
        lb = ddiv((ll)(i - j1) * (y[j2] - y[j1]) + (ll)y[j1] * (j2 - j1), j2 - j1) + 1;
        ub = min(ub, (ll)LIM);
        lb = max(lb, 0ll);
        y[i] = (lb + ub) / 2;
      }
      if (lb > ub) {
        puts("ooops");
        printf("i=%d j=%d %lld %lld\n", i, j, lb, ub);
        for (int z = s; z < t; z++)
          printf("%d %d\n", q[z], y[q[z]]);
        goto finish;
      }

      // update convex
      s = z;
      q[--s] = i;
    }
finish:
    if (ok) {
      for (int i = 0; i < n; i++)
        printf(" %d", y[i]);
      puts("");
    } else {
      puts(" Impossible");
    }
  }
  return 0;
}
