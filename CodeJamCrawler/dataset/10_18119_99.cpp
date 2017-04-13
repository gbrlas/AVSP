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
	for( int caseid = 1; caseid <= cases; ++caseid ) {
		int n, k;
		cin >> n >> k;
		int res = (k % (1<<n)) == (1<<n)-1;
		cout << "Case #" << caseid << ": " << (res ? "ON" : "OFF") << endl;
	}
	return 0;
}
