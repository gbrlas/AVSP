#include <algorithm>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) {
  int tc;
  scanf("%d", &tc);
  for (int i = 1; i <= tc; ++i) {
    int n;
    scanf("%d", &n);

    int sum = 0, t;
    for (int j = 1; j <= n; ++ j) {
      scanf("%d", &t);
      sum += (t != j);
    }
    printf("Case #%d: %.6f\n", i, (float)sum);
  }
  return 0;
}
