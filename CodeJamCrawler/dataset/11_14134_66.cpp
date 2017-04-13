#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int gcd(int x, int y) {
  return y ? gcd(y, x % y) : x;
}

int lcm(int x, int y) {
  return x / gcd(x, y) * y;
}

const int N = 1010;
int p[N], f[N];

int main() {

  for (int i = 2; i < N; i++)
    p[i] = 0;
  for (int i = 2; i < N; i++)
    if (!p[i]) {
      for (int j = i; j < N; j += i)
        p[j] = i;
    }

  f[1] = 1;
  for (int i = 2; i < N; i++) {
    int j = i / p[i];
    f[i] = (j == 1 || p[i] == p[j]) && f[j];
  }

  int T, ca = 0; scanf("%d", &T);
  while (T--) {
    int n; scanf("%d", &n);

    int mint = 0;
    for (int i = 2; i <= n; i++) {
      if (p[i] == i) mint++;
    }
    if (n == 1) mint = 1;

    int maxt = 1;
    for (int i = 2; i <= n; i++) {
      if (f[i]) maxt++;
    }

    printf("Case #%d: %d\n", ++ca, maxt - mint);
//  printf("Case #%d: %d %d %d\n", ++ca, maxt, mint, maxt - mint);
  }
  return 0;
}
