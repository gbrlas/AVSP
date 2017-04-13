/*
 * Google Code Jam 2008
 * Round 3
 * Problem C
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
#define FOR0(VAR,UB) for (int VAR = 0; VAR <  (UB); VAR++)
#define FOR1(VAR,UB) for (int VAR = 1; VAR <= (UB); VAR++)

template<typename T>
T scan(istream& is = cin) {T v; is >> v; return v;}

int popul(int arg) {
  int ret = 0;
  for (; arg > 0; arg >>= 1)
    ret += (arg & 1);
  return ret;
}

struct Solver {
  // dp[r][b] =
  // Maximum number of ways to seat students in the first  r  rows
  // where row  r  is arranged in the bit pattern  b
  int dp[11][(1<<10)];

  // brokens[r] =
  // Bitmap of broken chairs in row  r
  int brokens[11];
  
  int nRows;
  int nCols;
  
  void run() {
    cin >> nRows >> nCols;
    brokens[0] = 0;
    FOR1(row, nRows) {
      string pattern = scan<string>();
      brokens[row] = 0;
      FOR0(col, nCols) {
	brokens[row] <<= 1;
	if (pattern[col] == 'x')
	  brokens[row] += 1;
      }
      // cerr << "Row " << row << " brokens " << brokens[row] << endl;
    }
    memset(dp, 0, sizeof(dp));
    FOR1(row, nRows) FOR0(pattern, (1<<nCols)) {
      if ((pattern & brokens[row]) != 0) continue;
      if ((pattern & (pattern << 1)) != 0) continue;
      FOR0 (frontPattern, (1<<nCols)) {
	if ((pattern & (frontPattern << 1)) != 0) continue;
	if (((pattern << 1) & frontPattern) != 0) continue;
	int thisCount = dp[row-1][frontPattern] + popul(pattern);
	if (thisCount > dp[row][pattern])
	  dp[row][pattern] = thisCount;
      }
    }
    int ret = 0;
    FOR0(pattern, (1<<nCols))
      if (dp[nRows][pattern] > ret)
	ret = dp[nRows][pattern];
    cout << ret;
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

