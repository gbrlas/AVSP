#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <numeric>
#include <cstdio>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;


int main() {
	freopen("E:\\Ëã·¨\\GCJ\\09qual\\A-small.in", "r", stdin);
	freopen("E:\\Ëã·¨\\GCJ\\09qual\\A-small.out", "w", stdout);
	int l, d, n;
	string temp;
	vector<string> dict;
	//scanf("%d%d%d", &l, &d &n);
	cin >> l >> d >> n;
	vector<string> data(l, "");

	for (int i = 1; i <= d; ++i) {
		cin >> temp;
		dict.push_back(temp);
	}

	for (int cnt = 1; cnt <= n; ++cnt) {
		cin >> temp;
		for (int i = 0; i < l; ++i) data[i] = "";
		for (int i = 0, j = 0; i < l; ++i, ++j) {
			if (temp[j] == '(') {
				for (++j; temp[j] != ')'; ++j) data[i] += temp[j];
			}
			else data[i] += temp[j];
		}

		int res = 0;
		for (int i = 0, j, k; i < d; ++i) {
			for (j = 0; j < l; ++j) {
				for (k = 0; k < data[j].length() && data[j][k] != dict[i][j]; ++k) {};
				if (k >= data[j].length()) break;
			}
			if (j >= l) ++res;
		}

		printf ("Case #%d: %d\n",cnt, res);
	}

	return 0;
}
