#include <stdio.h>

#define MAX_N 30

int main() {
  freopen("snapper.out", "w", stdout);

  int cases;
  int n, k;
  int i;

  scanf("%d\n", &cases);

  for (i = 0; i < cases; i++) {
    scanf("%d %d\n", &n, &k);
    printf("Case #%d: %s\n", i + 1, (k & (1 << n) - 1) == (1 << n) - 1 ? "ON" : "OFF");
  }

  return 0;
}
