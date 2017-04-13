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

#define N 1005
#define inf 0x7fffffff
#define eps 1e-8

int main(){
    freopen("a.txt","r",stdin);
    freopen("D:/gcj/d-large.out","w",stdout);
    int T,i,a[N],aa[N],cnt,n,cas=0;
    scanf("%d",&T);
    while (T--){
        cas++;
        scanf("%d",&n);
        for (i=1;i<=n;++i){
            scanf("%d",&a[i]);
            aa[i]=a[i];
        }
        sort(a+1,a+n+1);
        cnt=0;
        for (i=1;i<=n;++i){
            if (a[i]!=aa[i]) cnt++;
        }
        printf("Case #%d: %d.00000000\n",cas,cnt);
    }
    return 0;
}
