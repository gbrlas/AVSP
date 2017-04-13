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

#define MAXN 10000

int d[MAXN], l[MAXN];
int r[MAXN];

void solve() {
	int n, D;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &d[i], &l[i]);
	scanf("%d", &D);
	for (int i = n - 1; i >= 0; --i) {
		int &rr = r[i];
		rr = d[i] + l[i] >= D ? D - d[i] : -1;
		for (int j = i + 1; j < n && d[j] - d[i] <= l[i]; ++j)
			if (r[j] >= 0 && r[j] <= d[j] - d[i])
				if (rr < 0 || rr > d[j] - d[i])
					rr = d[j] - d[i];
	}
	printf("%s\n", r[0] >= 0 && r[0] <= d[0] ? "YES" : "NO");
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
