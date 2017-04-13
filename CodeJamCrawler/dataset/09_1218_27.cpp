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

char buf[100];
set<int> happy[11], unhappy[11], path;
int start[11];

bool isHappy(int x, int base) {
  if (happy[base].find(x) != happy[base].end()) return true;
  else return false;
}

bool isUnhappy(int x, int base) {
  if (unhappy[base].find(x) != unhappy[base].end()) return true;
  else return false;
}

int f(int x, int base) {
  int sum = 0;
  while (x) {
    int tmp = x % base;
    sum += (tmp * tmp);
    x /= base;
  }
  return sum;
}

bool test(int x, int base) {
/*
  printf("%d: ", base);
  for (set<int>::iterator p = happy[base].begin(); p != happy[base].end(); ++p)
    printf("%d ", *p);
  printf("\n");
*/
  path.clear();
  while (path.find(x) == path.end()) { // not repeat.
    path.insert(x);
    if (x == 1 || happy[base].find(x) != happy[base].end()){
      for (set<int>::iterator p = path.begin(); p != path.end(); ++p)
        happy[base].insert(*p);
      return true;
    }
    else if (unhappy[base].find(x) != unhappy[base].end()) break;
    x = f(x, base);
  }

  for (set<int>::iterator p = path.begin(); p != path.end(); ++p)
    unhappy[base].insert(*p);
  return false;
}

// TODO: check long long carefully.
int main() {
  int caseN;
  scanf("%d\n", &caseN);

  // initial.
  for (int base = 2; base <= 10; ++base) {
    bool found = false;
    for (int smallest = 2; !found; ++smallest) {
      int x = smallest;
      path.clear();
      while (path.find(x) == path.end()) { // not repeat.
        path.insert(x);
        if (x == 1) {
          start[base] = smallest;
          for (set<int>::iterator p = path.begin(); p != path.end(); ++p)
            happy[base].insert(*p);
          found = true;
          break;
        } else if (unhappy[base].find(x) != unhappy[base].end()) break;
        x = f(x, base);
      }
      if (!found) {
        for (set<int>::iterator p = path.begin(); p != path.end(); ++p)
          unhappy[base].insert(*p);
      }
    }
    /*
    printf("%d: %d\n", base, start[base]);
    for (set<int>::iterator p = happy[base].begin(); p != happy[base].end(); ++p)
      printf("%d ", *p);
    printf("\n");*/
  }

  for (int cas = 1; cas <= caseN; ++cas) {
    printf("Case #%d:", cas);

    fgets(buf, 100, stdin);
    int n = 0;
    int bases[10];

    for (char *p = strtok(buf, " "); p; p = strtok(NULL, " "))
      bases[n++] = atoi(p);

//    for (int i = 0; i < n; ++i)
//      printf("%d ", bases[i]);

    int smallest = 2;
    for (int i = 0; i < n; ++i)
      smallest = max(smallest, start[bases[i]]);

    for (; ; ++smallest) {
      bool ok = true;
      for (int i = 0; i < n; ++i)
        if (!test(smallest, bases[i])) {
          ok = false;
          break;
        }
      if (ok) break;
    }

    printf(" %d\n", smallest);
  }

  return 0;
}
