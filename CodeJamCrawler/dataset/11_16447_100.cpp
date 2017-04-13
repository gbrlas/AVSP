#include <algorithm>
#include <cstdio>

using namespace std;

const int MAX = (1 << 20);

int main(int argc, char *argv[]) {
  int tc;
  scanf("%d", &tc);
  for (int i = 1; i <= tc; ++i) {
    int n;
    scanf("%d", &n);

    int sum = 0;
    int xsum = 0;
    int small = MAX;
    int t;
    for (int j = 0; j < n; ++ j) {
      scanf("%d", &t);
      sum += t;
      small = min(small, t);
      xsum ^= t;
    }
    if (xsum) {
      printf("Case #%d: NO\n", i);
    } else {
      printf("Case #%d: %d\n", i, sum - small);
    }
  }
  return 0;
}
