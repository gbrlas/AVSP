#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const double eps = 1e-7;
const int N = 1010;

struct node {
  double s, v, t;
} a[N];

double x, s, r, t;
int n;

bool cmp(node a, node b) {
  return a.v < b.v;
}

int main() {
  int T, ca = 1; scanf("%d", &T);
  while (T--) {
    scanf("%lf %lf %lf %lf %d", &x, &s, &r, &t, &n);
    r -= s;
    a[n].s = x;
    a[n].v = s;
    for (int i = 0; i < n; i++) {
      double b, e, w;
      scanf("%lf %lf %lf", &b, &e, &w);
      a[i].s = e - b;
      a[i].v = w + s;
      a[n].s -= a[i].s;
    }
    n++;
    sort(a, a + n, cmp);

//  for (int i = 0; i < n; i++) 
//    printf("%lf %lf\n", a[i].s, a[i].v);

    for (int i = 0; i < n; i++) {
      double tt = min(t, a[i].s / (r + a[i].v));
      t -= tt;
//    printf("%d tt=%lf\n", i, tt);
      a[i].t = tt;
      a[i].s -= (r + a[i].v) * tt;
      a[i].t += a[i].s / a[i].v;
    }

    double ans = 0;
    for (int i = 0; i < n; i++)
      ans += a[i].t;
    printf("Case #%d: %.9lf\n", ca++, ans);
  }
  return 0;
}
