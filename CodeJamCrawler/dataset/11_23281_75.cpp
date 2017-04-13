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

#define FILE_IN  "B-large.in"
#define FILE_OUT "B-large.out"

#define MAXC 202
#define LOTS 2000000000000LL

typedef pair<int, int> pii;

int c;
int d;
pii p[MAXC];

bool good(long long dist) {
	long long pos = -LOTS;
	for (int i = 0; i < c; ++i) {
		pos = max(pos, p[i].first - dist);
		pos += (long long) d * (p[i].second - 1);
		if (pos > p[i].first + dist)
			return false;
		pos += d;
	}
	return true;
}

void solve() {
	scanf("%d%d", &c, &d);
	d *= 2;
	for (int i = 0; i < c; ++i) {
		scanf("%d%d", &p[i].first, &p[i].second);
		p[i].first *= 2;
	}
	sort(p, p + c);
	long long low = 0, high = LOTS;
	while (high - low > 1) {
		long long mid = (low + high) / 2;
		(good(mid) ? high : low) = mid;
	}
	if (good(low))
		high = low;
	printf("%I64d.%d\n", high / 2, (int)(high % 2 * 5));
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
