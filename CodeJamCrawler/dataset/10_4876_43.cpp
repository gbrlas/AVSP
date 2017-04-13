#include <stdio.h>

int main(void) {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {

    int n, k;
    scanf("%d %d", &n, &k);

    int ok = (k+1) % (1<<n) == 0;

    printf("Case #%d: ", i+1);
    if (ok)
      printf("ON\n");
    else
      printf("OFF\n");
  }
  return 0;
}
