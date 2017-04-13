/*
 * Google Code Jam 2008
 * Round 3
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
typedef pair<int, int> ipair;
#define FOR0(VAR,UB) for (int VAR = 0; VAR <  (UB); VAR++)
#define FOR1(VAR,UB) for (int VAR = 1; VAR <= (UB); VAR++)

template<typename T>
T scan(istream& is = cin) {T v; is >> v; return v;}

#define START_OFFSET 150

struct Solver {

  // verticalOnPath[x][y] == true if the segment (x,y) to (x,y+1) is on the path
  bool verticalOnPath[6020][6020];
  bool inInterior[6020][6020];
  bool isLRPocket[6020][6020];
  bool isUDPocket[6020][6020];

  set<ipair> verticalSegments;
  void run() {
    memset(verticalOnPath, 0, sizeof(verticalOnPath));
    memset(inInterior, 0, sizeof(inInterior));
    memset(isLRPocket, 0, sizeof(isLRPocket));
    memset(isUDPocket, 0, sizeof(isUDPocket));
    int nEntries = scan<int>();
    int x = START_OFFSET;
    int y = START_OFFSET;
    int dx = 0;
    int dy = 1;
    FOR0(i, nEntries) {
      string action;
      int nReps;
      cin >> action >> nReps;
      FOR0(rep, nReps) FOR0(index, action.size()) {
	switch (action[index]) {
	case 'L' : { swap(dx, dy); dx = -dx; break; }
	case 'R' : { swap(dx, dy); dy = -dy; break; }
	case 'F' : { 
	  if (dx == 0) { verticalOnPath[x][(dy == -1)?(y-1):y] = true; }
	  x += dx; 
	  y += dy; 
	  break; }
	default : { assert(false); }
	}
      }
    } // nEntries
    FOR0(y,START_OFFSET*2) {
      bool inside = false;
      FOR0(x, START_OFFSET*2) {
	if (verticalOnPath[x][y])
	  inside = ! inside;
	inInterior[x][y] = inside;
      }
    }
    /*
    for (int y = START_OFFSET+20; y >= START_OFFSET-20; y--) {
      for (int x = START_OFFSET-20; x <= START_OFFSET+20; x++) 
	if (inInterior[x][y]) cerr << '*'; else cerr << '.';
      cerr << endl;
    }
    */
    FOR0(y, START_OFFSET*2) {
      int xlo = -1;
      int xhi = -1;
      FOR0(x, START_OFFSET*2)
	if (inInterior[x][y]) {
	  xlo = x;
	  break;
	}
      for(int x = START_OFFSET*2-1; x >= 0; x--)
	if (inInterior[x][y]) {
	  xhi = x;
	  break;
	}
      if (xlo == -1) continue;
      for(int x = xlo; x <= xhi; x++)
	if (!inInterior[x][y]) {
	  isLRPocket[x][y] = true;
	  // cerr << "LR Pocket: " << x << " " << y << endl;
	}
    }
    FOR0(x, START_OFFSET*2) {
      int ylo = -1;
      int yhi = -1;
      FOR0(y, START_OFFSET*2)
	if (inInterior[x][y]) {
	  ylo = y;
	  break;
	}
      for (int y = START_OFFSET*2-1; y >= 0; y--)
	if (inInterior[x][y]) {
	  yhi = y;
	  break;
	}
      if (ylo == -1) continue;
      for (int y = ylo; y <= yhi; y++)
	if (!inInterior[x][y]) {
	  isUDPocket[x][y] = true;
	  //	  cerr << "UD Pocket: " << x << " " << y << endl;
	}
    }
    int ret = 0;
    FOR0(x, START_OFFSET*2) FOR0(y, START_OFFSET*2)
      if (isUDPocket[x][y] || isLRPocket[x][y])
	ret++;
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

