#include <stdio.h>
#include <string.h>

const int M = 2000001;
int c[M];
int v[M][10];

void find(int k) {
    if (k <= 10) return;
    int w = 0;
    int s = 1;
    while (s < k) s = s * 10;
    for (int i = 10 ; i <= s / 10; i = i *  10) {
        if (k % i < i / 10) continue;
        w = k % i * (s / i) + k / i;
        if (w > k) {
            int j;
            for(j = 0; j < c[k]; j++) {
                if (w == v[k][j]) break;
            }
            if (j == c[k]) v[k][c[k]++] = w;
        }
    }
}

int main() {
    int T, n, m;
    memset(c, 0, sizeof(c));
    for (int i = 0; i <= 2000000; i++) find(i);
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



