#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;

void solve() {
	int n;
	int ans = 0;
	cin >> n;
	vector<string> data(n);
	vector<int> s(n);
	for (int i=0; i<n; i++) {
		string tmp;
		cin >> tmp;
		data[i] = "";
		int j = 0;
		for (int m=0; m<tmp.size(); m++) {
			if (i==0) {
				data[i] += tmp[m];
				j = 0;
			} else {
				if (data[i][j] != tmp[m]) {
					data[i] += tmp[m];
					j++;
				}
			}
		}
		s[i] = i;
	}
	do {
		bool huruf[26];
		for (int i=0; i<26; i++) {
			huruf[i] = false;
		}
		char last = '-';
		bool valid = true;
		for (int i=0; valid && (i<n); i++) {
			int d = s[i];
			for (int j=0; valid && (j<data[d].size()); j++) {
				if (last == data[d][j]) {
					continue;
				} else {
					last = data[d][j];
					if (!huruf[last-'a']) {
						huruf[last-'a'] = true;
					} else {
						valid = false;
					}
				}
			}
		}
		if (valid) ans++;
	} while (next_permutation(s.begin(), s.end()));
	printf("%d\n", ans);
}

int main() {
	int tc;
	cin >> tc;
	for (int i=0; i<tc; i++) {
		printf ("Case #%d: ", i+1);
		solve();
	}
	return 0;
}