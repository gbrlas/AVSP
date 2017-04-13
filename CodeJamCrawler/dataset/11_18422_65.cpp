#include <algorithm>
#include <numeric>
#include <sstream>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <iostream>

#define foreach(i, s, w) for(int i = s; i < int(w.size()); ++i)
#define forX(i, m) for(typeof(m.begin()) i = m.begin(); i != m.end(); ++i)

using namespace std;

template <typename T> T gcd(T a, T b) {
	T t;
	while(b != 0)
		t = b, b = a % b, a = t;
	return (a == 0? 1: a < 0? -a: a);
}

int players, low, high;
long long freq[1024];

int Solve() {
	for(long long res = low; res <= high; ++res) {
		bool ok = true;
		for(int j = 0; j < players; ++j) {
			if(res % freq[j] != 0 && freq[j] % res != 0) {
				ok = false;
				break;
			}
		}
		if(ok)
			return res;
	}
	return -1;
}

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		cin >> players >> low >> high;
		for(int i = 0; i < players; ++i)
			cin >> freq[i];
		int res = Solve();
		if(res == -1)
			printf("Case #%d: NO\n", t + 1);
		else
			printf("Case #%d: %d\n", t + 1, res);
	}
	return 0;
}
