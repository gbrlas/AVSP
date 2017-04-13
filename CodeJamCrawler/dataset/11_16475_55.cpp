#include <algorithm>
#include <vector>

#include <cmath>
#include <cstdio>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> LP;
typedef vector<LP> VLP;

const LL MIN = -1000000000000000L;
const LL MAX =  1000000000000000L;

int c;
LL d;
VLP data;

bool testDist(LL x) {
  LL low = MIN;
  LL p, v, l, r;
  for (int i = 0; i < c; ++ i) {
    p = data[i].first;
    v = data[i].second;
    l = max(low + d, p - x);
    r = l + (v - 1) * d;
    if (llabs(r - p) > x) {
      return false;
    }
    if (llabs(l - p) > x) {
      return false;
    }
    low = r;
  }
  return true;
}

LL solve() {
  scanf("%d %lld", &c, &d);
  d *= 2;
  data.resize(c);
  for (int i = 0; i < c; ++ i) {
    scanf("%lld %lld", &data[i].first, &data[i].second);
    data[i].first *= 2;
  }
  sort(data.begin(), data.end());
  LL start = 0, end = MAX, mid;
  while (start < end) {
    mid = (start + end) / 2;
    bool test = testDist(mid);
    //printf("%s %lld\n", test ? "true" : "false", mid);
    if (test) {
      end = mid;
    } else {
      start = mid + 1;
    }
  }
  return start;
}

int main(int argc, char *argv[]) {
  int tc;
  scanf("%d", &tc);
  for (int i = 1; i <= tc; ++i) {
    LL ans = solve();
    if (ans % 2) {
      printf("Case #%d: %lld.5\n", i, ans / 2);
    } else {
      printf("Case #%d: %lld.0\n", i, ans / 2);
    }
  }
  return 0;
}
