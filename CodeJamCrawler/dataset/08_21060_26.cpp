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

#define MAXN 33

typedef pair<int, int> pii;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int n, m;
char area[MAXN][MAXN];
int dist[MAXN][MAXN];
int from[MAXN][MAXN];

void solve() {
	scanf("%d%d", &n, &m);
	fill(area[0], area[MAXN], '.');
	fill(dist[0], dist[MAXN], 100000);
	fill(from[0], from[MAXN], -1);
	queue<int> q;
	int trees = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			scanf(" %c", &area[i][j]);
			if (area[i][j] == 'T') {
				q.push(i); q.push(j);
				dist[i][j] = 0;
				from[i][j] = trees++;
			}
		}
	pii coll1, coll2;
	int colls = 0;

	while (!q.empty()) {
		int a = q.front(); q.pop();
		int b = q.front(); q.pop();
		for (int d = 0; d < 4; ++d) {
			int na = a + dx[d];
			int nb = b + dy[d];
			if (area[na][nb] == '.')
				continue;
			if (from[na][nb] < 0) {
				from[na][nb] = from[a][b];
				dist[na][nb] = dist[a][b] + 1;
				q.push(na); q.push(nb);
			} else if (from[na][nb] != from[a][b] && colls == 0) {
				coll1 = pii(a, b);
				coll2 = pii(na, nb);
				++colls;
			}
		}
	}
	int work = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (area[i][j] != '.')
				work += dist[i][j];
	if (colls > 0) {
		int a = dist[coll1.first][coll1.second];
		int b = dist[coll2.first][coll2.second];
		work += (b + 1) * (a + 1); 
	}
	printf("%d\n", work);
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
