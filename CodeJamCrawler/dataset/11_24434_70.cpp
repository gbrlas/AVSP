/*
 * Candy.cpp
 *
 */

#include <limits>
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

int main(void) {
	int t, n, i;
	for (i = 1, cin >> t; i <= t; ++i) {
		int xsum = 0, sum = 0, xmin = numeric_limits<int>::max();
		for (cin >> n; n; --n) {
			int tmp;
			cin >> tmp;
			xsum = xsum ^ tmp;
			sum += tmp;
			xmin = min(xmin, tmp);
		}
		if (xsum)
			printf("Case #%d: NO\n", i);
		else
			printf("Case #%d: %d\n", i, sum - xmin);
	}
}
