#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    double C, F, X;
    int tasks; scanf("%d", &tasks);
    for (int cas = 1; cas <= tasks; ++cas) {
        scanf("%lf%lf%lf", &C, &F, &X);
        double rate = 2;
        double ans = X / rate;
        double spent = 0;
        int cnt  = 0;
        while (1) { 
            spent += (C / rate);
            rate += F;
            double tmp = spent + X / rate;
            if (tmp < ans) {
                ans = tmp;
                cnt = 0;
            } else
                if (cnt ++ > 10) 
                    break;
        }
        printf("Case #%d: %.7f\n", cas, ans);
    }
    return 0;
}


            


