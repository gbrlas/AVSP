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

#define FILE_IN  "A-large.in"
#define FILE_OUT "A-large.out"

void solve() {
	int n;
	scanf("%d", &n);
	int bp = 1, bt = 0, op = 1, ot = 0;
	for (int i = 0; i < n; ++i) {
		char r;
		int b;
		scanf(" %c %d", &r, &b);
		if (r == 'B') {
			int d = abs(bp - b);
			bp = b;
			bt = max(bt + d, ot) + 1;
		} else {
			int d = abs(op - b);
			op = b;
			ot = max(ot + d, bt) + 1;
		}
	}
	printf("%d\n", max(bt, ot));
}

int main() {
	freopen(FILE_IN, "r", stdin);
	freopen(FILE_OUT, "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
