#include <cstdio>
#include <algorithm>
using namespace std;

int d[10005], len[10005], best[10005], D, T, n;

int main() {


    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &n);
        int i;
        for (i = 0; i < n; i++) {
            scanf("%d %d", &d[i], &len[i]);
        }
        scanf("%d", &D);

        for (i = 0; i < n; i++) {
            //best way to get here?
            best[i] = -1;
            if (i == 0) best[i] = d[0];
            for (int j = 0; j < i; j++) {
                if (d[i] - d[j] > best[j]) continue;
                best[i] = max(best[i], min(len[i], d[i]-d[j]));
            }
//            printf("best[%d] = %d\n", i, best[i]);
            if (d[i] + best[i] >= D) break;
        }

        printf("Case #%d: %s\n", t, (i < n ? "YES" : "NO"));

    }

    return 0;
}



