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

#define PROBLEM "B"
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

const int maxn = 110;
const int maxhp = 210;

void solve(int testcase) {
  DB(testcase);
  printf("Case #%d: ", testcase);
  int p, q, n;
  scanf("%d %d %d", &p, &q, &n);
  vector<int> h(n + 1);
  vector<int> g(n + 1);
  for (int i = 0; i < n; ++i) scanf("%d %d", &h[i], &g[i]);
  vector<vector<map<vector<int>,int>>> dp(n + 1);
  for (int i = 0; i <= n; ++i) {
    dp[i] = vector<map<vector<int>,int>>(maxhp);
  }
  vector<int> zero = {0, 0, 0};
  dp[0][h[0]][zero] = 0;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int hp = h[i]; hp > 0; --hp) {
      for (const auto &kv : dp[i][hp]) {
        int x = kv.first[0];
        int s = kv.first[1];
        int t = kv.first[2];
        int d = kv.second;
        //DB(i); DB(hp); DB(s); DB(t); DB(d); DBL;

        if (x == 0) {
          {
            int nexti = i;
            int nexthp = hp - p;
            int nextx = 1;
            int nexts = s;
            int nextt = t;
            int score = d;
            if (nexthp <= 0) {
              score += g[i];
              nexti = i + 1;
              nexthp = h[nexti];
              nexts += nextt;
              nextt = 0;
            }

            if (nexti < n) {
              vector<int> nextall = { nextx, nexts, nextt };
              int &tmp = dp[nexti][nexthp][nextall];
              tmp = max(tmp, score);
            } else {
              res = max(res, score);
            }
          }

          {
            int nexti = i;
            int nexthp = hp;
            int nextx = 1;
            int nexts = s;
            int nextt = t + 1;
            int score = d;

            vector<int> nextall = { nextx, nexts, nextt };
            int &tmp = dp[nexti][nexthp][nextall];
            tmp = max(tmp, score);
          }


        } else {
          {
            int nexti = i;
            int nexthp = hp - q;
            int nextx = 0;
            int nexts = s;
            int nextt = t;
            int score = d;
            if (nexthp <= 0) {
              nexti = i + 1;
              nexthp = h[nexti];
              nexts += nextt;
              nextt = 0;
            }

            if (nexti < n) {
              vector<int> nextall = { nextx, nexts, nextt };
              int &tmp = dp[nexti][nexthp][nextall];
              tmp = max(tmp, score);
            } else {
              res = max(res, score);
            }
          }
        }

        if (s > 0) {
          int nexti = i;
          int nexthp = hp - p;
          int nextx = x;
          int nexts = s - 1;
          int nextt = t;
          int score = d;
          if (hp <= p) score += g[i];
          if (nexthp <= 0) {
            nexti = i + 1;
            nexthp = h[nexti];
            nexts += nextt;
            nextt = 0;
          }

          if (nexti < n) {
            vector<int> nextall = { nextx, nexts, nextt };
            int &tmp = dp[nexti][nexthp][nextall];
            tmp = max(tmp, score);
          } else {
            res = max(res, score);
          }
        }
      }
    }
  }

  printf("%d\n", res);
}

int main(int argc, char **argv) {
  init(argc, argv);
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t)
    solve(t);
  return 0;
}
