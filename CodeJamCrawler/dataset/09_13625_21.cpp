#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

double calc (vector<int> & x, vector<int> & y, vector<int> & r, int a, int b, int c) {

  double dist = sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
  return max((dist+r[a]+r[b])/2, r[c]*1.0);
}

int main () {

  int c, n;
  scanf("%d", &c);
  for (int cc = 1; cc <= c; ++cc) {
    scanf("%d", &n);
    vector<int> x(n);
    vector<int> y(n);
    vector<int> r(n);
    for (int i = 0; i < n; ++i)
      scanf("%d %d %d", &x[i], &y[i], &r[i]);
    double best = 10000;
    if (n < 3)
      for (int i = 0; i < n; ++i)
	best = min(best, r[i]*1.0);
    else {
      best = min(best, calc(x, y, r, 0, 1, 2));
      best = min(best, calc(x, y, r, 0, 2, 1));
      best = min(best, calc(x, y, r, 1, 2, 0));
    }
    printf("Case #%d: %lf\n", cc, best);
  }
}
