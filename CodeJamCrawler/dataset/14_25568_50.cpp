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

#define FILE_IN  "C-small.in"
#define FILE_OUT "C-small.out"

#define MAXB 1000
#define MAXW 1000
#define MAXH 2001
#define LOTS 0x3fffffff
#define D 8

typedef pair<int, int> pii;

int dx[D] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[D] = {1, 1, 0, -1, -1, -1, 0, 1};

int W, H, B;
int X0[MAXB], Y0[MAXB], X1[MAXB], Y1[MAXB];

bool flow[MAXW][MAXH];
int dist[MAXW][MAXH];

void solve() {
    scanf("%d%d%d", &W, &H, &B);
    for (int i = 0; i < B; ++i) {
        scanf("%d%d%d%d", &X0[i], &Y0[i], &X1[i], &Y1[i]);
    }
    fill(flow[0], flow[MAXW], true);
    for (int i = 0; i < B; ++i) {
        for (int x = X0[i]; x <= X1[i]; ++x)
            for (int y = Y0[i]; y <= Y1[i]; ++y)
                flow[x][y] = false;
    }
    fill(dist[0], dist[MAXW], LOTS);
    deque<pii> Q;
    for (int i = 0; i < H; ++i) {
        if (flow[0][i]) {
            dist[0][i] = 1;
            Q.push_back(pii(0, i));
        } else {
            dist[0][i] = 0;
            Q.push_front(pii(0, i));
        }
    }
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop_front();
        for (int i = 0; i < D; ++i) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 0 || xx >= W || yy < 0 || yy >= H)
                continue;
            int dd = dist[x][y] + (flow[xx][yy] ? 1 : 0);
            if (dist[xx][yy] <= dd)
                continue;
            dist[xx][yy] = dd;
            if (flow[xx][yy]) {
                Q.push_back(pii(xx, yy));
            } else {
                Q.push_front(pii(xx, yy));
            }
        }
    }
    int best = LOTS;
    for (int i = 0; i < H; ++i) {
        best = min(best, dist[W-1][i]);
    }
	printf("%d\n", best);
}

int main() {
	//freopen(FILE_IN, "r", stdin);
	//freopen(FILE_OUT, "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
