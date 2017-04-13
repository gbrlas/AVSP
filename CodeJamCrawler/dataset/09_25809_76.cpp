#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
char str[5001][32];
int main() {
    int L, D, N;
    scanf("%d%d%d", &L, &D, &N);
    for (int i = 0; i < D; ++i) {
        scanf("%s", str[i]);
    }
    for (int kase = 1; kase <= N; ++kase) {
        char s[28 * 16];
        scanf("%s", s);
        int token = 0;
        bool alpha[32][27];
        memset(alpha, 0, sizeof(alpha));
        bool flag = false;
		int i;
        for ( i = 0; s[i]; ++i) {
            if (s[i] == '(') {
                flag = true;
                continue;
            } else if (s[i] == ')') {
                flag = false;
                token++;
            } else {
                alpha[token][s[i] - 'a'] = true; 
                if (flag == false) {
                    token++;
                }
            }
        }
        int ans = 0;
        for ( i = 0; i < D; ++i) {
            bool ok = true;
            for (int j = 0; j < L; ++j) {
                if (!alpha[j][str[i][j] - 'a']) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ++ans;
            }
        }
        printf("Case #%d: %d\n", kase, ans);
    }
    return 0;
}
