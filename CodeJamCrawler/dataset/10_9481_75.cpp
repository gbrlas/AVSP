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

int a1, a2, b1, b2;

bool brute_win(int a, int b) {
    if (a < b) {
        swap(a, b);
    }
    if (a == b) {
        return false;
    }
    int m = a % b;
    if (m == 0) {
        return true;
    }
    if (!brute_win(b,m)) {
        return true;
    }
    if (b+m < a && !brute_win(b+m,b)) {
        return true;
    }
    return false;
}

long long brute(void) {
    long long r = 0;
    for (int a = a1; a <= a2; a++) {
        for (int b = b1; b <= b2; b++) {
            if (brute_win(a,b)) {
                r++;
            }
        }
    }
    return r;
}

int main(void) {
    int ti, t;
    scanf("%d", &t);
    for (ti = 1; ti <= t; ti++) {
        printf("Case #%d: ", ti);

        scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
        printf("%lld\n", brute());

    }
    return 48-48;
}
