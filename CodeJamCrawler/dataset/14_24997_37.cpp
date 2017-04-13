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

#define PROBLEM "A"
#define PATH "/home/arman/Downloads"

void init(int argc, char **argv) {
  if (argc == 1 || (argc == 2 && std::string(argv[1]) == "in")) {
    fprintf(stderr, "SAMPLE:\n\n");
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  } else if (argc > 1 && std::string(argv[1]) == "small") {
    assert(argc == 3);
    std::string filename = std::string(PROBLEM) + std::string("-small-attempt") + std::string(argv[2]);
    fprintf(stderr, "%s:\n\n", filename.data());
    std::string fullpath = std::string(PATH) + std::string("/") + filename;
    freopen((fullpath + std::string(".in")).data(), "r", stdin);
    freopen((fullpath + std::string(".out")).data(), "w", stdout);
  } else if (argc == 2 && std::string(argv[1]) == "large") {
    std::string filename = std::string(PROBLEM) + std::string("-large");
    fprintf(stderr, "%s:\n\n", filename.data());
    std::string fullpath = std::string(PATH) + std::string("/") + filename;
    freopen((fullpath + std::string(".in")).data(), "r", stdin);
    freopen((fullpath + std::string(".out")).data(), "w", stdout);
  }
}

#define DB(x) cerr << #x << "=" << x << endl
#define DBV(x) cerr << x << " "
#define DBL cerr << endl
#define sz(c) ((int)(c).size())
#define pb push_back
#define mp make_pair
#define endl '\n'

typedef long long int64;

using namespace std;

const int maxn = 1e6 + 10;

int n;
int a[maxn];
int64 psum[maxn];

int64 sum(int l, int r) {
  if (l > r) return 0;
  int64 res = psum[r];
  if (l > 0) res -= psum[l - 1];
  return res;
}

int64 arnarScore(int a, int b) {
  int64 sl = sum(0, a - 1);
  int64 sm = sum(a, b);
  int64 sr = sum(b + 1, n - 1);
  int64 total = sl + sm + sr;
  return total - max(sl, max(sm, sr));
}

void solve(int testcase) {
  DB(testcase);
  printf("Case #%d: ", testcase);

  int p, q, r, s;
  scanf("%d %d %d %d %d", &n, &p, &q, &r, &s);
  for (int i = 0; i < n; ++i) {
    a[i] = (int64(i) * p + q) % r + s;
  }

  psum[0] = a[0];
  for (int i = 1; i < n; ++i)
    psum[i] = psum[i - 1] + a[i];

  int64 score = 0;
  for (int a = 0; a < n; ++a) {
    int l = a, r = n - 1;
    while (l < r) {
      int m = (l + r) / 2;
      if (sum(a, m) < sum(m + 1, n - 1))
        l = m + 1;
      else
        r = m;
    }

    for (int d = -2; d <= 2; ++d) {
      int b = l + d;
      if (a <= b && b < n) {
        score = max(score, arnarScore(a, b));
      }
    }
  }

  double res = double(score) / psum[n - 1];
  printf("%.10lf\n", res);
}

int main(int argc, char **argv) {
  init(argc, argv);
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t)
    solve(t);
  return 0;
}
