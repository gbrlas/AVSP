/*
 * Google Code Jam 2008
 * Americas Onsite Round - September 29, 2008
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
  // winner[r][c][mask]
  // king is on r, c
  // mask indicates squares visited
  // bit (r*4+c) of mask corresponds to (r, c)
  // = 0 if unknown, 1 if player to move wins, 2 if other
  bool burned[4][4];
  int winner[4][4][65536];
  int R;
  int C;

  int solve(int r, int c, int mask) {
    int& ret = winner[r][c][mask];
    if (ret != 0) return ret;
    assert((mask & (1 << (r*4+c))) == 0);
    int newmask = mask | (1 << r*4+c);
    bool foundWinningMove = false;
    for (int dr = -1; dr <= 1; dr++)
      for (int dc = -1; dc <= 1; dc++) {
	if ((dr == 0) && (dc == 0)) continue;
	if ((r+dr) >= R) continue;
	if ((r+dr) < 0) continue;
	if ((c+dc) >= C) continue;
	if ((c+dc) < 0) continue;
	if (burned[r+dr][c+dc]) continue;
	if ((mask & (1 << ((r+dr)*4+c+dc))) != 0) continue;
	if (solve(r+dr,c+dc,newmask) == 2) foundWinningMove = true;
      }
    ret = foundWinningMove ? 1 : 2;
    return ret;
  }

  void run() {
    memset(burned, 0, sizeof(burned));
    memset(winner, 0, sizeof(winner));
    int r0, c0;
    cin >> R >> C;
    int mask = 0;
    FOR0(r,R) {
      string s = scan<string>();
      FOR0(c,C) {
	char ch = s[c];
	if (ch == '#') burned[r][c] = true;
	if (ch == 'K') { r0 = r; c0 = c; }
      }
    }
    if (solve(r0, c0, 0) == 1) cout << 'A'; else cout << 'B';
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

