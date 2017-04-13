#include <cstdio>
#include <iostream>
using namespace std;
const int MXN = 2001;
int a[MXN];
int main () {
    freopen ("C-small-attempt0.in", "r", stdin);
    freopen ("out.txt", "w", stdout);
    int cn;
    int n, m, L, H;
    scanf ("%d", &cn);
    for (int ci = 0; ci < cn; ci ++) {
        int found = 0;
        scanf ("%d%d%d", &n, &L, &H);
        for (int i = 0; i < n; i++)
            scanf ("%d", &a[i]);
        for (int i = L; i <= H; i++) {
            int flag = 1;
            for (int j = 0; j < n; j++) {
                if (!(a[j] % i == 0 || i % a[j] == 0)) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                found = 1;
                printf ("Case #%d: %d\n", ci + 1, i);
                break;
            }
        }
        if (!found)
            printf ("Case #%d: NO\n", ci + 1);
    }
    return 0;
}
