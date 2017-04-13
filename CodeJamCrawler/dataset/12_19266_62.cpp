#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct less_idx {
	less_idx(vector<int>& r): r(r) {}
	vector<int>& r;
	
	bool operator()(int lhs, int rhs) const {
		return r[lhs] < r[rhs];
	}
};

int main() {
	int num_tests;
	cin >> num_tests;
	for (int test = 1; test <= num_tests; ++test) {
		int n, w, l;
		cin >> n >> w >> l;
		vector<int> r(n);
		vector<int> idx(n);
		for (int i = 0; i < n; ++i) {
			cin >> r[i];
			idx[i] = i;
		}
		sort(idx.begin(), idx.end(), less_idx(r));
		vector<int> px(1, 0), py(1, 0);
		vector<int> x(n), y(n);
		for (int i = n - 1; i >= 0; --i) {
			int j = idx[i];
//			cout << "next: " << j << " " << r[j] << endl;
			int ll = -r[j];
			int k = 0;
			int top = py[k];
			while (top > 0 && top > l - r[j]) {
				++k;
				if (k >= px.size()) {
					cout << "OOPS 1" << endl;
					return 1;
				}
				top = py[k];
				ll = px[k];
			}
//			cout << "1" << endl;
			int rr = k + 1;
			while (rr < px.size() && ll + 2*r[j] > px[rr]) {
				top = max(top, py[rr]);
				++rr;
				while (top > l - r[j]) {
					++k;
					if (k >= px.size()) {
						cout << "OOPS 2" << endl;
						return 1;
					}
					top = py[k];
					ll = px[k];
					rr = k + 1;
				}
			}
//			cout << "2" << endl;
			if (ll > w - r[j]) {
				cout << "OOPS 3" << endl;
				return 1;
			}
			x[j] = ll + r[j];
			if (top == 0) {
				y[j] = 0;
			} else {
				y[j] = top + r[j];
			}
			px[k] = max(0, ll);
			int prevy = py[k];
			py[k] = y[j] + r[j];
//			int rr = k + 1;
			while (rr < px.size() && px[rr] < x[j] + r[j]) {
				++rr;
			}
			if (rr < px.size()) {
				if (px[rr] == x[j] + r[j]) {
					px.erase(px.begin() + k + 1, px.begin() + rr);
					py.erase(py.begin() + k + 1, py.begin() + rr);
				} else {
					if (rr > k + 1) {
						px[rr - 1] = x[j] + r[j];
						px.erase(px.begin() + k + 1, px.begin() + rr - 1);
						py.erase(py.begin() + k + 1, py.begin() + rr - 1);
					} else {
						px.insert(px.begin() + rr, x[j] + r[j]);
						py.insert(py.begin() + rr, prevy);
					}
				}
			} else {
				px.erase(px.begin() + k + 1, px.end());
				py.erase(py.begin() + k + 1, py.end());
				px.push_back(x[j] + r[j]);
				py.push_back(0);
			}

//			cout << "p" << endl;
//			for (int m = 0; m < px.size(); ++m) {
//				cout << px[m] << " " << py[m] << endl;
//			}
		}

		cout << "Case #" << test << ":";
		for (int i = 0; i < n; ++i) {
			cout << " " << x[i] << " " << y[i];
		}
		cout << endl;
	}
}
