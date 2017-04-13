/*
 * c.cpp
 *
 */

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <complex>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
 
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)

int rotate(int n, int offset) {
	return n / 10 + (n % 10) * offset;
}

int solve(int a, int b) {
	int ans = 0;
	int digits = 1;
	int offset = 10;
	while (a / offset >= 10) offset *= 10, ++digits;
	for(int n = a; n < b; ++n) {
		int m = n;
		set<int> seen;
		forn(i, digits) {
			m = rotate(m, offset);
			if (n < m && m <= b && not seen.count(m)) {
				++ans;
				seen.insert(m);
			}
		}
	}
	return ans;
}

int main(void) {
	int ncase; cin >> ncase;
	forn(i, ncase) {
		int a, b; cin >> a >> b;
		int ans = solve(a, b);
		printf("Case #%d: %d\n", i + 1, ans);
	}
	return 0;
}
