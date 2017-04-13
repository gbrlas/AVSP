#include <iostream>
#include <vector>
using namespace std;

#define abs(a) (a<0?-(a):(a))

struct Chicken {
  int x, v, p;
  double t;
  bool operator<(const Chicken & c) const {
    return t<c.t;
  }
};

int main () {

  int C, N, K, B, T;
  scanf("%d", &C);
  for (int c = 1; c <= C; ++c) {
    scanf("%d %d %d %d", &N, &K, &B, &T);
    vector<Chicken> ch(N);
    for (int i = 0; i < N; ++i)
      scanf("%d", &ch[i].x);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &ch[i].v);
      ch[i].t = (B-ch[i].x)*1.0/ch[i].v;
//      printf("%d %d %d %lf\n", i, ch[i].x, ch[i].v, ch[i].t);
    }
    sort(ch.begin(), ch.end());
    int ok = 0;
    for (; ok < N; ++ok) {
//      printf("%d %lf %lf\n", T, ch[ok].t, abs(T-ch[ok].t));
      if (!(T > ch[ok].t || abs(T-ch[ok].t) < 1e-10))
        break;
    }
//    printf("%d\n", ok);
    if (ok < K)
      printf("Case #%d: IMPOSSIBLE\n", c);
    else {
      for (int i = 0; i < ok; ++i) {
        ch[i].p = 0;
        for (int j = ok; j < N; ++j)
          if (ch[j].x > ch[i].x)
            ++ch[i].p;
      }
      int ans = 0;
      for (int i = 0; i < K; ++i) {
        int best = 50;
        int bp = -1;
        for (int j = 0; j < ok; ++j) {
          if (ch[j].p < best) {
            best = ch[j].p;
            bp = j;
          }
        }
        ans += best;
        ch[bp].p = 50;
      }
      printf("Case #%d: %d\n", c, ans);
    }
  }
  return 0;
}
