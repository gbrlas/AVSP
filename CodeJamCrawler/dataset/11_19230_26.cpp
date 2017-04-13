#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int test = 1; test <= t; ++test) {
		int r, c, d;
		cin >> r >> c >> d;
		vector<vector<int> > v(r);
		for (int i = 0; i < r; ++i) {
			v[i].resize(c);
			for (int j = 0; j < c; ++j) {
				char ch;
				cin >> ch;
				v[i][j] = d + (ch - '0');
			}
		}
		int best = -1;
		for (int s = min(r, c); s >= 3; --s) {
			for (int i = 0; i <= r - s; ++i) {
				for (int j = 0; j <= c - s; ++j) {
					int sx = 0, sy = 0, sm = 0;
					for (int k = i; k < i + s; ++k) {
						for (int m = j; m < j + s; ++m) {
							if (k == i && m == j || k == i + s - 1 && m == j ||
									k == i && m == j + s - 1 || k == i + s - 1 && m == j + s - 1) {
								continue;
							}
							sx += v[k][m]*k;
							sy += v[k][m]*m;
							sm += v[k][m];
						}
					}
					if (2*sx == (2*i + s - 1)*sm && 2*sy == (2*j + s - 1)*sm) {
						best = s;
						goto done;
					}
				}
			}
		}
done:
		cout.precision(15);
		cout << "Case #" << test << ": ";
		if (best == -1) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			cout << best << endl;
		}
	}
}
