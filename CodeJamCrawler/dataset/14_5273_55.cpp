#include<cstdio>
int main(){
    freopen("2014B-in.txt", "r", stdin);
    freopen("2014B-out.txt", "w", stdout);
    int nCases, _case = 1;
    double C, F, X, x, ans, tmp;
    scanf("%d", &nCases);
    while(_case <= nCases){
        scanf("%lf%lf%lf", &C, &F, &X);
        x = F*X/C-F;
        ans = 0;
        tmp = 2;
        while(tmp < x){
            ans += C/tmp;
            tmp+=F;
        }
        ans += X/tmp;
        printf("Case #%d: %.7lf\n", _case++, ans);
    }
    return 0;
}
