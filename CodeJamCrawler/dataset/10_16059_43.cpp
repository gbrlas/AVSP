#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int t, r, k, n, p[1000];
int dp[1000][1000], ery[100000];
int i, j, sum, ans, l;

int main(){
    //freopen("C-small.in", "r", stdin);
    //freopen("C-small.out", "w", stdout);
    scanf("%d", &t);
    for (i = 1; i <= t; ++i){
        scanf("%d%d%d", &r, &k, &n);
        for (j = 0; j < n; ++j)
            scanf("%d", &p[j]);
        for (int a = 0; a < n; ++a){
            dp[a][a] = p[a];
            for (j = a + 1; j < n; ++j)
                dp[a][j] = dp[a][j - 1] + p[j];
        }
        for (int a = 1; a < n; ++a)
            for (j = 0; j < a; ++j)
                dp[a][j] = dp[a][n - 1] + dp[0][j];
        int now = 0;
        l = sum = 0;
        int next;
        do{
            for (j = now; j < now + n; ++j)
                if (dp[now][j % n] <= k && dp[now][(j + 1) % n] > k || j == now + n - 1){
                    ery[l] = dp[now][j % n];
                    sum += ery[l++];
                    next = (j + 1) % n;
                    break;
                }
            now = next;
        } while (now && l < r);
        if (l == r){
            printf("Case #%d: %d\n", i, sum);
            continue;
        }
        ans = (r / l) * sum;
        l = r % l;
        for (j = 0; j < l; ++j)
            ans += ery[j];
        printf("Case #%d: %d\n", i, ans);
    }
    //system("pause");
    return 0;
}
