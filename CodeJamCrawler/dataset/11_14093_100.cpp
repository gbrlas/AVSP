#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 11;
int n;
int a[N];

int main() {
  int T, ca = 0; scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]), a[i]--;

    int ans = 0;
    for (int i = 0; i < n; i++)
      ans += a[i] != i;

    printf("Case #%d: %d.000000\n", ++ca, ans);
  }
  return 0;
}
