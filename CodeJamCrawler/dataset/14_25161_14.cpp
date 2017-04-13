#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
double deep,c,f,x,per,ans;
double dfs(double time, double perr)
{
    if(time > deep)return 99999999;
    double tmp1 = time + x / perr;
    deep = min(deep,tmp1);
    double tmp2 = time + c / perr;
    if(tmp1 < tmp2)return tmp1;
    tmp2 += dfs(tmp2, perr + f);
    ans = min(ans,min(tmp1,tmp2));
}
int main()
{
    //freopen("/home/zth/下载/B-small-attempt0.in","r",stdin);
    //freopen("/home/zth/下载/m.out","w",stdout);
    int T;
    cin >> T;
    for(int nu = 1; nu <= T; nu++)
    {
        scanf("%lf%lf%lf", &c, &f, &x);
        deep = x / 2;
        ans = deep;
        dfs(0, 2);
        printf("Case #%d: %.7lf\n",nu,ans);
    }
    return 0;
}
