#include <iostream>
#include <cstdio>
using namespace std;

int c[1003];

int main()
{
    int t, n, i, j;
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++) {
        scanf("%d", &n);
        int tmp = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &c[i]);
            tmp ^= c[i];
        }
        if (tmp != 0) {
            printf("Case #%d: NO\n", cas);
        } else {
            int sum = 0;
            int max = 0;
            tmp = 0;
            for (i = 0; i < n; i++) {
                sum += c[i];
            }
            for (i = 0; i < n; i++) {
                if (max < sum-c[i])
                    max = sum-c[i];
            }
            printf("Case #%d: %d\n", cas, max);
        }
    }
    return 0;
}
