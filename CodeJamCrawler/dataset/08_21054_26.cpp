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

#define MAXS 105

bool hit[MAXS][MAXS];

void solve() {
	fill(hit[0], hit[MAXS], 0);
	int w, h;
	scanf("%d%d", &w, &h);
	int dx1, dy1;
	scanf("%d%d", &dx1, &dy1);
	int dx2, dy2;
	scanf("%d%d", &dx2, &dy2);
	int x, y;
	scanf("%d%d", &x, &y);
	queue<int> q;
	hit[x][y] = 1;
	q.push(x); q.push(y);
	int c = 0;
	while (!q.empty()) {
		++c;
		x = q.front(); q.pop();
		y = q.front(); q.pop();
		int nx = x + dx1;
		int ny = y + dy1;
		if (nx >= 0 && nx < w && ny >= 0 && ny < h && !hit[nx][ny]) {
			hit[nx][ny] = 1;
			q.push(nx);
			q.push(ny);
		}
		nx = x + dx2;
		ny = y + dy2;
		if (nx >= 0 && nx < w && ny >= 0 && ny < h && !hit[nx][ny]) {
			hit[nx][ny] = 1;
			q.push(nx);
			q.push(ny);
		}
	}
	printf("%d\n", c);
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
