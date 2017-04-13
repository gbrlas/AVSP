#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;

#define add push_back
#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define tr(c, it) \
for (typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)

int main() {
#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif // LOCAL

	int T, cs = 1;
	cin >> T;
	while(T--) {
		double c, f, x;
		cin >> c >> f >> x;
		double min = x/2.0, loc = x/2.0;
		for(int i=1; ; i++) {
			double tans = 0;
			for(int j=0; j<i; j++) tans += c/(2.0+f*j);
			tans += x/(2.0+f*i);
			if(loc < tans || loc-tans < 1e-8) break;
			loc = tans;
			if(tans < min) min = tans;
		}
		printf("Case #%d: %.7f\n", cs++, min);
	}

	return 0;
}
