#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int main() {
	int T; cin >> T;
	for (int i=1; i<=T; i++) {
		int C; cin >> C;
		unsigned int val = 0;
		unsigned long long sum = 0;
		int mn = 10000000;
		for (int j=0; j < C; j++) {
			int next; cin >> next;
			val ^= next;
			sum += next;
			mn = min(mn, next);
		}
		
		
		cout << "Case #" << i << ": ";
		if (val == 0) {
			cout << sum - mn;
		} else cout << "NO";
		cout << endl;
	}
	return 0;
}