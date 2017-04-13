#include <cstdio>
#define MAXN 100
using namespace std;
void solve () {
  int N, i, j, w[MAXN], l[MAXN];
  double WP[MAXN], OWP[MAXN], OOWP[MAXN], RPI[MAXN];
  char table[MAXN][MAXN + 1];
  scanf("%d\n", &N);
  for (i = 0; i < N; i++) {
    scanf("%s", table[i]);
    w[i] = 0;
    l[i] = 0;
    WP[i] = 0;
    OWP[i] = 0;
    OOWP[i] = 0;
    RPI[i] = 0;
  }
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++)
      if (table[i][j] == '1')
        w[i]++;
      else if (table[i][j] == '0')
        l[i]++;
    WP[i] = w[i] / (double)(w[i] + l[i]);
  }
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (table[j][i] == '1')
        OWP[i] += (w[j] - 1) / (double)(w[j] + l[j] - 1);
      else if (table[j][i] == '0')
        OWP[i] += w[j] / (double)(w[j] + l[j] - 1);
    }
    OWP[i] /= w[i] + l[i];
  }
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (table[j][i] == '1' || table[j][i] == '0')
        OOWP[i] += OWP[j];
    }
    OOWP[i] /= w[i] + l[i];
  }
  for (i = 0; i < N; i++) {
    printf("%.7lf\n", 0.25 * WP[i] + 0.5 * OWP[i] + 0.25 * OOWP[i]);
  }
}
int main() {
  int T, t;
  scanf("%d", &T);
  for (t = 1; t <= T; t++) {
    printf("Case #%d:\n", t);
    solve();
  }
}
