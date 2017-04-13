#include <cstdio>
#include <iostream>
using namespace std;
const int MXN = 2001;
long long a[MXN];
long long s[MXN];
long long c[MXN];
int n, m;
int L, t, N, C;
struct data {
    int x, c;
};
data d[MXN];
int cmp (data a, data b) {
    return a.x > b.x;
}

int main () {
    freopen ("B-small-attempt1.in", "r", stdin);
    freopen ("out.txt", "w", stdout);
    int cn;
    int n, m;
    scanf ("%d", &cn);
    for (int ci = 0; ci < cn; ci ++) {
        long long ans = 0;
        scanf ("%d%lld%d%d", &L, &t, &N, &C);
        memset (s, 0, sizeof(s));
        memset (c, 0, sizeof(c));
        for (int i = 0; i < C; i++) {
            scanf ("%lld", &a[i]);
            s[i + 1] = s[i] + a[i];
        }
        while (N) {
            if (N < C)
                C = N;
            if (ans + s[C] * 2 < t) {
                ans += s[C] * 2;
                N -= C;
            } else {
                int k = 0;
                for (int i = 0; i < C; i++) {
                    if (ans + s[i + 1] * 2 > t) {
                        k = i;
                        ans += s[i] * 2;
                        break;
                    }
                }
                //cout << N << ' ' << k << endl;
                for (int i = 0; i < C; i++) {
                    c[i] += N / C - 1;
                }
                for (int i = k + 1; i < C; i++) {
                    c[i] ++;
                }
                for (int i = 0; i < N % C; i++) {
                    c[i] ++;
                }
                for (int i = 0; i < C; i++) {
                    d[i].x = a[i];
                    d[i].c = c[i];
                }
                //cout << ans << endl;
                d[C].x = a[k] - (t - ans) / 2;
                d[C].c = 1;
                ans = t;
                sort (d, d + C + 1, cmp);
                for (int i = 0; i <= C; i++) {
                    //cout << '*' << d[i].x << ' ' << d[i].c << endl;
                }
                for (int i = 0; i <= C; i++) {
                    if (L >= d[i].c) {
                        L -= d[i].c;
                        ans += d[i].x * d[i].c;
                    } else if (L > 0) {
                        ans += d[i].x * L + d[i].x * (d[i].c - L) * 2;
                        L = 0;
                    } else {
                        ans += d[i].x * d[i].c * 2;
                    }
                   // cout << ans << endl;
                }
                /*
                for (int i = 0; i < C; i++)
                    printf ("%lld ", c[i]);
                printf ("\n");
                */
                break;
            }
        }
        printf ("Case #%d: %lld\n", ci + 1, ans);
    }
    return 0;
}
