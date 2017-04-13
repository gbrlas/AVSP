#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int d = 0;

const int MAXN = 101010101, MAXM = 1010;
const long long mod = 1000002013;

int T, N, M, begin[MAXM], end[MAXM];

int main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %d", &N, &M);
        for (int i = 0; i < N; i++) {
            begin[i] = end[i] = 0;
        }
        long long prev = 0;
        for (int i = 0; i < M; i++) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            begin[a] += c;
            end[b] += c;
            long long len = b - a;
            prev = (prev + c * len * (len - 1) / 2) % mod;
        }

        long long ans = 0;
        for (int len = 0; len < N; len++) {
            for (int left = 1; left <= N; left++) {
                int right = left + len;
                long long use = min(begin[left], end[right]);
                begin[left] -= use;
                end[right] -= use;
                ans = (ans + use * len * (len - 1) / 2) % mod;
            }
        }

        if (d) cout << prev << " " << ans << endl;

        printf("Case #%d: %lld\n", t, ((ans - prev) % mod + mod) % mod);
    }

    return 0;
}
