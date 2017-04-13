#include <cstdio>
#include <cstring>
char *x = "welcome to code jam";
int f[512][32];
char str[512];
int main() {
//	freopen("a.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    gets(str);
    for (int kase = 1; kase <= t; ++kase) {
        gets(str);
        int n = strlen(str);
        int m = strlen(x); 
        int ans = 0;
        int i;
        for (i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (j > i) {
                    f[i][j] = 0;
                } else if (i == 0) {
                    f[i][j] = (str[i] == x[j]);
                } else {
                    if (str[i] == x[j]) {
						if (j == 0) f[i][j] = (f[i - 1][j] + 1) % 10000;
						else  {
							f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % 10000; 
						}
                    }else {
                        f[i][j] = f[i - 1][j];
                    }
                }
            }
        }
        ans = f[n - 1][m-1];
        printf("Case #%d: %04d\n", kase, ans);
    }
    return 0;
}
