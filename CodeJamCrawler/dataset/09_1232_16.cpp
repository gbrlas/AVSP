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
#include <deque>

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

int N;
char tmp[41];

// TODO: check long long carefully.
int main() {
  int caseN;
  scanf("%d", &caseN);
  for (int cas = 1; cas <= caseN; ++cas) {
    printf("Case #%d:", cas);

    scanf("%d", &N);
    int num[N];

    F0(i, N) {
      scanf("%s", tmp);
      num[i] = strrchr(tmp, '1') - tmp;
    }

    int times = 0;
    F0(i, N) {
      if (num[i] > i) { // not valid. find first valid.
        int j = i + 1;
        while (num[j] > i) j++;
        times += (j - i);

        // shift.
        int t = num[j];
        for (; j > i; --j)
          num[j] = num[j - 1];
        num[i] = t;
      }
    }

    printf(" %d\n", times);
  }
  return 0;
}
