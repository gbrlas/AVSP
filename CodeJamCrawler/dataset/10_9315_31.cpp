#include<stdio.h>
#include<string.h>
#define maxn 5000

int M[maxn];

int price[maxn], now, p[2][maxn][20];

int i, j, n, m;

int main() {
//    freopen("a.txt","r",stdin);
    freopen("B-small-attempt0.in","r",stdin);
    freopen("b_small.ans","w",stdout);
    int ii, nn;
    scanf("%d", &nn);
    for (ii = 1; ii <= nn; ii++) {
        printf("Case #%d: ", ii);
        scanf("%d", &m);
        n = (1 << m);
        now = 0;
        memset(p, -1, sizeof (p));
        for (i = 1; i <= n; i++) {
            scanf("%d", &M[i]);
            M[i] = (M[i] > m ? 0 : m - M[i]);
            for (j = M[i]; j <= m; j++)
                p[now][i][j] = 0;
        }

        int mm, a, b;
        for (mm = 1; mm <= m; mm++) {
            n /= 2;
            now = 1 - now;
            for (i = 1; i <= n; i++) {
                scanf("%d", &price[i]);
                for (j = 0; j <= m; j++)p[now][i][j] = -1;
            }
            for (i = 1; i <= n; i++) {
                a = i * 2 - 1;
                b = a + 1;
                for (j = 0; j <= m; j++) {
                    if (p[1-now][a][j]>=0&&p[1-now][b][j]>=0)
                        p[now][i][j]=p[1-now][a][j]+p[1-now][b][j];
                    if(p[1-now][a][j+1]>=0&&p[1-now][b][j+1]>=0){
                        if(p[now][i][j]>p[1-now][a][j+1]+p[1-now][b][j+1]+price[i]||p[now][i][j]<0){
                            p[now][i][j]=p[1-now][a][j+1]+p[1-now][b][j+1]+price[i];
                        }
                    }
                }
                for(j=1;j<=m;j++)if(p[now][i][j-1]>=0){
                    if(p[now][i][j]<0||p[now][i][j]>p[now][i][j-1])p[now][i][j]=p[now][i][j-1];
                }
                        
            }
        }
//        for(i=0;i<=m;i++)
//        printf("%d\n",p[now][1][i]);
        printf("%d\n",p[now][1][0]);
    }
    return 0;
}
