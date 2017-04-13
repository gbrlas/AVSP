#include <stdio.h>

int main() {
    int testnum, n, smallest, x, sum, val;

    scanf("%d", &testnum);
    for (int test = 1;test <= testnum;test++) {
        scanf("%d", &n);
        smallest = 1111111;
        x = sum = 0;
        for (int i = 0;i < n;i++) {
            scanf("%d", &val);
            if (val < smallest)
                smallest = val;
            x ^= val;
            sum += val;
        }
        if (x)
            printf("Case #%d: NO\n", test);
        else
            printf("Case #%d: %d\n", test, sum - smallest);
    }
    return 0;
}
