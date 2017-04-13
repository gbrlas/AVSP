#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

double solve() {
  int x, s, r, t, n;
  scanf("%d %d %d %d %d", &x, &s, &r, &t, &n);
  r -= s;
  vector <PII> order(n + 1);
  int b, e, speed;
  order[0].first = s;
  order[0].second = x;
  for (int i = 0; i < n; ++i) {
    scanf("%d %d %d", &b, &e, &speed);
    order[0].second -= e - b;
    order[i + 1].first = speed + s;
    order[i + 1].second = e - b;
  }
  ++n;
  sort(order.begin(), order.end());
  double ans = 0;
  double rem = t;
  for (int i = 0; i < n; ++i) {
    //printf(">> %d %d\n", order[i].first, order[i].second);
    double temp = order[i].second / (double)(order[i].first + r);
    if (temp <= rem) {
      //printf("A %d : %lf\n", i, temp);
      rem -= temp;
      ans += temp;
    } else {
      double dist = order[i].second - (order[i].first + r) * rem;
      //printf("B %d : %lf\n", i, rem + dist / order[i].first);
      ans += rem + dist / order[i].first;
      rem = 0;
    }
  }
  return ans;
}

int main(int argc, char *argv[]) {
  int tc;
  scanf("%d", &tc);
  for (int i = 1; i <= tc; ++i) {
    printf("Case #%d: %.10lf\n", i, solve());
  }
  return 0;
}
