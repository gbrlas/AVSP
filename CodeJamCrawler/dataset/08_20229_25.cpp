/*
 * Google Code Jam 2008
 * Round 2
 * Problem A
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


#define INF 9999999

int min(int x, int y) {
  if (x < y) return x; else return y;
}

struct Solver {
  bool isAnd[10001];
  bool changeable[10001];
  int minChangesForZero[10001];
  int minChangesForOne[10001];
  void run() {
    int nNodes, targetValue;
    cin >> nNodes >> targetValue;
    for (int i = 1; i <= (nNodes-1)/2; i++) {
      int G, C;
      cin >> G >> C;
      isAnd[i] = (G == 1);
      changeable[i] = (C == 1);
    }
    for (int i = (nNodes-1)/2 + 1; i <= nNodes; i++) {
      int I;
      cin >> I;
      minChangesForZero[i] = (I == 0) ? 0 : INF;
      minChangesForOne[i] = (I == 1) ? 0 : INF;
    }
    for (int i = (nNodes-1)/2; i >= 0; i--) {
      int ANDZero = min(minChangesForZero[i*2], minChangesForZero[i*2+1]);
      int ANDOne = minChangesForOne[i*2] + minChangesForOne[i*2+1];
      int ORZero = minChangesForZero[i*2] + minChangesForZero[i*2+1];
      int OROne = min(minChangesForOne[i*2], minChangesForOne[i*2+1]);
      if ((!changeable[i]) && isAnd[i]) {
	minChangesForZero[i] = ANDZero;
	minChangesForOne[i] = ANDOne;
      }
      else if ((!changeable[i]) && (!isAnd[i])) {
	minChangesForZero[i] = ORZero;
	minChangesForOne[i] = OROne;
      }
      else if (changeable[i] && isAnd[i]) {
	minChangesForZero[i] = min(ANDZero, 1 + ORZero);
	minChangesForOne[i] = min(ANDOne, 1 + OROne);
      }
      else if (changeable[i] && (!isAnd[i])) {
	minChangesForZero[i] = min(ORZero, 1 + ANDZero);
	minChangesForOne[i] = min(OROne, 1 + ANDOne);
      }
      else {
	assert (false);
      };
      minChangesForZero[i] = min(INF, minChangesForZero[i]);
      minChangesForOne[i] = min(INF, minChangesForOne[i]);
    }
    int ret = (targetValue == 0) ? minChangesForZero[1]
      : minChangesForOne[1];
    if (ret == INF)
      printf("IMPOSSIBLE");
    else
      printf("%d", ret);
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

