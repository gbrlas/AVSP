#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cassert>

using namespace std;

#define debug(...)
//#define debug printf

long long L, P, C;

int main() {
  int caseN;
  cin >> caseN;

  for (int cc = 1; cc <= caseN; ++cc) {
    cout << "Case #" << cc << ": ";

    cin >> L >> P >> C;
    debug("=> %d %d %d\n", L, P, C);

    long long tmpL = L;
    long long tmpP = P;
    int cnt = 0;

    long long mid, mid1, mid2;
    double left1, left2;
    while (tmpP > C * tmpL) {
      mid1 = (long long)floor(sqrt((double)tmpL * tmpP));
      mid2 = (long long)ceil(sqrt((double)tmpL * tmpP));
      left1 = max((double)mid1 / tmpL, (double)tmpP / mid1);
      left2 = max((double)mid2 / tmpL, (double)tmpP / mid2);

      mid = (left1 < left2) ? mid1 : mid2; // test value
      if ((double)mid / tmpL < (double)tmpP / mid) tmpL = mid;
      else tmpP = mid;

      debug("%d ", mid);
      cnt++;
    }
    debug("\n");

    cout << cnt;
    cout << endl;
  }

  return 0;
}

