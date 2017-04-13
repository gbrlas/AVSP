#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    freopen("D:\\A-small-attempt0.in", "r", stdin);
    freopen("D:\\A-small-attempt0.out", "w", stdout);
    static int N, L[10005], D[10005], length[10005], Sub;
    int i, j, k, t, got, tc;
    scanf("%d", &t);
    for (tc = 1; tc <= t; ++tc) {
        scanf("%d", &N);
        for (got = i = 0; i < N; i++)
            scanf("%d%d", D + i, L + i);
        memset(length, 0, sizeof (length));
        length[0] = D[0];
        scanf("%d", &Sub);
        for (i = 0; i < N; i++) {
            for (j = i + 1; j < N; j++) {
                if (length[i] + D[i] >= D[j]) {
                    if (L[j] < D[j] - D[i])
                        length[j] = max(length[j], L[j]);
                    else
                        length[j] = max(length[j], D[j] - D[i]);
                }
            }
        }
        for (i = 0; i < N; i++)
            if (D[i] + length[i] >= Sub)
                got = 1;
        printf("Case #%d: ", tc);
        puts(got == 1 ? "YES" : "NO");
    }
    return 0;
}
