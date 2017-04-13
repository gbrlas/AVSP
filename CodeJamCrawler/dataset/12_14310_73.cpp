#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
ll acnt[105], bcnt[105], atp[105], btp[105], best;
int n, m;

void dfs(int i, ll irst, int j, ll jrst, ll ans) {
    if (i > n || j > m) {
        best = max(best, ans);
        return;
    }
    if (atp[i] == btp[j]) {
        if (irst < jrst) {
            dfs(i + 1, acnt[i + 1], j, jrst - irst, ans + irst);
        } else {
            dfs(i, irst - jrst, j + 1, bcnt[j + 1], ans + jrst);
        }
        return;
    }
    dfs(i + 1, acnt[i + 1], j, jrst, ans);
    dfs(i, irst, j + 1, bcnt[j + 1], ans);
}

int main() {
    freopen("D:\\C-small-attempt0.in","r",stdin);
    freopen("D:\\C-small-attempt0.out","w",stdout);
    int tc, c = 0, i, j, k, s;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d", &n, &m);
        for (i = 1; i <= n; i++)
            scanf("%lld%lld", acnt + i, atp + i);
        for (i = 1; i <= m; i++)
            scanf("%lld%lld", bcnt + i, btp + i);
        best = 0;
        dfs(1, acnt[1], 1, bcnt[1], 0);
        printf("Case #%d: %lld\n", ++c, best);
    }
    return 0;
}