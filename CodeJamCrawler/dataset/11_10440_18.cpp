#include <cstdio>
#include <algorithm>
#define MAXN 1001
using namespace std;
double solve () {
  int X, S, R, N, i, be, B, E;
  pair<int, int> wbe[MAXN];
  double ats = 0, kt, t;
  scanf("%d%d%d%lf%d", &X, &S, &R, &t, &N);
  wbe[0].first = 0;
  wbe[0].second = X;
  for (i = 1; i <= N; i++) {
    scanf("%d%d%d", &B, &E, &wbe[i].first);
    wbe[i].second = E - B;
    wbe[0].second -= wbe[i].second;
  }
  sort(wbe, wbe + N + 1);
  for (i = 0; i <= N; i++) {
    kt = min((double)wbe[i].second / (wbe[i].first + R), t);
    t -= kt;
    ats += kt + (wbe[i].second - kt * (wbe[i].first + R)) / (wbe[i].first + S);
  }
  return ats;
}
int main() {
  int T, t;
  scanf("%d", &T);
  for (t = 1; t <= T; t++) {
    printf("Case #%d: %.9lf\n", t, solve());
  }
}
