#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
#include <string>
#include <deque>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <cmath>

using namespace std;

typedef long long LL;
string m[505];

int main() {
	int cases;
	cin >> cases;
	for (int caseid = 1; caseid <= cases; ++caseid) {
		cout << "Case #" << caseid << ": ";
		int rows, cols, D;
		cin >> rows >> cols >> D;
		for (int r = 0; r < rows; ++r)
			cin >> m[r];
		int len = min(rows, cols);
		// odd
		int best_l = 0;
		for (int l = (len & 1) ? len : len - 1; l >= 3; l -= 2) {
			for (int r = l / 2; r < rows - l / 2; ++r) {
				for (int c = l / 2; c < cols - l / 2; ++c) {
					LL mass[2] = { 0, 0 };
					for (int dr = -l / 2; dr <= l / 2; ++dr) {
						for (int dc = -l / 2; dc <= l / 2; ++dc) {
							if (abs(dr) == l / 2 && abs(dc) == l / 2)
								continue;
							mass[0] += dr * (m[r + dr][c + dc] - '0'+D);
							mass[1] += dc * (m[r + dr][c + dc] - '0'+D);
						}
					}
					if (mass[0] == 0 && mass[1] == 0) {
						best_l = l;
						//cerr << caseid << " odd:" << l << ' ' << r << ' ' << c << endl;
						goto even;
					}
				}
			}
		}
		// even
		even: ;
		for (int l = (len & 1) ? len - 1 : len; l >= 4 && l > best_l; l -= 2) {
			for (int r = 0; r + l <= rows; ++r) {
				for (int c = 0; c + l <= cols; ++c) {
					LL mass[2] = { 0, 0 };
					for (int dr = 0; dr < l; ++dr) {
						for (int dc = 0; dc < l; ++dc) {
							// r+dr,c+dc
							if (dr == 0 && (dc == 0 || dc == l - 1))
								continue;
							if (dr == l-1  && (dc == 0 || dc == l - 1))
								continue;
							mass[0] += (2 * dr - (l - 1)) * (m[r + dr][c + dc]
									- '0'+D);
							mass[1] += (2 * dc - (l - 1)) * (m[r + dr][c + dc]
									- '0'+D);
						}
					}
					if (mass[0] == 0 && mass[1] == 0) {
						best_l = l;
						//cerr << caseid << " even:" << rows << ' ' << cols << ' ' << l << ' ' << r << ' ' << c << endl;
						goto finished;
					}
				}
			}
		}
		finished: if (best_l >= 3)
			cout << best_l << endl;
		else
			cout << "IMPOSSIBLE\n";
	}
	return 0;
}
