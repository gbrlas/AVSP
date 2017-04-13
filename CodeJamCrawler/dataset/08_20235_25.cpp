/*
 * Google Code Jam 2008
 * Round 2
 * Problem B
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

template<typename T>
T scan(istream& is = cin) {T v; is >> v; return v;}


struct Solver {
  void run() {
    i64 N, M, A;
    cin >> N >> M >> A;
    i64 x1, y1, x2, y2, x3, y3;
    x1 = 0;
    y2 = 0;
    for (y1 = 0; y1 <= M; y1++)
      for (y3 = 0; y3 <= M; y3++)
	for (x2 = 0; x2 <= N; x2++)
	  for (x3 = 0; x3 <= N; x3++) {
	    i64 cross = (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1);
	    if ((cross == A) || (cross == -A)) {
	      cout << x1 << " "
		   << y1 << " "
		   << x2 << " "
		   << y2 << " "
		   << x3 << " "
		   << y3;
	      return;
	    }
	  }
    cout << "IMPOSSIBLE";
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

