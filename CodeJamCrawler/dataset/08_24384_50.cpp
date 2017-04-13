#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


bool solve(int P) {
	int p, k, l; cin >> p >> k >> l;
	vector<int> v;
	for (int i = 0; i < l; ++i) {
		int f; cin >> f; v.push_back(f);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	int presses = 0;
	for (int i = 0; i < l; ++i) {
		presses += ((i / k) + 1) * v[i];
	}
	cout << "Case #" << P + 1 << ": " << presses << endl;
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
		solve(i);
	return 0;
}
