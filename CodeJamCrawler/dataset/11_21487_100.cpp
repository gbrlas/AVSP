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

#define N 1010
#define inf 0x7fffffff
#define eps 1e-8

int main(){
    freopen("a.txt","r",stdin);
    freopen("D:/gcj/c-large.out","w",stdout);
    int a,T,cas=0,i,n,sum,bsum,small;
    scanf("%d",&T);
    while (T--){
        cas++;
        sum=0;
        bsum=0;
        small=inf;
        scanf("%d",&n);
        for (i=1;i<=n;++i){
            scanf("%d",&a);
            sum+=a;
            if (a<small) small=a;
            bsum=bsum^a;
        }
        if (bsum){
            printf("Case #%d: NO\n",cas);
        }
        else{
            printf("Case #%d: %d\n",cas,sum-small);
        }
    }
    return 0;
}
