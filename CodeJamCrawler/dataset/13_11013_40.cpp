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

bool isPal(int x) {
  vector<int> asc;
  while (x > 0) {
    asc.push_back(x % 10);
    x /= 10;
  }
  vector<int> desc(asc.rbegin(), asc.rend());
  return asc == desc;
}

int solve(int a, int b) {
  int res = 0;
  for (int i = 1; i*i <= b; i++) {
    if (i*i >= a && isPal(i*i) && isPal(i)) {
      res += (isPal(i*i)) ? 1 : 0;
    }
  }
  return res;
}

int main() {
  int t;
  scanf("%d", &t);
  FOR(tid, 1, t) {
    int a;
    int b;
    scanf("%d %d", &a, &b);
    printf("Case #%d: %d\n", tid, solve(a,b));
  }
}
