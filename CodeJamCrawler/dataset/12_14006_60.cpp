#include <stdio.h>
#include <string.h>

int kase,kk;
int n,s,p,t,tp;

int main() {
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    scanf("%d",&kase);
    while (kase--) {
        scanf("%d%d%d",&n,&s,&p);
        int num=0;
        for (int i=0;i<n;i++) {
            scanf("%d",&t);
            tp=t/3;
            t%=3;
            if (tp>=p) num++;
            else {
                if (t==0&&tp==p-1&&tp>0&&s>0) s--,num++;
                else if (t==1&&tp==p-1) num++;
                else if (t==2&&tp==p-1) num++;
                else if (t==2&&tp==p-2&&s>0) s--,num++;
            }
        }
        printf("Case #%d: %d\n",++kk,num);
    }
    return 0;
}
