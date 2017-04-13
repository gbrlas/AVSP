#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; ++tc) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> s(n, vector<int>(m));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin >> s[i][j];
		bool f = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int x = 2;
				for (int k = 0; k < m; ++k)
					if (s[i][j] < s[i][k]) {
						--x;
						break;
					}
				for (int k = 0; k < n; ++k)
					if (s[i][j] < s[k][j]) {
						--x;
						break;
					}
				if (x == 0) {
					f = false;
					break;
				}
			}
			if (!f)
				break;
		}
		cout << "Case #" << tc << ": ";
		if (f)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}