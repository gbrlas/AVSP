#include<stdio.h>
#include<string.h>
#define maxn 100

bool p[maxn + 1][maxn + 1];

int i, j, n, m;

int main() {
    //freopen("a.txt", "r", stdin);
    freopen("C-small-attempt0.in","r",stdin);
    freopen("c.ans","w",stdout);
    int ii, nn;
    scanf("%d", &nn);
    for (ii = 1; ii <= nn; ii++) {
        printf("Case #%d: ",ii);
        scanf("%d", &n);
        int x1, x2, y1, y2;
        memset(p, 0, sizeof (p));
        while (n--) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            for (i = x1; i <= x2; i++)for (j = y1; j <= y2; j++) {
                    p[i][j] = 1;
                }
        }
        bool o = true;
        int step = 0;
        while (o) {
            o = false;
//            for (i = 1; i <= 10; i++) {
//                for (j = 1; j <= 10; j++)printf("%d", p[i][j]);
//                printf("\n");
//            }
            for (i = maxn; i; i--)for (j = maxn; j; j--) {
                    if (p[i][j])o = true;
                    if (!p[i - 1][j] && !p[i][j - 1])p[i][j] = false;
                    if (p[i - 1][j] && p[i][j - 1])p[i][j] = true;
                }
            step++;
        }
        printf("%d\n", step-1);
    }
    return 0;
}
