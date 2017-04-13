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

const char pattern[] = "welcome to code jam";
const int length = 19;

// TODO: check long long carefully.
int main() {
  int caseN;
  scanf("%d\n", &caseN);
  for (int cas = 1; cas <= caseN; ++cas) {
    printf("Case #%d:", cas);

    char str[510];
    fgets(str, 510, stdin); // TODO: trim \n
    int len = strlen(str) - 1;

    int times[len], cnt = 0;
    F0(i, len) {
      if (str[i] == 'w') cnt++;
      times[i] = cnt;
    }

    F1(p, length - 1) {
      cnt = 0;
      F0(i, len) {
        if (str[i] == pattern[p]) cnt = (cnt + times[i]) % 10000;
        times[i] = cnt;
      }
    }

/*
    F0(i, len) {
      printf("%d ", times[i]);
    }
*/
    printf(" %04d", times[len - 1]);
    printf("\n");
  }

  return 0;
}
