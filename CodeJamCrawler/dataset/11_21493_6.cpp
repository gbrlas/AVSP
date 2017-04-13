#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <cmath>

using namespace std;

#define N
#define inf 0x3f3f3f3f
#define eps 1e-8
#define LL long long

int main(){
    freopen("a.txt","r",stdin);
    freopen("D:/out.txt","w",stdout);
    int T,i,j,n,pd,pg,cas = 0;
    bool flag;
    scanf("%d",&T);
    while (T--){
        cas ++;
        scanf("%d%d%d",&n,&pd,&pg);
        flag  = 0;
        if (pd == 0){
            if (pg >= 0 && pg <= 99) {
                printf("Case #%d: Possible\n",cas);
            }
            else printf("Case #%d: Broken\n",cas);
            continue;
        }
        for (i = 1; i <= n; ++i){
            j = i * pd / 100;
            if (j * 100 / pd == i){
                flag = 1;
            }
        }
        if (flag){
            if (pd != 100){
                if (pg >= 1 && pg <= 99){
                    printf("Case #%d: Possible\n",cas);
                    continue;
                }
                else {
                    printf("Case #%d: Broken\n",cas);
                    continue;
                }
            }
            else {
                if (pg != 0) {
                    printf("Case #%d: Possible\n",cas);
                    continue;
                }
                else {
                    printf("Case #%d: Broken\n",cas);
                    continue;
                }
            }
        }
        else printf("Case #%d: Broken\n",cas);
    }
    return 0;
}
