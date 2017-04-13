#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  int T;
  cin >> T;

  for (int tc = 0; tc < T; ++tc) {
    double C, F, X;
    cin >> C >> F >> X;

    double p_come = 0;
    double p_full = X / 2;
    for (int i = 1; ; ++i) {
      double c_come = p_come + C / (2 + (i - 1) * F);
      double c_full = c_come + X / (2 + i * F);
      if (c_full > p_full) break;

      p_come = c_come;
      p_full = c_full;
    }
    printf("Case #%d: %.7lf\n", tc + 1, p_full);
  }
}

