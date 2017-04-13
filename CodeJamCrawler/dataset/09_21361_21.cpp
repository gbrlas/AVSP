#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef long long ll;

#define sz(c) ((int) (c).size())
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define tr(c, i) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sqr(x) ((x) * (x))

double dist(int x1, int y1, int x2, int y2)
{
   return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}

#define MAXN 45

int N;
int x[MAXN], y[MAXN], r[MAXN];

int main()
{
   int T;
   scanf("%d\n", &T);
   for (int tt = 0; tt < T; tt++)
   {
      scanf("%d", &N);
      for (int i = 0; i < N; i++)
         scanf("%d%d%d", &x[i], &y[i], &r[i]);
      double res = 0;
      if (N == 1)
         res = r[0];
      else if (N == 2)
      {
         res = max(r[0], r[1]);
      }
      else
      {
         res = max(1.0 * r[0], (r[1] + r[2] + dist(x[1], y[1], x[2], y[2])) * 0.5);
         res = min(res, max(1.0 * r[1], (r[0] + r[2] + dist(x[0], y[0], x[2], y[2])) * 0.5));
         res = min(res, max(1.0 * r[2], (r[0] + r[1] + dist(x[0], y[0], x[1], y[1])) * 0.5));         
      }
      printf("Case #%d: %lf\n", tt + 1, res);
   }
   return 0;
}
