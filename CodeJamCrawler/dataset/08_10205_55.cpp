#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int ITER = 100;

int N;
int X[1010], Y[1010], Z[1010], _P[1010];
double P[1010];

double my_abs(double z) {
  if (z > 0)
    return z;
  return -z;
}

double l4(double x, double y, double z) {
  double powerReq = 0;

  for (int i = 0; i < N; ++i) {
    powerReq = max(powerReq, (my_abs(X[i] - x) + my_abs(Y[i] - y) + my_abs(Z[i] - z)) * P[i]);
  }

  return powerReq;
}

double l3(double x, double y, int num_iter) {
  double lo = 0, hi = 1000000;

  for (int i = 0; i < num_iter; ++i) {
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

double l2(double x, int num_iter) {
  double lo = 0, hi = 1000000;

  for (int i = 0; i < num_iter; ++i) {
    double m1 = 2 * lo / 3 + hi / 3;
    double m2 = lo / 3 + 2 * hi / 3;

    double r1 = l3(x, m1, num_iter);
    double r2 = l3(x, m2, num_iter);

    if (r1 < r2) {
      hi = m2;
    } else {
      lo = m1;
    }
  }

  return l3(x, (lo + hi) / 2, num_iter);
}

double l1() {
  double lo = 0, hi = 1000000;

  for (int i = 0; i < ITER; ++i) {
    double m1 = 2 * lo / 3 + hi / 3;
    double m2 = lo / 3 + 2 * hi / 3;
    double r1, r2;

    if (i < 5 * ITER / 6) {
      r1 = l2(m1, ITER / 3);
      r2 = l2(m2, ITER / 3);
    } else {
      r1 = l2(m1, ITER);
      r2 = l2(m2, ITER);
    }

    if (r1 < r2) {
      hi = m2;
    } else {
      lo = m1;
    }
  }

  return l2((lo + hi) / 2, ITER);
}

int main() {
  int kk;
  scanf("%d", &kk);

  for (int k = 1; k <= kk; ++k) {
    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
      scanf("%d%d%d%d", &X[i], &Y[i], &Z[i], &_P[i]);
      P[i] = 1.0 / _P[i];
    }

    printf("Case #%d: %.09f\n", k, l1());
  }

  return 0;
}