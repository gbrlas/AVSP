#include <stdio.h>

typedef long long ll;

int gcd(int x, int y) {
  return !y ? x : gcd(y, x % y);
}

int main() {
  int T; scanf("%d", &T);
  int t = 0;
  while (T--) {
    printf("Case #%d: ", ++t);
    ll n;
    int pd, pg, a, b, c, d, g;
    scanf("%lld %d %d", &n, &pd, &pg);
    a = pd; b = 100 - pd;
    c = pg; d = 100 - pg;
    g = gcd(a, b); a /= g; b /= g;
    g = gcd(c, d); c /= g; d /= g;
    if (a && !c || b && !d || a + b > n)
      puts("Broken");
    else
      puts("Possible");
  }
  return 0;
}
