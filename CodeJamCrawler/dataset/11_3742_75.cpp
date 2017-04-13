#include <cstdio>
#include <iostream>
using namespace std;
const int MXN = 1001;
int a[MXN];
int main () {
    freopen ("D-small-attempt1.in", "r", stdin);
    freopen ("out.txt", "w", stdout);
    int cn;
    int n;
    scanf ("%d", &cn);
    for (int ci = 0; ci < cn; ci ++) {
        scanf ("%d", &n);
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            scanf ("%d", &a[i]);
            if (a[i] != i + 1)
                 ans ++;
        }
        printf ("Case #%d: %d.000000\n", ci + 1, ans);
    }
    return 0;
}
