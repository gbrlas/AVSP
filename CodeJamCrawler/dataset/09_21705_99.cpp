#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cctype>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#define FILE_IN  "A-small-attempt0.in"
#define FILE_OUT "A-small-attempt0.out"

#define MAXL 18
#define MAXN 502
#define MAXD 5002

int L, D, N;
char words[MAXD][MAXL];

void solve() {
	bool good[MAXL][26];
	scanf("\n");
	for (int i = 0; i < L; ++i) {
		fill(good[i], good[i+1], 0);
		char c;
		if (scanf("(%c", &c) == 1) {
			while (c != ')') {
				good[i][c - 'a'] = true;
				scanf("%c", &c);
			}
		} else {
			scanf("%c", &c);
			good[i][c - 'a'] = true;
		}
	}
	int cnt = 0;
	for (int i = 0; i < D; ++i) {
		bool ok = true;
		for (int j = 0; j < L && ok; ++j)
			if (!good[j][words[i][j] - 'a'])
				ok = false;
		if (ok)
			++cnt;
	}
	printf("%d\n", cnt);
}

int main() {
	freopen(FILE_IN, "r", stdin);
	freopen(FILE_OUT, "w", stdout);
	scanf("%d%d%d", &L, &D, &N);
	for (int i = 0; i < D; ++i)
		scanf(" %s", words[i]);
	for (int i = 1; i <= N; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
