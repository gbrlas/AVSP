#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 1024;
int n;
int a[N];

int main() {
  int T, ca = 0; scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    int minx = 0x7f7f7f7f, sumx = 0, bitx = 0;
    for (int i = 0; i < n; i++) {
      int x; scanf("%d", &x);
      sumx += x;
      minx = min(minx, x);
      bitx ^= x;
    }
    printf("Case #%d: ", ++ca);
    if (bitx)
      puts("NO");
    else
      printf("%d\n", sumx - minx);
  }
  return 0;
}
