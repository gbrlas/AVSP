#include <stdio.h>
#include <string.h>

const int M = 2001;
int N;
int d[M],l[M];
int D;
bool can[M][M];

int mymin(int a, int b) { return a < b ? a:b;}


bool solve() {
    scanf("%d", &N);
    d[0] = 0;
    for (int i = 1; i <= N; i++) scanf("%d %d", &d[i], &l[i]);
    scanf("%d", &D);
    memset(can, false, sizeof(can));

    can[0][1] = true;
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            can[j][i] = false;
            for (int k = 0; k < j; k++) {
                if (!can[k][j]) continue;
                if (d[i] - d[j] > mymin(l[j] , d[j] -d[k])) continue;
                can[j][i] = true;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < i; j++) {
            if (!can[j][i]) continue;
            if (D - d[i] <= mymin(l[i], d[i] - d[j])) return true;
        }
    }
    return false;
    
}


int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++){
        if (solve()) {
            printf("Case #%d: YES\n", i);
        } else {
            printf("Case #%d: NO\n", i);
        }
    }
    return 0;
}




