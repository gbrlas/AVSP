#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    int T, t;
    double c, f, x, p;
    double ans, tm;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%lf %lf %lf", &c, &f, &x);
        p = 2;
        ans = x/p, tm = 0;
        while (ans > tm + c/p + x/(p+f)) {
            ans = tm + c/p + x/(p+f);
            tm += c/p;
            p += f;
        }
        printf("Case #%d: %.7lf\n", t, ans);
    }
    return 0;
}
