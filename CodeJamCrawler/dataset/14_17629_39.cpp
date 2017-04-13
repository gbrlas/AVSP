#include <cstdio>
#include <algorithm>
using namespace std;

int a[1221], b[1212], n;


int solve_war() {
    int ret = n;
    for (int i = 0, j = 0; i < n; ++i) {
        while (j < n && a[i] > b[j]) ++j;
        if (j++ < n) --ret;
    }
    return ret;
}

int solve_deceive() {
    int ret = 0;
    for (int i = 0, l = 0, r = 0; i < n; ++i)
        if (a[i] < b[l]) --r; else ++ret, ++l;
    return ret;
}

int main() {
    int cases; scanf("%d", &cases);
    for (int cas = 1; cas <= cases; ++cas) {
        scanf("%d", &n); 
        for (int i = 0; i < n; ++i) {
            double x; scanf("%lf", &x); 
            a[i] = x * 10000;// Naomi
        }
        for (int i = 0; i < n; ++i) {
            double x; scanf("%lf", &x); 
            b[i] = x * 10000;// Naomi
        }
        sort(a, a + n);
        sort(b, b + n);
        int ans1 = solve_deceive();
        int ans2 = solve_war();
        printf("Case #%d: %d %d\n", cas, ans1, ans2);
    }
    return 0;
}
