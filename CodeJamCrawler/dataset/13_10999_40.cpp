/* Author: Adrian Zgorzałek
 *
 */

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

#define ASSERT_ for (;;) {}

typedef long long ll;
typedef long double ld;
typedef std::pair<int,int> PII;

#define FOR(k,a,b) for(typeof(a) k=(a); k <= (b); ++k)
#define FORREV(k,a,b) for(typeof(b) k=(b); (a) <= (--k);)
#define REP(k,a) for(int k=0; k < (a); ++k)

#define INFTY 2000000000

using namespace std;

int main() {
  int n;
  cin >> n;
  FOR(ca,1,n) {
    char grid[4][4];
    int empty = 0;
    FOR(i, 0, 3) {
      FOR(j, 0, 3) {
        cin >> grid[i][j];
        if (grid[i][j] == '.') empty++;
      }
    }
    int winner = -1;
    // poziom
    FOR(i, 0, 3) {
      int os = 0;
      int xs = 0;
      int ts = 0;
      FOR(j, 0, 3) {
        switch (grid[i][j]) {
          case 'O':
            os++;
            break;
          case 'X':
            xs++;
            break;
          case 'T':
            ts++;
            break;
        }
        if (xs + ts == 4) winner = 1;
        if (os + ts == 4) winner = 0;
      }
    }
    // pion
    FOR(j, 0, 3) {
      int os = 0;
      int xs = 0;
      int ts = 0;
      FOR(i, 0, 3) {
        switch (grid[i][j]) {
          case 'O':
            os++;
            break;
          case 'X':
            xs++;
            break;
          case 'T':
            ts++;
            break;
        }
        if (xs + ts == 4) winner = 1;
        if (os + ts == 4) winner = 0;
      }
    }
    // skos
    {
      int os = 0;
      int xs = 0;
      int ts = 0;
      FOR(i, 0, 3) {
        switch (grid[i][i]) {
          case 'O':
            os++;
            break;
          case 'X':
            xs++;
            break;
          case 'T':
            ts++;
            break;
        }
        if (xs + ts == 4) winner = 1;
        if (os + ts == 4) winner = 0;
      }
    }
    
    {
      int os = 0;
      int xs = 0;
      int ts = 0;
      FOR(i, 0, 3) {
        switch (grid[3-i][i]) {
          case 'O':
            os++;
            break;
          case 'X':
            xs++;
            break;
          case 'T':
            ts++;
            break;
        }
        if (xs + ts == 4) winner = 1;
        if (os + ts == 4) winner = 0;
      }
    }
    if (winner == 1) printf("Case #%d: X won\n", ca);
    else if (winner == 0) printf("Case #%d: O won\n", ca);
    else if (winner == -1 && empty == 0) printf("Case #%d: Draw\n", ca);
    else printf("Case #%d: Game has not completed\n", ca);
  }
}
