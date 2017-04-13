
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
    int arr[1000];
    queue<int>Q;
    int T, ca, i, r, k, n, v, ans, tot, cnt, top;
    freopen("2.in", "r", stdin);
    freopen("2.out", "w",stdout);
    scanf("%d", &T);
    for (ca = 1; ca <= T; ca++) {
        while (!Q.empty()) {
            Q.pop();
        }
        scanf("%d%d%d", &r, &k, &n);
        for (i = 0; i < n; i++) {
            scanf("%d", &v);
            Q.push(v);
        }
        ans = 0;
        for (i = 0; i < r; i++) {
            cnt = 0;
            tot = 0;
            while (true) {
                top = Q.front();
                cnt++;
                tot += top;
                if (cnt > n || tot > k) {
                    ans += tot - top;
                    break;
                }                
                Q.pop();
                Q.push(top);
            }
        }
        printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}


    