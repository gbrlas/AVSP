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

int main() {
  int L, D, N;
  scanf("%d%d%d", &L, &D, &N);

  char words[D][L + 1];
  F0(i, D) {
    scanf("%s", &words[i]);
  }

  list<int> matches;
  bool ok[D];

  char pattern[450];
  F0(i, N) {
    scanf("%s", &pattern);
    int len = strlen(pattern);

    matches.clear();
    F0(j, D) matches.push_back(j);

    int m = 0, l = 0;
    while (l != L && !matches.empty()) {
      if (pattern[m] == '(') {
        // set all matches flase.
        for (list<int>::iterator p = matches.begin(); p != matches.end(); p++) {
          ok[*p] = false;
        }

        // set matched.
        for (m++; pattern[m] != ')'; m++) {
          for (list<int>::iterator p = matches.begin(); p != matches.end(); p++) {
            if (words[*p][l] == pattern[m]) ok[*p] = true;
          }
        }

        // remove not matched.
        for (list<int>::iterator p = matches.begin(); p != matches.end();) {
          if (!ok[*p]) p = matches.erase(p);
          else p++;
        }
      } else {
        // remove not matched.
        for (list<int>::iterator p = matches.begin(); p != matches.end();) {
          if (words[*p][l] != pattern[m]) p = matches.erase(p);
          else p++;
        }
      }
      m++;
      l++;
    }

    printf("Case #%d: %d\n", i + 1, matches.size());
  }
/*
  // TODO: check long long carefully.
  F1(i, N) {
    printf("Case #%d: %d", i, );
    printf("\n");
  }
*/
  return 0;
}
