#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    freopen("D-large.in", "r", stdin);
    int T, t, n;
    double a[1000], b[1000];
    int ans1, ans2;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%lf", a+i);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%lf", b+i);
        }
        sort(a, a+n);
        sort(b, b+n);
        ans1 = 0, ans2 = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            if (a[i] > b[j]) {
                ++ans1;
                ++j;
            }
        }
        for (int i = 0, j = 0; i < n && j < n; ++i, ++j) {
            while (j < n && a[i] > b[j]) {
                ++j;
            }
            if (j == n) break;
            ++ans2;
        }
        printf("Case #%d: %d %d\n", t, ans1, n-ans2);
    }
    return 0;
}
