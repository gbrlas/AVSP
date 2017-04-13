#include <stdio.h>
#define esp 10e-8

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d", &T);
    int cnt = 1;
    double c,f,x;
    double ans;
    double tmp;
    double now;
    double nowin;
    bool flag;
    while(T--){
        scanf("%lf %lf %lf", &c, &f, &x);
        ans = x / 2.0;
        flag = true;
        now = 0;
        nowin = 2.0;
        while(flag){
            flag = false;
            now += c / nowin;
            nowin += f;
            tmp = now + x / nowin;
            if(ans - tmp > esp){
                flag = true;
                ans = tmp;
            }
        }
        printf("Case #%d: %.7f\n", cnt++, ans);
    }
    return 0;
}
