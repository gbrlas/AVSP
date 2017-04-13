#include <cstdio>

const int MAXN = 110;

int tot[MAXN];
double w[MAXN], ow[MAXN], oow[MAXN];
char s[MAXN][MAXN];

int main() {
    int testnum, n, tw;
    double ww;

    scanf("%d", &testnum);
    for (int test = 1;test <= testnum;test++) {
        scanf("%d", &n);
        for (int i = 0;i < n;i++) {
            scanf("%s", s[i]);
            tot[i] = 0;
            w[i] = 0;
            for (int j = 0;j < n;j++) {
                if (s[i][j] == '1') {
                    tot[i]++;
                    w[i] += 1;
                } else if (s[i][j] == '0') {
                    tot[i]++;
                }
            }
            w[i] /= tot[i];
        }
        for (int i = 0;i < n;i++) {
            ow[i] = 0;
            for (int j = 0;j < n;j++) if (s[i][j] != '.') {
                ww = 0; tw = 0;
                for (int k = 0;k < n;k++) if (k != i) {
                    if (s[j][k] == '0') {
                        tw++;
                    } else if (s[j][k] == '1') {
                        tw++;
                        ww += 1;
                    }
                }
                ow[i] += ww / tw;
            }
            ow[i] /= tot[i];
        }
        for (int i = 0;i < n;i++) {
            oow[i] = 0;
            for (int j = 0;j < n;j++) {
                if (s[i][j] != '.')
                    oow[i] += ow[j];
            }
            oow[i] /= tot[i];
        }
        printf("Case #%d:\n", test);
        for (int i = 0;i < n;i++) {
            printf("%.15lf\n", 0.25 * w[i] + 0.5 * ow[i] + 0.25 * oow[i]);
        }
    }
    return 0;
}
