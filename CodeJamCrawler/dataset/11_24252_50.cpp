#include "cmath"
#include "cstdio"
#include "algorithm"
#include "map"
#include "numeric"
#include "queue"
#include "set"
#include "string"
#include "utility"
#include "vector"
using namespace std;
typedef long long i64;

int main() {
  int T; scanf("%d", &T);
  for (int Ti = 1; Ti <= T; ++Ti) {
    fprintf(stderr, "Case #%d of %d...\n", Ti, T);
    int n; scanf("%d ", &n);

    int xors = 0;
    i64 total = 0;
    i64 min = 9999999;

    for (int i = 1; i <= n; ++i)
    {
        int Ci; scanf("%d", &Ci);
        if(Ci < min) min = Ci;
        xors ^= Ci;
        total += Ci;

        fprintf(stderr, "Debugs - Ci %d, min %d, xors %d, total %d\n", Ci, min, xors, total);
    }

    if (xors != 0) printf("Case #%d: %s\n", Ti, "NO");
    else printf("Case #%d: %d\n", Ti, total - min);
  }
  return 0;
}
