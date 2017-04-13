#include <cstdio>
#include <map>
#define MAXC 1000
using namespace std;
long long solve () {
  long long ats = 0, C, L, t, N, a[MAXC], s = 0, zv, boost, i, j;
  map<long long, long long> atstKiek;
  scanf("%lld %lld %lld %lld", &L, &t, &N, &C);
  for (i = 0; i < C; i++) {
    scanf("%lld", a + i);
    s += a[i];
  }
  zv = t / (s * 2) * C;
  for (i = 0; i < C; i++) {
    atstKiek[a[i]] += N / C + (i < N % C ? 1 : 0) - t / (s * 2);
  }
  for (i = t % (s * 2), j = 0; i >= a[j] * 2; j++) {
    i -= a[j] * 2;
    atstKiek[a[j]]--;
    zv++;
  }
  atstKiek[a[j]]--;
  atstKiek[a[j] - i / 2]++;
  if (zv >= N) {
    ats = N / C * s * 2;
    for (i = 0; i < N % C; i++)
      ats += a[i] * 2;
    return ats;
  }
  ats = t;
  for (map<long long, long long>::reverse_iterator it = atstKiek.rbegin(); it != atstKiek.rend(); it++) {
    boost = min(L, it->second);
    L -= boost;
    ats += boost * it->first + (it->second - boost) * it->first * 2;
  }
  return ats;
}
int main() {
  int T, t;
  scanf("%d", &T);
  for (t = 1; t <= T; t++) {
    printf("Case #%d: %lld\n", t, solve());
  }
}
