#include <cstdio>
#include <iostream>
int main () {
    freopen ("C-large.in", "r", stdin);
    freopen ("out.txt", "w", stdout);
    int cn;
    int n;
    int a;
    scanf ("%d", &cn);
    for (int ci = 0; ci < cn; ci ++) {
        scanf ("%d", &n);
        int s = 0;
        int sum = 0;
        int min = 1000000000;
        for (int i = 0; i < n; i ++) {
            scanf ("%d", &a);
            s = s ^ a;
            sum += a;
            if (a < min)
                min = a;
        }
        if (s != 0) {
            printf ("Case #%d: NO\n", ci + 1);
        } else
            printf ("Case #%d: %d\n", ci + 1, sum - min);
    }
    return 0;
}
