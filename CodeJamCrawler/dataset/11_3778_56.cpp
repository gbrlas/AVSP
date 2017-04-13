#include <cstdio>
#include <iostream>
using namespace std;
const int MXN = 4001;

int X, S, R, N;
double t;
int l[MXN], r[MXN], w[MXN];
int len[MXN];
int v[MXN];
double p[MXN];
int n;

int main () {
    freopen ("A-small-attempt2.in", "r", stdin);
    freopen ("out.txt", "w", stdout);
    int cn;
    int n, m;
    scanf ("%d", &cn);
    for (int ci = 0; ci < cn; ci ++) {
        scanf ("%d%d%d%lf%d", &X, &S, &R, &t, &N);
        n = 0;
        int x = 0;
        double ans = 0;
        for (int i = 0; i < N; i ++) {
            scanf ("%d%d%d", &l[i], &r[i], &w[i]);
            if (l[i] - x > 0) {
                len [n] = l[i] - x;
                v [n] = 0;
                n ++;
            }
            if (r[i] - l[i] > 0) {
                len [n] = r[i] - l[i];
                v [n] = w[i];
                n ++;
            }
            x = r[i];
        }
        if (X - x > 0) {
            len [n] = X - x;
            v [n] = 0;
            n ++;
        }
        //for (int i = 0; i < n; i++)
            //cout << len[i] << ' ' << v[i] << endl;
        for (int i = n - 1; i >= 0; i --) {
            int k = 0;
            for (int j = 0; j <= i; j ++)
                if (v[j] < v[k])
                    k = j;
            //cout << v[k] << ' ' << len[k] << endl;
            double llen = len[k];
            double vv = R + v[k];
            //cout << ans << ' ' << t << endl;
            if (llen / vv <= t) {
                t -= llen / vv;
                ans += llen / vv;
            } else {
                if (t > 0) {
                    ans += t;
                    llen -= t * vv;
                    t = 0;
                }
                ans += llen / (double)(S + v[k]);
            }
            //cout << ans << ' ' << t << endl;
            v[k] = v[i];
            len[k] = len[i];
        }
        printf ("Case #%d: %.9lf\n", ci + 1, ans);
    }
    return 0;
}
