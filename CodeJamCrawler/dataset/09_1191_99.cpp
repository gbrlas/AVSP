#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cassert>

#include <iostream>
#include <sstream>
#include <iterator>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <list>
#include <complex>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

const double PI = atan(1.0) * 4;
const int inf = 1000000009;
const double eps = 1e-8;

#define F0(i, n) for (int i = 0; i < (n); ++i)
#define F1(i, n) for (int i = 1; i <= (n); ++i)
#define RA(x) (x).begin(), (x).end()
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())

using namespace std;



// disjoint set.
const int MAX = 10010;

int p[MAX];
int rank[MAX];

void makeSet(int x) {
  p[x] = x;
  rank[x] = 0;
}

void link(int x, int y) {
  if (rank[x] > rank[y]) {
    p[y] = x;
  } else {
    p[x] = y;
    if (rank[x] == rank[y]) rank[y]++;
  }
}

int findSet(int x) {
  if (x != p[x])
    p[x] = findSet(p[x]);
  return p[x];
}

void unionSet(int x, int y) {
  link(findSet(x), findSet(y));
}
// disjoint set end.


int caseN;
int H, W;

int f(int h, int w) {
  return (h - 1) * W + w - 1;
}

map<int, char> labels;

void dump() {
  F1(i, H) {
    printf("\n");
    F1(j, W) {
      if (j != 1) printf(" ");
      printf("%c", labels[p[f(i, j)]]);
    }
  }
}


int vh[4] = {-1, 0, 0, 1};
int vw[4] = {0, -1, 1, 0};

// TODO: check long long carefully.
int main() {
  scanf("%d", &caseN);
  for (int cas = 1; cas <= caseN; ++cas) {
    printf("Case #%d:", cas);

    // read in.
    scanf("%d%d", &H, &W);

    // set map.
    int map[H + 2][W + 2]; // gardian.
    F0(i, W + 2) map[0][i] = map[H + 1][i] = MAX;
    F0(i, H + 2) map[i][0] = map[i][W + 1] = MAX;
    F1(i, H) {
      F1(j, W) {
        scanf("%d", &map[i][j]);
        makeSet(f(i, j));
      }
    }
/*
    // show map.
    F0(i, H + 2) {
      F0(j, W + 2) {
        printf("%d ", map[i][j]);
      }
      printf("\n");
    }
*/

    F1(i, H) {
      F1(j, W) {
        // find the lowest.
        int mind = -1;
        int minAlt = map[i][j];
        F0(k, 4) {
          int alt = map[i + vh[k]][j + vw[k]];
          if (alt < minAlt) {
            minAlt = alt;
            mind = k;
          }
        }
        // union.
        if (mind != -1) {
          unionSet(f(i, j), f(i + vh[mind], j + vw[mind]));
        }
      }
    }

    // label.
    char ch = 'a';
    labels.clear();
    F1(i, H) {
      F1(j, W) {
        if (labels.find(p[f(i, j)]) == labels.end()) { // new label.
          labels[p[f(i, j)]] = ch;
          ch++;
        }
      }
    }

    dump();
    printf("\n");
  }

  return 0;
}
