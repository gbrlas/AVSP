#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int MXN = 1001005;

int R, C, D;
int p[MXN];
long long a[MXN];
int n;
int ans;
long long N;

int main () {
    freopen ("C-small-attempt0.in", "r", stdin);
    freopen ("out.txt", "w", stdout);
    int cn;
    scanf ("%d", &cn);
    memset (p, sizeof(p), 0);
    for (int i = 2; i < sqrt (MXN); i ++)
        if (!p[i])
            for (int j = i * i; j < MXN; j += i)
                p[j] = 1;
    int n = 0;
    for (int i = 2; i < MXN; i ++)
        if (!p[i]) {
            a[n] = i;
            n++;
        }
    for (int ci = 0; ci < cn; ci ++) {
        scanf ("%lld", &N);
        //cout << N << endl;
        int i = 0;
        long long ans = N > 1;
        while (a[i] < sqrt(N) + 1) {
            if (a[i] > N)
                break;
            long long k = 0;
            long long t = a[i];
            while (t <= N) {
                t *= a[i];
                k ++;
            }
            ans += k - 1;
            //cout << a[i] << ' ' << k << endl;
            i ++;
        }
        printf ("Case #%d: %lld\n", ci + 1, ans);
    }
    return 0;
}
