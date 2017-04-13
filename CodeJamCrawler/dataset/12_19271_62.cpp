#include <iostream>
#include <vector>
using namespace std;

vector<int> p;
vector<int> m;

bool rec(int i, int j) {
	for (int k = i + 1; k < j; ++k) {
		if (p[k] > j) {
			return false;
		}
		m[k] = min(m[k], m[i] + (k - i)*(m[j] - m[i])/(j - i) - 1);
	}
	while (j > i + 1) {
		int l = i + 1;
		while (l < j && p[l] != j) {
			++l;
		}
		if (l >= j) {
			return false;
		}
		for (int k = i + 1; k < l; ++k) {
			m[k] = min(m[k], m[l] + static_cast<int>(1.0*(k - l)*(m[j] - m[l])/(j - l)) - 1);
		}
//		cout << l << " " << j << endl;
		if (!rec(l, j)) {
			return false;
		}
		j = l;
	}
	return true;
}

int main() {
	int num_tests;
	cin >> num_tests;
	for (int test = 1; test <= num_tests; ++test) {
		int n;
		cin >> n;
		p.resize(n);
		m.assign(n, 100000000);
		bool ok = true;
		for (int i = 0; i < n - 1; ++i) {
			cin >> p[i];
			--p[i];
			if (p[i] <= i || p[i] >= n) {
				ok = false;
			}
		}
		int j = n - 1;
		while (j > 0 && ok) {
			int i = 0;
			while (i < j && p[i] != j) {
				++i;
			}
			if (i >= j) {
				ok = false;
				break;
			}
			for (int k = 0; k < i; ++k) {
				m[k] = min(m[k], m[i] + (k - i)*(m[j] - m[i])/(j - i) - 1);
			}
//			cout << i << " " << j << endl;
			if (!rec(i, j)) {
				ok = false;
				break;
			}
			j = i;
		}
		cout << "Case #" << test << ":";
		if (ok) {
			for (int i = 0; i < n; ++i) {
				cout << " " << m[i];
			}
		} else {
			cout << " Impossible";
		}
		cout << endl;
	}
}
