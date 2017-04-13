#include <cstdio>
#include <string>
#include <string.h>

using namespace std;

int n, s, p, val;

int main() {
    freopen ("b.in", "rt", stdin);
    freopen ("b.out", "wt", stdout);
    int T;
    scanf ("%d\n", &T);
    for (int t = 1; t <= T; ++t) {
        printf("Case #%d: ", t);
        scanf ("%d%d%d", &n, &s, &p);
        int res = 0;
        for (int i = 0; i < n; i++) {
            scanf ("%d", &val);
            if ((val + 2) / 3 >= p) {
                res++;
            } else if ((val + 1) / 3 >= p-1 && p > 1 && s > 0) {
                res++;
                s--;
            }
        }
        printf ("%d", res);
        printf ("\n");
    }
}
