#include <iostream>
#include <vector>
#include <memory>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <functional>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <vector>
#include <deque>
#include <list>
using namespace std;

#define bitcount  __builtin_popcount
#define all(x)    x.begin(), x.end()
#define gcd       __gcd

typedef long long lnt;

int v[1<<7];
int D, I, M, N;

int c[1<<7][1<<8];

int min(int a, int b) {
    return (a<b)?a:b;
}

int max(int a, int b) {
    return (a>b)?a:b;
}

int hujak(int e, int en) {

    if (c[e][en] >= 0) {
        return c[e][en];
    }

    if (e == 0) {
        c[e][en] = 0;
        return c[e][en];
    }

    int r = D + hujak(e-1, en);

    for (int i = 0; i < 256; i++) {
        if (abs(en-i) > M) {
            continue;
        }
        int cr = abs(i-v[e-1]) + hujak(e-1,i);
        if (r > cr) {
            r = cr;
        }
    }

    for (int i = 0; i < 256; i++) {
        if (i <= min(v[e-1],en) || i >= max(v[e-1],en)) {
            continue;
        }
        if (abs(en-i) > M) {
            continue;
        }
        int cr = I + hujak(e,i);
        if (cr < r) {
            r = cr;
        }
    }

    c[e][en] = r;
    return c[e][en];
}

int main(void) {
    int ti, t;
    scanf("%d", &t);
    for (ti = 1; ti <= t; ti++) {
        printf("Case #%d: ", ti);

        scanf("%d %d %d %d", &D, &I, &M, &N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &v[i]);
        }

        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 256; j++) {
                c[i][j] = -1;
            }
        }

        int r = 1000000000;
        for (int i = 0; i < 256; i++) {
            if (r > hujak(N,i)) {
                r = hujak(N,i);
            }
        }
        printf("%d\n", r);
    }
    return 48-48;
}
