#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		int n, x;
		cin >> n >> x;
		vector<int> s(n);
		for (int i = 0; i < n; ++i) {
			cin >> s[i];
		}
		multiset<int> ss(s.begin(), s.end());
		int count = 0;
		while (!ss.empty()) {
			++count;
			int a = *ss.begin();
			ss.erase(ss.begin());
			if (ss.empty()) {
				break;
			}
			multiset<int>::iterator it = ss.upper_bound(x - a);
			if (it == ss.begin()) {
				continue;
			}
			ss.erase(--it);
		}
		cout << "Case #" << test << ": " << count << endl;
	}
}
