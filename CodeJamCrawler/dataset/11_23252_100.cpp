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

#define FILE_IN  "C-small-attempt0.in"
#define FILE_OUT "C-small-attempt0.out"
#define LOTS 0x3fffffff

void solve() {
	int n;
	scanf("%d", &n);
	int x = 0, s = 0, m = LOTS;
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		x ^= a;
		s += a;
		m = min(m, a);
	}
	if (x != 0)
		printf("NO\n");
	else
		printf("%d\n", s - m);
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
