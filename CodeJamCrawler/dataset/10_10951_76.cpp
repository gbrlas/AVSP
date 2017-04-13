#include <stdio.h>
#include <string.h>

int kase;
int res[50];
int n,k;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&kase);
    for (int i=0;i<kase;i++) {
        scanf("%d%d",&n,&k);
        while (n--) {
            if (k%2==0) break;
            k/=2;
        }
        if (n==-1) printf("Case #%d: ON\n",i+1);
        else printf("Case #%d: OFF\n",i+1);
    }
    return 0;
}
