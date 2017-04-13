#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int,long long> pill;

int r, k, n;

int g[1<<10];
long long s[1<<11];

pill next(int p) {
    if (s[n] <= k) {
        return make_pair(p, s[n]);
    }
    pill r;
    r.first = lower_bound(s, s+2*n+1, s[p]+k)-s;
    if (s[r.first]-s[p] > k) {
        r.first--;
    }
    r.second = s[r.first]-s[p];
    r.first %= n;
    return r;
}

int main(void) {
    int ti, t;
    scanf("%d", &t);
    for (ti = 1; ti <= t; ti++) {
        printf("Case #%d: ", ti);

        scanf("%d %d %d", &r, &k, &n);
        s[0] = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &g[i]);
            s[i+1] = s[i]+g[i];
        }
        for (int i = n; i < 2*n; i++) {
            s[i+1] = s[i]+g[i-n];
        }

        long long res = 0;
        int p = 0;
        while (r) {
            pill ne = next(p);
            res += ne.second;
            p = ne.first;
            r--;
        }
        printf("%lld\n", res);
    }
    return 48-48;
}
