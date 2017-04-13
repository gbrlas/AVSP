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

#define FILE_IN  "D-small-attempt0.in"
#define FILE_OUT "D-small-attempt0.out"

void solve() {
	int n;
	scanf("%d", &n);
	int b = 0;
	for (int i = 1; i <= n; ++i) {
		int a;
		scanf("%d", &a);
		if (a != i)
			++b;
	}
	printf("%d.000000\n", b);
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
