/* Language: C
 * (gcc 4.5.2 on Windows 7)
 */

#include <stdio.h>

int main() {
  int t, i;
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    int ans = 0, a, b, n;
    scanf("%d %d", &a, &b);
    for (n = a; n <= b; n++) {
      int tmp = n, nlen = 0, fac = 1, oth;
      while (tmp > 0) {
        tmp /= 10;
        nlen++;
        fac *= 10;
      }
      fac /= 10;
      oth = n;
      for (tmp = 0; tmp < nlen - 1; tmp++) {
        oth = oth / 10 + fac * (oth % 10);
        if (oth != n && a <= oth && oth <= b) {
          ans++;
        } else if (oth == n) {
          break;
        }
      }
    }
    printf("Case #%d: %d\n", i+1, ans / 2);
  }
  return 0;
}
