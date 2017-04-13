#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int t, n, s, p, a, q, r, m, canS, canNS;
	cin >> t;
	for(int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		canS = 0;
		canNS = 0;
		cin >> n >> s >> p;
		for(int j = 0; j < n; j++) {
			cin >> a;
			if (a == 0) {
				if (p == 0) canNS++;
				continue;
			}
			if (a == 1) {
				if (p <= 1) canNS++;
				continue;
			}
			q = a/3;
			r = a%3;

			if (q >= p) {
				canNS++;
			} else if (p-q == 1) {
				if (r == 0) canS++;
				if (r >= 1) canNS++;
			} else if (p-q == 2 && r == 2) {
				canS++;
			}
		}
		m = canNS + min(canS,s);
		cout << m << endl;
	}

}
