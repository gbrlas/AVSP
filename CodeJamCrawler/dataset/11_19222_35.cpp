#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool ok(vector<double>& x, double d, double t) {
	double y = x[0] - t;
	for (size_t j = 1; j < x.size(); ++j) {
		y = max(y + d, x[j] - t);
		if (y > x[j] + t) {
			return false;
		}
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	for (int test = 1; test <= t; ++test) {
		int c;
		double d;
		cin >> c >> d;
		vector<double> x;
		for (int i = 0; i < c; ++i) {
			double p;
			int v;
			cin >> p >> v;
			for (int j = 0; j < v; ++j) {
				x.push_back(p);
			}
		}
		sort(x.begin(), x.end());

		double lo = 0.0;
		double hi = d*x.size();
		if (ok(x, d, lo)) {
			hi = 0.0;
		} else {
			while (hi - lo > 1e-9) {
				double mid = (hi + lo) / 2;
				if (ok(x, d, mid)) {
					hi = mid;
				} else {
					lo = mid;
				}
			}
		}

		cout.precision(15);
		cout << "Case #" << test << ": " << hi << endl;
	}
}
