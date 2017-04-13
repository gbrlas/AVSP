#include <stdio.h>
#include <string.h>

int kase,kk;
int a[2000];
int n,mina,sum,res;

int main() {
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    scanf("%d",&kase);
    while (kase--) {
        scanf("%d",&n);
        mina=10000000;
        res=sum=0;
        for (int i=0;i<n;i++) {
            scanf("%d",&a[i]);
            if (mina>a[i]) mina=a[i];
            res^=a[i];
            sum+=a[i];
        }
        printf("Case #%d: ",++kk);
        if (res) printf("NO\n");
        else printf("%d\n",sum-mina);
    }
    return 0;
}
