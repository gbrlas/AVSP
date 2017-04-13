/*
 * a.cpp
 *
 */

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <complex>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)

bool solve(vector<int> &pos, vector<int> &len, int n, int d) {
	vector<int> maxLen(n, 0);
	maxLen[0] = pos[0];
	forn(i, n) {
		if (maxLen[i] + pos[i] >= d)
			return true;
		for (int j = i + 1; j < n; ++j) {
			if (maxLen[i] + pos[i] >= pos[j])
				maxLen[j] = max(maxLen[j], min(len[j], pos[j] - pos[i]));
			else
				break;
		}
	}
	return false;
	/*
	vector<bool> pending(n, false);
	queue<int> file;
	maxLen[0] = pos[0];
	file.push(0);
	pending[0] = true;
	while (not file.empty()) {
		int i = file.front();
		file.pop();
		pending[i] = false;
		for (int j = i + 1; j < n; ++j) {
			if (maxLen[i] + pos[i] >= pos[j]) {
				if (min(len[j], pos[j] - pos[i]) > maxLen[j]) {
					maxLen[j] = min(len[j], pos[j] - pos[i]);
					if (not pending[j]) {
						pending[j] = true;
						file.push(j);
					}
				}
			} else
				break;
		}
	}
	for (int j = 0; j < n; ++j)
		cout << maxLen[j] << endl;
	return maxLen[n - 1] + pos[n - 1] >= d;
	*/
}

int main(void) {
	int ncase;
	cin >> ncase;
	for (int index = 1; index <= ncase; ++index) {
		int n;
		cin >> n;
		vector<int> pos(n);
		vector<int> len(n);
		forn(i, n) {
			cin >> pos[i] >> len[i];
		}
		int d;
		cin >> d;
		bool ans = solve(pos, len, n, d);
		printf("Case #%d: %s\n", index, ans ? "YES" : "NO");
	}
	return 0;
}
