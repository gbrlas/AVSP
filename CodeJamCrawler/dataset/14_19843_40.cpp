#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		int count = 0;
		int start = 0, end = n - 1;
		for (int i = 1; i <= n - 2; ++i) {
			int pos = -1;
			for (int j = start; j <= end; ++j) {
				if (pos == -1 || a[j] < a[pos]) {
					pos = j;
				}
			}
			if (pos - start < end - pos) {
				count += pos - start;
				for (int j = pos; j > start; --j) {
					a[j] = a[j - 1];
				}
				++start;
			} else {
				count += end - pos;
				for (int j = pos; j < end; ++j) {
					a[j] = a[j + 1];
				}
				--end;
			}
		}
		cout << "Case #" << test << ": " << count << endl;
	}
}
