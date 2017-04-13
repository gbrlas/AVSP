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

#define FILE_IN  "B-small-attempt0.in"
#define FILE_OUT "B-small-attempt0.out"

#define MAXN 303
#define FENCE 10000
#define LOTS 100000000

typedef pair<int, int> pii;
typedef map<string, int> msi;
typedef pair<int, pii> pipii;

int n;
msi colors;
pipii painters[MAXN];

pii fp[MAXN];
int fpn;

void filter(int a, int b, int c) {
	fpn = 0;
	for (int i = 0; i < n; ++i)
		if (painters[i].first == a || painters[i].first == b || painters[i].first == c)
			fp[fpn++] = painters[i].second;
}

int paint() {
	sort(fp, fp + fpn);
	int s = 0;
	int c = 0;
	set<int> ends;
	int i = 0;
	while (s < FENCE) {
		while (!ends.empty() && *ends.begin() <= s)
			ends.erase(ends.begin());
		while (i < fpn && fp[i].first <= s)
			ends.insert(fp[i++].second);
		if (ends.empty()) {
//			printf("failed @ %d\n", s);
			return -1;
		}
		int last = *ends.rbegin();
		++c;
		s = last;
	}
	return c;
}

void solve() {
	colors.clear();
	scanf("%d", &n);
	char col[20];
	int a, b;
	for (int i = 0; i < n; ++i) {
		scanf(" %s %d %d", col, &a, &b);
		int cid;
		if (colors.count(col) > 0)
			cid = colors[col];
		else {
			cid = colors.size();
			colors[col] = cid;
		}
		painters[i] = pipii(cid, pii(a-1, b));
	}
	int cc = colors.size();
	int best = LOTS;
	if (cc < 3) {
		filter(0, 0, cc-1);
		int p = paint();
		if (p >= 0)
			best = p;
	}
	for (int i = 0; i < cc; ++i)
		for (int j = i + 1; j < cc; ++j)
			for (int k = j + 1; k < cc; ++k) {
				filter(i, j, k);
				int p = paint();
				if (p < 0)
					continue;
//				printf("%d @ %d, %d, %d\n", p, i, j, k);
				best = min(best, p);
			}
	if (best == LOTS)
		printf("IMPOSSIBLE\n");
	else
		printf("%d\n", best);
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
