#include <cstdio>
#include <algorithm>
using namespace std;


int main() {

    int T, n, w, l, r, sum;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%d %d %d", &n, &w, &l);

        printf("Case #%d:", t);
        sum = 0;

        int side = 0;
        int maxr = -1;
        for (int i = 0; i < n; i++) {
            scanf("%d", &r);
            sum += r;
            maxr = max(r, maxr);
            if (w > l && sum > w) {
                if (side != 0) fprintf(stderr, "FAIL case %d\n", t);
                sum = 0;
                side = l;
            }
            if (w <= l && sum > l) {
                if (side != 0) fprintf(stderr, "FAIL case %d\n", t);
                sum = 0;
                side = w;
            }
            if (w > l) {
                printf(" %d %d", sum, side);
            } else {
                printf(" %d %d", side, sum);
            }
            sum += r;
        }
        if (maxr + maxr >= w && maxr + maxr >= l) fprintf(stderr, "MAXFAIL case %d\n", t);

        printf("\n");
    }
    return 0;
}


