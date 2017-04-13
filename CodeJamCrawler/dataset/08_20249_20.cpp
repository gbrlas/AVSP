/*
 * Google Code Jam 2008
 * Round 3
 * Problem D
 *
 * James Rauen
 * jrauen@gmail.com
 * Handle: JRR
 */

using namespace std;
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
typedef long long i64;
typedef pair<int, int> ipair;
#define FOR0(VAR,UB) for (int VAR = 0; VAR <  (UB); VAR++)
#define FOR1(VAR,UB) for (int VAR = 1; VAR <= (UB); VAR++)

template<typename T>
T scan(istream& is = cin) {T v; is >> v; return v;}


struct Solver {
  set<ipair> rockLocns;
  int dp[101][101];
  void run() {
    memset(dp, 0, sizeof(dp));
    i64 H, W, nRocks;
    cin >> H >> W >> nRocks;
    for (int r = 0; r < nRocks; r++)
      rockLocns.insert(make_pair(scan<int>(), scan<int>()));
    FOR1(x, W) FOR1(y, H) {
      if ((x == 1) && (y == 1)) {
	dp[x][y] = 1;
	continue;
      }
      if ((x == 1) || (y == 1)) {
	dp[x][y] = 0;
	continue;
      }
      if (rockLocns.count(make_pair(x,y)) > 0) {
	dp[x][y] = 0;
	continue;
      }
      dp[x][y] = dp[x-1][y-2] + dp[x-2][y-1];
      dp[x][y] %= 10007;
    }
    cout << dp[W][H];
  }
};

int main()
{
  const int nCases = scan<int>();
  for (int tc = 1; tc <= nCases; tc++) {
    cerr << "Case #" << tc << endl;
    cout << "Case #" << tc << ": ";
    auto_ptr<Solver> s(new Solver);
    s->run();
    cout << endl;
  }
  return 0;
}

