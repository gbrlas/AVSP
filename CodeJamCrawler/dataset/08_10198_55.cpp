#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int X[1010], Y[1010], Z[1010], P[1010];

double l4(double x, double y, double z) {
  double powerReq = 0;

  for (int i = 0; i < N; ++i) {
    powerReq = max(powerReq, (fabs(X[i] - x) + fabs(Y[i] - y) + fabs(Z[i] - z)) / P[i]);
  }

  return powerReq;
}

double l3(double x, double y) {
  double lo = 0, hi = 1000000;

  for (int i = 0; i < 100; ++i) {
    double m1 = 2 * lo / 3 + hi / 3;
    double m2 = lo / 3 + 2 * hi / 3;

    double r1 = l4(x, y, m1);
    double r2 = l4(x, y, m2);

    if (r1 < r2) {
      hi = m2;
    } else {
      lo = m1;
    }
  }

  return l4(x, y, (lo + hi) / 2);
}

double l2(double x) {
  double lo = 0, hi = 1000000;

  for (int i = 0; i < 100; ++i) {
    double m1 = 2 * lo / 3 + hi / 3;
    double m2 = lo / 3 + 2 * hi / 3;

    double r1 = l3(x, m1);
    double r2 = l3(x, m2);

    if (r1 < r2) {
      hi = m2;
    } else {
      lo = m1;
    }
  }

  return l3(x, (lo + hi) / 2);
}

double l1() {
  double lo = 0, hi = 1000000;

  for (int i = 0; i < 100; ++i) {
    double m1 = 2 * lo / 3 + hi / 3;
    double m2 = lo / 3 + 2 * hi / 3;

    double r1 = l2(m1);
    double r2 = l2(m2);

    if (r1 < r2) {
      hi = m2;
    } else {
      lo = m1;
    }
  }

  return l2((lo + hi) / 2);
}

int main() {
  int kk;
  scanf("%d", &kk);

  for (int k = 1; k <= kk; ++k) {
    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
      scanf("%d%d%d%d", &X[i], &Y[i], &Z[i], &P[i]);
    }

    printf("Case #%d: %.09f\n", k, l1());
  }

  return 0;
}