#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main () {
    freopen ("A-large.in", "r", stdin);
    freopen ("out.txt", "w", stdout);
    int cn;
    int n;
    int a;
    scanf ("%d", &cn);
    for (int ci = 0; ci < cn; ci ++) {
        scanf ("%d", &n);
        int ox = 1;
        int bx = 1;
        int ot = 0;
        int bt = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            char ch[10];
            int x;
            scanf ("%s%d", &ch, &x);
           // cout << ch[0] << ' ' << x << endl;
            if (ch[0] == 'O') {
                ans += 1 + max (0, abs (x - ox) - (ans - ot));
                ox = x;
                ot = ans;
            } else {
                ans += 1 + max (0, abs (x - bx) - (ans - bt));
                bx = x;
                bt = ans;
            }
        }
        printf ("Case #%d: %d\n", ci + 1, ans);
    }
    return 0;
}
