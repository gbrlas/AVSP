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

#define FILE_IN  "C-large.in"
#define FILE_OUT "C-large.out"

#define LEN 20
#define MOD 10000

const char LINE[LEN] = "welcome to code jam";

void solve() {
	int cnts[LEN];
	fill(cnts, cnts + LEN, 0);
	cnts[0] = 1;
	char c;
	scanf("%c", &c);
	while (c != '\n') {
		for (int i = LEN - 1; i >= 0; --i)
			if (LINE[i] == c)
				cnts[i + 1] = (cnts[i] + cnts[i + 1]) % MOD;
		scanf("%c", &c);
	}
	printf("%04d\n", cnts[LEN - 1]);
}

int main() {
	freopen(FILE_IN, "r", stdin);
	freopen(FILE_OUT, "w", stdout);
	int n;
	scanf("%d\n", &n);
	for (int i = 1; i <= n; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
