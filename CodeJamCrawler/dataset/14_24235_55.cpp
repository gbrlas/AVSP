#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#define LOCAL
using namespace std;
int main()
{
#ifdef LOCAL
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // LOCAL
    int t = 0;
    scanf("%d", &t);
    double c, f, x;
    for(int cas = 1; cas <= t; cas++){
        scanf("%lf%lf%lf", &c, &f, &x);
        double ans = x / 2;
        double curT = c / 2, ct = 1;
        bool tag = 0;
        while(tag == 0){
            double tem = curT + x/(2+ct*f);
            if(ans > tem){
                ans = tem;
                curT += c / (2+ct*f);
                ct++;
            } else{
                tag = 1;
            }
        }
        printf("Case #%d: %lf\n", cas, ans);
    }

    return 0;
}
