#include <iostream>
#include <vector>
using namespace std;

int main() {
	int num_tests;
	cin >> num_tests;
	for (int test = 1; test <= num_tests; ++test) {
		int n;
		cin >> n;
		vector<int> d(n), l(n);
		for (int i = 0; i < n; ++i) {
			cin >> d[i] >> l[i];
		}
		int dd;
		cin >> dd;
		vector<int> x(n, 0);
		x[0] = d[0];
		bool ok = false;
		for (int i = 0; i < n; ++i) {
			if (d[i] + x[i] >= dd) {
				ok = true;
				break;
			}
			for (int j = i + 1; j < n; ++j) {
				if (d[j] > d[i] + x[i]) {
					break;
				}
				int xx = min(l[j], d[j] - d[i]);
				if (x[j] < xx) {
					x[j] = xx;
				}
			}
		}
		cout << "Case #" << test << ": " << (ok ? "YES" : "NO") << endl;
	}
}
