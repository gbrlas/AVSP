#include <stdio.h>
#include <string.h>

const int M = 102;
int T, N, S, P;
int t[M];
int sp[M];
int nsp[M];
int ans[M][M];
void init(int c) {
    sp[c] = nsp[c] = 0;
    if (t[c] % 3 == 0 && t[c]/3 >= P)  sp[c] = 1;
    if ((t[c] - 1) % 3 == 0 && t[c] >= 1) {
        if ((t[c] - 1)/3 + 1 >= P)  sp[c] = 1;
    }
    if ((t[c] - 2) % 3 == 0 && t[c] >= 2) {
        if ((t[c] - 2)/3 + 1 >= P)  sp[c] = 1;
    }
    if ((t[c] - 2) % 3 == 0 && (t[c] - 2)/3 + 2 >= P && t[c] >= 2)  {
        nsp[c]  = 1;
    }
    if ((t[c] - 3) % 3 == 0 && t[c] >= 3) {
        if ((t[c] - 3)/3 + 2 >= P)  nsp[c] = 1;
    }
    if ((t[c] - 4) % 3 == 0 && t[c] >= 4) {
        if ((t[c] - 4)/3 + 2 >= P)  nsp[c] = 1;
    }
}

int _max(int a, int b) { return a > b ? a : b;}

int dp() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < S; j++) ans[i][j] = -100000000;
    for (int i = 0; i < N; i++) init(i);
    ans[0][1] = nsp[0];
    ans[0][0] = sp[0];
    for (int i = 1 ; i < N; i++) {
        ans[i][0] = ans[i-1][0] + sp[i];
        for (int j = 1; j <= S && j <= i + 1; j++) {
            ans[i][j] = _max(ans[i-1][j] + sp[i], ans[i-1][j-1] + nsp[i]);
        }
    }
}


int main() {
    scanf("%d\n",&T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d %d", &N, &S, &P);
        for (int j = 0; j < N; j++) {
            scanf("%d", &t[j]);
        }
        scanf("\n");
        dp();
        printf("Case #%d: %d\n", i+1, ans[N-1][S]);
    }
    return 0;

}





