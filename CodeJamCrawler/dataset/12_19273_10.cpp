#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct compare {
	compare(const vector<int>& p, const vector<int>& l): p(p), l(l) {}
	bool operator()(int i, int j) {
		return p[i]*l[j] > p[j]*l[i];
	}

	const vector<int>& p;
	const vector<int>& l;
};

int main() {
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		int n;
		cin >> n;
		vector<int> l(n);
		for (int i = 0; i < n; ++i) {
			cin >> l[i];
		}
		vector<int> p(n);
		for (int i = 0; i < n; ++i) {
			cin >> p[i];
		}
		vector<int> idx(n);
		for (int i = 0; i < n; ++i) {
			idx[i] = i;;
		}
		stable_sort(idx.begin(), idx.end(), compare(p, l));
		cout << "Case #" << test << ":";
		for (int i = 0; i < n; ++i) {
			cout << " " << idx[i];
		}
		cout << endl;
	}
}
