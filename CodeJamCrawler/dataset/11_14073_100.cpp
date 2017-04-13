#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n, m;
int combine[256][256];
int opposed[256][256];
int q[1024];
char buf[1024];

int main() {
  int T, ca = 0; scanf("%d", &T);
  while (T--) {

    scanf("%d", &n);
    memset(combine, -1, sizeof(combine));
    while (n--) {
      scanf("%s", buf);
      int a = buf[0];
      int b = buf[1];
      int c = buf[2];
      combine[a][b] = c;
      combine[b][a] = c;
    }

    scanf("%d", &n);
    memset(opposed, 0, sizeof(opposed));
    while (n--) {
      scanf("%s", buf);
      int a = buf[0];
      int b = buf[1];
      opposed[a][b] = 1;
      opposed[b][a] = 1;
    }

    scanf("%d", &n);
    scanf("%s", buf);
    m = 0;
    for (int i = 0; i < n; i++) {
      int b = buf[i], combined = 0;
      if (m) {
        int a = q[m - 1];
        if (combine[a][b] != -1) {
          q[m - 1] = combine[a][b];
          combined = 1;
        } else {
          q[m++] = b;
        }
      } else {
        q[m++] = b;
      }
      if (!combined && m >= 2)
        for (int j = 0; j < m - 1; j++)
          if (opposed[q[j]][q[m - 1]])
            m = 0;
    }

    printf("Case #%d: [", ++ca);
    for (int i = 0; i < m; i++) {
      if (i) printf(", ");
      printf("%c", q[i]);
    }
    puts("]");
  }

  return 0;
}
