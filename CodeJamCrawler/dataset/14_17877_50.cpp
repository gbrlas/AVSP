#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int t[5000][26], tot;
string s[20];
int n, m;
int w[10];
int ans, cnt;

void ins(string w) {
	int p = 0;
	for (int i = 0; i < w.size(); i++) {
		if (t[p][w[i] - 'A'] == 0) {
			t[p][w[i] - 'A'] = ++tot;
		}
		p = t[p][w[i] - 'A'];
	}
}
int calc(vector<string> a) {
	if (a.size() == 0) {
		return 0;
	}
	tot = 0;
	memset(t, 0, sizeof t);
	for (int i = 0; i < a.size(); i++) {
		ins(a[i]);
	}
	return tot + 1;
}

void dfs(int i) {
	if (i == n) {
		int tmp = 0;
		for (int j = 0; j < m; j++) {
			vector<string> a;
			for (int k = 0; k < n; k++) {
				if (w[k] == j) {
					a.push_back(s[k]);
				}
			}
			tmp += calc(a);
		}
		if (tmp > ans) {
			ans = tmp;
			cnt = 1;
		}
		else if(tmp == ans) {
			cnt += 1;
		}
		return;
	}
	for (int j = 0; j < m; j++) {
		w[i] = j;
		dfs(i + 1);
	}
}
int main() {
	int T;
	scanf("%d", &T);
	for (int q = 1; q <= T; q++) {
		cerr << q << endl;
		ans = 0;
		cnt = 0;
		printf("Case #%d: ", q);
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		dfs(0);
		printf("%d %d\n", ans, cnt);
	}
	return 0;
}
