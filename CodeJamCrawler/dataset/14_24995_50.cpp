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

const int maxm = 1010;
const int maxn = 101;

int n, m;
string s[maxm];
int res;
int rescnt;
map<string, int> pre[maxn];
int cntin[maxn];

int cntr = 0;

void go(int i) {
  if (i == m) {
    for (int j = 0; j < n; ++j)
      if (cntin[j] == 0) return;
    int numnodes = 0;
    for (int j = 0; j < n; ++j)
      numnodes += sz(pre[j]) + 1;

    //++cntr;
    //DBV(cntr); DBL; for (int j = 0; j < n; ++j) { DBV(j); DBV(": "); for (auto x : pre[j]) { DBV(x.first); DBV(" "); } DBL; } DBL;

    if (res < numnodes) {
      res = numnodes;
      rescnt = 0;
    }
    if (res == numnodes) {
      rescnt += 1;
    }
    return;
  }
  //DB(s[i]);
  for (int j = 0; j < n; ++j) {
    cntin[j] += 1;
    string p;
    for (char c : s[i]) {
      p += c;
      //DB(p);
      pre[j][p] += 1;
    }
    go(i + 1);
    p.clear();
    for (char c : s[i]) {
      p += c;
      pre[j][p] -= 1;
      if (pre[j][p] == 0) {
        pre[j].erase(p);
      }
    }
    cntin[j] -= 1;
  }
}

void solve(int testcase) {
  printf("Case #%d: ", testcase);
  scanf("%d %d", &m, &n);
  for (int i = 0; i < m; ++i) {
    char t[110];
    scanf("%s", t);
    s[i] = t;
  }
  res = 0;
  rescnt = 0;
  memset(cntin, 0, sizeof(cntin));
  for (int i = 0; i < n; ++i) assert(sz(pre[i]) == 0);
  go(0);
  printf("%d %d\n", res, rescnt);
}

int main() {
  freopen("D-small-attempt0.in", "r", stdin);
  freopen("out", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; ++i)
    solve(i);
  return 0;
}
