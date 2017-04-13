#include <bits/stdc++.h>
using namespace std;

int T;
double c, f, x, cur;

int main() {
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        cur = 2;
        scanf("%lf%lf%lf", &c, &f, &x);
        double time = c/cur;
        while ((x-c)/cur > x/(cur+f)) {
            cur += f;
            time += c/cur;
        }
        time += (x-c)/cur;
        printf("Case #%d: %.7f\n", t, time); 
    }
    return 0;
}
