#include <cstdio>

using namespace std;

int main(void) {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int T;
    int n;
    scanf ("%d", &T);
    for (int x = 1; x <= T; ++x) {
        scanf ("%d", &n);
        int min = 0x7fffffff;
        int a;
        int sum = 0;
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            scanf ("%d", &a);
                sum += a;
            if (a < min) {
                min = a;
            }
            ret ^= a;
        }
        printf ("Case #%d: ", x);
        if (ret == 0) {
            printf ("%d\n", sum-min);
        } else {
            printf ("NO\n");
        }

    }

    return 0;
}
