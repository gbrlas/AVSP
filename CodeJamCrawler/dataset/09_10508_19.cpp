#include <stdio.h>
#include <string.h>

int map[10],map2[10];

int n,k;

int main()
{
    freopen("B-small-attempt3.in","r",stdin);
    freopen("B-small-attempt3.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d",&k);
        int k2=k;
        memset(map,0,sizeof(map));
        while (k>0) {
            map[k%10]++;
            k/=10;
        }
        for (int j=k2+1;j>0;j++) {
            memset(map2,0,sizeof(map2));
            int tp=j;
            while (tp>0) {
                map2[tp%10]++;
                tp/=10;
            }
            int l;
            for (l=1;l<10;l++) if (map[l]!=map2[l]) break;
            if (l==10) {
                printf("Case #%d: %d\n",i,j);
                break;
            }
        }
    }
    return 0;
}
