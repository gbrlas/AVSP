#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("D-small-attempt0.out", "w", stdout);

    int t, T, i, j, n, x, y;
    double N[1000], K[1000];

    scanf("%d", &T);

    for(t = 1;t <= T;t++) {
        scanf("%d", &n);
        for(i = 0;i < n;i++) {
            scanf("%lf", N + i);
        }
        for(i = 0;i < n;i++) {
            scanf("%lf", K + i);
        }

        sort(N, N + n);
        sort(K, K + n);

        j = -1;
        x = 0;
        for(i = 0;i < n;i++) {
            for(j++;j < n && K[j] < N[i];j++);
            if(j == n) {
                x = n - i;
                break;
            }
        }
        j = 0;
        y = 0;
        for(i = 0;i < n;i++) {
            if(N[i] > K[j]) {
                y++;
                j++;
            }
        }

        printf("Case #%d: %d %d\n", t, y, x);

    }
    return 0;
}
