#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int MXN = 501;

int R, C, D;
char a[MXN][MXN];
double sum[MXN][MXN];
double xsum[MXN][MXN];
double ysum[MXN][MXN];
int n;
int ans;

int main () {
    freopen ("B-small-attempt0.in", "r", stdin);
    freopen ("out.txt", "w", stdout);
    int cn;
    int n, m;
    scanf ("%d", &cn);
    for (int ci = 0; ci < cn; ci ++) {
        scanf ("%d%d%d", &R, &C, &D);
        for (int i = 0; i < R; i ++) {
            scanf ("%s", a[i]);
            for (int j = 0; j < C; j ++)
                a[i][j] -= '0';
        }
        memset (sum, 0, sizeof(sum));
        for (int i = 1; i <= R; i ++)
            for (int j = 1; j <= C; j++) {
                sum [i][j] = sum[i][j - 1] + sum[i - 1][j] - sum [i - 1][j - 1] + (double)(a[i - 1][j - 1]) + D;
                xsum [i][j] = xsum[i][j - 1] + xsum[i - 1][j] - xsum [i - 1][j - 1] + (double)(a[i - 1][j - 1] + D) * i;
                ysum [i][j] = ysum[i][j - 1] + ysum[i - 1][j] - ysum [i - 1][j - 1] + (double)(a[i - 1][j - 1] + D) * j;
            }
        int ans = 0;
        for (int i = 0; i < R; i ++)
            for (int j = 0; j < C; j ++) {
                int len = min (R - i, C - j);
                for (int k = max (ans, 3); k <= len; k++) {
                    int up = i + 1;
                    int left = j + 1;
                    int down = i + k;
                    int right = j + k;
                    double tsum = sum[i][j] + sum[down][right] - sum[i][right] - sum[down][j]
                                  - a[up - 1][left - 1] - a[up - 1][right - 1] - a[down - 1][left - 1]- a[down - 1][right - 1] - 4 * D;
                    double txsum = xsum[i][j] + xsum[down][right] - xsum[i][right] - xsum[down][j]
                                  - (double)(a[up - 1][left - 1] + D) * up - (double)(a[up - 1][right - 1] + D) * up
                                  - (double)(a[down - 1][left - 1] + D) * down - (double)(a[down - 1][right - 1] + D) * down;
                    double tysum = ysum[i][j] + ysum[down][right] - ysum[i][right] - ysum[down][j]
                                  - (double)(a[up - 1][left - 1] + D) * left - (double)(a[up - 1][right - 1] + D) * right
                                  - (double)(a[down - 1][left - 1] + D) * left - (double)(a[down - 1][right - 1] + D) * right;
                 //   printf ("(%d, %d), %d:\n", i, j, k);
                  //  cout << tsum << endl;
                 //   cout << txsum << endl;
                 //   cout << tysum << endl;
                    double cx = txsum / tsum;
                    double cy = tysum / tsum;
                 //   cout << cx << endl;
                  //  cout << cy << endl;
                  //  cout << fabs ((cx - i) * 2 - k - 1) << endl;
                    //cout << fabs ((cy - j) * 2 - k - 1) << endl;
                    if (fabs ((cx - i) * 2 - k - 1) < 1e-5 && fabs ((cy - j) * 2 - k - 1) < 1e-5) {
                        ans = k;
                       // cout << ans << endl;
                    }
                }
            }
        if (ans == 0) {
            printf ("Case #%d: IMPOSSIBLE\n", ci + 1);
        } else {
            printf ("Case #%d: %d\n", ci + 1, ans);
        }
    }
    return 0;
}
