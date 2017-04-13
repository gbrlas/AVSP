#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

#define DB(x) cerr << #x << "=" << x << endl
#define DBV(x) cerr << x
#define DBL cerr << endl
#define sz(c) ((int)(c).size())
#define pb push_back
#define mp make_pair
#define endl '\n'

typedef long long int64;

using namespace std;

const int maxn = 10010;
int a[maxn];

void solve(int testcase) {
  printf("Case #%d: ", testcase);
  int n, x;
  scanf("%d %d", &n, &x);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  sort(a, a + n, greater<int>());
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > 0) {
      ++res;
      for (int j = i + 1; j < n; ++j)
        if (a[j] > 0 && a[i] + a[j] <= x) {
          a[j] = 0;
          break;
        }
      a[i] = 0;
    }
  }
  printf("%d\n", res);
}

int main() {
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("out", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; ++i)
    solve(i);
  return 0;
}
