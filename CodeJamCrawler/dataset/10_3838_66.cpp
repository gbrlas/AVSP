
#include <stdio.h>
#define N 1000
int arr[N];
int end[N];
long long num[N];
int main()
{
    int T, ca, i, j, start, n, r, k;
    long long cnt, ans;
    freopen("2.in", "r", stdin);
    freopen("2.out", "w", stdout);
    scanf("%d", &T);
    for (ca = 1; ca <= T; ca++) {
        scanf("%d%d%d", &r, &k, &n);
        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        for (i = 0; i < n; i++) {
            cnt = 0;
            start = i;
            for (j = 0; j < n; j++) {
                if (cnt + arr[start] > k) {
                    break;
                }
                cnt += arr[start];
                start = (start + 1) % n;
            }
            if (cnt == 0) {
                end[i] = -1;
                num[i] = 0;
            } else {
                end[i] = start;
                num[i] = cnt;
            }
        }
        start = 0;
        ans = 0;
        for (i = 0; i < r; i++) {
            if (end[start] == -1) {
                break;
            }
            ans += num[start];
            start = end[start];
        }
        printf("Case #%d: %lld\n", ca, ans);
    }
    return 0;
}
