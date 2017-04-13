#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int test = 1; test <= t; ++test) {
		int n;
		cin >> n;
		int x = 0, min = 0, sum = 0;
		for (int i = 0; i < n; ++i) {
			int ci;
			cin >> ci;
			x ^= ci;
			sum += ci;
			if (min == 0 || min > ci) {
				min = ci;
			}
		}
		cout << "Case #" << test << ": ";
		if (x != 0) {
			cout << "NO";
		} else {
			cout << sum - min;
		}
		cout << endl;
	}
}
