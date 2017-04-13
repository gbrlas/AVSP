#include <stdio.h>
#include <string.h>

const int M = 2000000;
int c[M];
int v[M][10];

void find(int k) {
    int w = 0;
    if (k < 10) {
        c[k] = 0;
    } else if (k < 100) {
        w = k % 10 * 10 + k / 10;
        if (w > k) {
            v[k][c[k]++] = w;
        }
    } else if (k < 1000) {
        w = k % 10 * 100 + k / 10;
        if (w > k) {
            v[k][c[k]++] = w;
        }
        w = k % 100 * 10 + k / 100;
        if (w > k) {
            v[k][c[k]++] = w;
        }
    }
}

int main() {
    int T, n, m;
    memset(c, 0, sizeof(c));
    for (int i = 0; i <= 1000; i++) find(i);
    scanf("%d\n", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d\n", &n, &m);
        int ans = 0;
        for (int j = n; j <= m; j++) {
            for (int k = 0; k < c[j]; k++) {
                if (v[j][k] <= m) ans ++;
            }
        }
        printf("Case #%d: %d\n", i + 1, ans);
    }
    return 0;
}



