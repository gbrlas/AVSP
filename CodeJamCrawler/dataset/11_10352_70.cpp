#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int solve () {
  int O = 1, B = 1, time = 0, i, p, freeO = 0, freeB = 0, curTime, N;
  char c;
  scanf("%d\n", &N);
  for (i = 0; i < N; i++) {
    scanf("%c %d\n", &c, &p);
    if (c == 'O') {
      curTime = max(abs(O - p) - freeO, 0) + 1;
      time += curTime;
      freeB += curTime;
      freeO = 0;
      O = p;
    } else {
      curTime = max(abs(B - p) - freeB, 0) + 1;
      time += curTime;
      freeO += curTime;
      freeB = 0;
      B = p;
    }
  }
  return time;
}
int main() {
  int T, t;
  scanf("%d", &T);
  for (t = 1; t <= T; t++) {
    printf("Case #%d: %d\n", t, solve());
  }
}
