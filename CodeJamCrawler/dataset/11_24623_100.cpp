#include <stdio.h>

int main() {
    int testnum, t, n, v;

    scanf("%d", &testnum);
    for (int test = 1;test <= testnum;test++) {
        scanf("%d", &n);
        t = 0;
        for (int i = 0;i < n;i++) {
            scanf("%d", &v);
            if (v != i + 1)
                t++;
        }
        printf("Case #%d: %d.000000\n", test, t);
    }
    return 0;
}
