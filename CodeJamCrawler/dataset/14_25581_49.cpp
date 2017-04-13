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

#define MAXN 102
#define MAXT 1102

int p, q, n;
int h[MAXN], g[MAXN];

int loot[MAXN][MAXT];

void solve() {
    scanf("%d%d%d", &p, &q, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &h[i], &g[i]);
    }
    fill(loot[0], loot[MAXN], -1);
    loot[0][1] = 0;
    for (int i = 0; i < n; ++i) {
        for (int t = 0; t < MAXT; ++t) if (loot[i][t] >= 0) {
            if (t > MAXT - 20) {
                fprintf(stderr, "bad\n");
            }
            int mt = (h[i] - 1) / q + 1;
            for (int j = 0; j < mt; ++j) {
                int tt = t + j;
                int hh = h[i] - q * j;
                if (tt * p >= hh) {
                    int nt = tt - ((hh - 1) / p + 1);
                    loot[i + 1][nt] = max(loot[i + 1][nt], loot[i][t] + g[i]);
                }
            }
            loot[i + 1][t + mt] = max(loot[i + 1][t + mt], loot[i][t]);
        }
    }
    int best = 0;
    for (int i = 0; i < MAXT; ++i)
        best = max(best, loot[n][i]);
	printf("%d\n", best);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
