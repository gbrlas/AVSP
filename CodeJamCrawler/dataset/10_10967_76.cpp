#include <stdio.h>
#include <string.h>

int kase,r,k,n;
int g[1100];

long long total;

int main()
{
    freopen("C-small.in","r",stdin);
    freopen("C-small.out","w",stdout);
    scanf("%d",&kase);
    for (int i=0;i<kase;i++) {
        scanf("%d%d%d",&r,&k,&n);
        for (int j=0;j<n;j++) scanf("%d",&g[j]);
        int curr=0,now,used;
        total=0;
        while (r--) {
            now=0;
            used=0;
            while (now+g[curr]<=k&&used<n) {
                now+=g[curr];
                curr++;
                used++;
                if (curr==n) curr=0;
            }
            total+=now;
        }
        printf("Case #%d: %lld\n",i+1,total);
    }
    return 0;
}
