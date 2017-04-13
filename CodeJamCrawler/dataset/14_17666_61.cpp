#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

struct Blk {
    int x[2], y[2];
}a[1111];

const LL oo = 1e15;
LL d[1111][1111], f[1111];
int vis[1111];
int n, w, h;
void readin() {
    scanf("%d%d%d", &w, &h, &n);
    for (int i = 1; i <= n; ++i) 
        scanf("%d%d%d%d", &a[i].x[0], &a[i].y[0], &a[i].x[1], &a[i].y[1]);
}

LL dist(Blk &a, Blk &b) {
    LL ret = 0;
    LL l, r;
    l = max(a.x[0], b.x[0]);
    r = min(a.x[1], b.x[1]);
    if (l <= r) ret = 0;
        else ret = l - r - 1;
    l = max(a.y[0], b.y[0]);
    r = min(a.y[1], b.y[1]);
    if (l <= r) ret = max(ret, 0ll);
        else ret = max(ret, l - r -1);
    return ret;
}

void work() {
    int st = n + 1, en = st + 1;
    for (int i = 1; i <= n; ++i) 
        for (int j = i; j <= n; ++j){
            d[i][j] = d[j][i] = dist(a[i], a[j]);
            //printf("%d %d %I64d\n", i, j, d[i][j]);
        }
    for (int i = 1; i <= n; ++i) {
        d[st][i] = d[i][st] = a[i].x[0];
        d[en][i] = d[i][en] = w - a[i].x[1] - 1;
    }
    d[st][en] = d[en][st] = w;
    for (int i = 1; i <= en; ++i) f[i] = oo;
    for (int i = 1; i <= en + 1; ++i) vis[i] = 0;
    f[st] = 0;
    for (int j = 1; j <= en; ++j) {
        int p = 1; while (vis[p]) ++p;
        for (int i = p + 1; i <= en; ++i)
            if (!vis[i] && f[i] < f[p])
                p = i;
        if (p >= en) return;
        vis[p] = 1;
        for (int i = 1; i <= en; ++i) 
            if (f[i] > f[p] + d[p][i])
                f[i] = f[p] + d[p][i];
    }
}

int main() {
    int task; scanf("%d", &task);
    for (int cas = 1; cas <= task; ++cas) {
        printf("Case #%d: ", cas);
        readin();
        work();
        printf("%I64d\n", f[n + 2]);
    }

    return 0;
}
