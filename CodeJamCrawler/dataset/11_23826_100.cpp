#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
#include <string>
#include <deque>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <cmath>

using namespace std;

int main() {
	int cases;

	cin >> cases;
	for (int caseid = 1; caseid <= cases; ++caseid) {
		int n;
		int sum = 0;
		int xo = 0;
		int min_c = 1000000000;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			int c;
			cin >> c;
			sum += c;
			xo ^= c;
			min_c = min(min_c, c);
		}
		cout << "Case #" << caseid << ": ";
		if (xo)
			cout << "NO\n";
		else
			cout << sum - min_c << endl;
	}
	return 0;
}
