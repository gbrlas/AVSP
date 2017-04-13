#include <iostream>
#include <cstdio>
using namespace std;

int t,n;
int c[100010];

int main(){
    freopen("C-small.in","r",stdin);
    freopen("C-small.out","w",stdout);
    scanf("%d",&t);
    int xsum,sum,mini;
    for (int ttt=1;ttt<=t;ttt++){
        scanf("%d",&n);
        sum=0;
        mini=1<<30;
        for (int i=0;i<n;i++){
            scanf("%d",&c[i]);
            sum+=c[i];
            if (c[i]<mini) mini=c[i];
        }
        xsum=0;
        for (int i=0;i<n;i++) xsum=xsum^c[i];
        if (xsum!=0){
            printf("Case #%d: NO\n",ttt);
            continue;
        }else{
            printf("Case #%d: %d\n",ttt,sum-mini);
        }
    }

    return 0;
}
