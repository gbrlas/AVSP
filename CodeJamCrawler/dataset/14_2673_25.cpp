#include <stdio.h>
#include <float.h>

void solve() {
  double c, f, x;
  scanf("%lf %lf %lf", &c, &f, &x);
  double a = 2, b = 0;
  double best_t = DBL_MAX;
  while (1) {
    double t = (x - b) / a;
    if (t < best_t) {
      best_t = t;
    } else {
      break;
    }
    b = (( f * b - c * f) / a) + b - c;
    a += f;
  }
  printf("%.7lf\n", best_t);
}

int main() {
  int t;
  scanf("%d\n", &t);
  for (int i = 1; i <= t; i++) {
    printf("Case #%d: ", i);
    solve();
  }
}
