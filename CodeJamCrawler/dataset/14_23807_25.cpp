#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include <stack>
#include <set>
using namespace std;
typedef long long LL;
const int maxn = 100 + 5;
const int INF = 1000000000 + 7;

int main(){
    freopen("B-large.in", "r", stdin);
    freopen("out", "w", stdout);
    int t,kase = 0;
    scanf("%d",&t);
    while(t--){
        kase++;
        double c,f,total;
        scanf("%lf%lf%lf",&c, &f, &total);
        double ans = total / 2;
        double farm = 0;
        for(int i = 1;i < 100000;i++){
            double tem = total/(i*f+2);
            farm += c/(2+(i-1)*f);
            tem += farm;
            if(tem > ans) break;
            ans = tem;
        }
        printf("Case #%d: %.7lf\n",kase,ans);
    }
    return 0;
}





