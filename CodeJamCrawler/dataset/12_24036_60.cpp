/*
 * b.cpp
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

int bestFromTotal(int x) {
	if (x % 3 == 0)
		return x / 3;
	else
		return x / 3 + 1;
}

int bestIfSurprise(int x) {
	if (x % 3 == 2)
		return x / 3 + 2;
	else if (x >= 3)
		return x / 3 + 1;
	else
		return x;
}

int solve(vector<int> &t, int s, int p) {
	int ans = 0;
	forn(i, t.size()) {
		if (bestFromTotal(t[i]) >= p)
			ans++;
		else if (s > 0 && bestIfSurprise(t[i]) >= p) {
			s--;
			ans++;
		}
	}
	return ans;
}

int main(void) {
	int ncase;
	cin >> ncase;
	forn(i, ncase) {
		int n, s, p;
		cin >> n >> s >> p;
		vector<int> t(n);
		forn(j, n)
			cin >> t[j];
		int ans = solve(t, s, p);
		printf("Case #%d: %d\n", i + 1, ans);
	}
	return 0;
}
