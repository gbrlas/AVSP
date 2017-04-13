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

const int maxn = 1010;
int n;
int a[maxn];
pair<int,int> p[maxn];
int c[maxn];

void solve(int testcase) {
  printf("Case #%d: ", testcase);
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i) p[i] = mp(a[i], i);
  sort(p, p + n);
  for (int i = 0; i < n; ++i) c[i] = 1;

  int res = 0;
  for (int i = 0; i < n; ++i) {
    int left = 0;
    for (int j = 0; j < p[i].second; ++j) left += c[j];
    int right = 0;
    for (int j = p[i].second + 1; j < n; ++j) right += c[j];
    res += min(left, right);
    c[p[i].second] = 0;
  }

  printf("%d\n", res);
}

int main() {
  freopen("B-large.in", "r", stdin);
  freopen("out", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; ++i)
    solve(i);
  return 0;
}
