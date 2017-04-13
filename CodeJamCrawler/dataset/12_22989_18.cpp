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

#define MAXN 1000

int t[MAXN];
int p[MAXN];

int z[MAXN];

struct cmp {
	bool operator()(int i, int j) {
		if (p[i] * t[j] == p[j] * t[i])
			return i < j;
		return p[i] * t[j] > p[j] * t[i];
	}
};

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &t[i]);
	for (int i = 0; i < n; ++i)
		scanf("%d", &p[i]);
	for (int i = 0; i < n; ++i)
		z[i] = i;
	sort(z, z + n, cmp());
	for (int i = 0; i < n; ++i)
		printf(" %d", z[i]);
	printf("\n");
}

int main() {
	freopen(FILE_IN, "r", stdin);
	freopen(FILE_OUT, "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		printf("Case #%d:", i);
		solve();
	}
	return 0;
}
