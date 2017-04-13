#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int kase,kk;
int a,b,num;

bool map[2000100];
int res[10],nn,p;
int chg[10];

void gen() {
    memset(chg,-1,sizeof(chg));
    for (int i=nn-1;i>=0;i--) {
        int tnum=0;
        for (int j=0;j<nn;j++) {
            tnum=tnum*10+res[(i-j+nn)%nn];
        }
        chg[i]=tnum;
    }
    sort(chg,chg+nn);
}

int main() {
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    scanf("%d",&kase);
    while (kase--) {
        scanf("%d%d",&a,&b);
        memset(map,false,sizeof map);
        num=0;
        for (int i=a;i<=b;i++) {
            nn=0;p=i;
            while (p>0) {
                res[nn++]=p%10;
                p/=10;
            }
            gen();
            for (int j=0;j<nn;j++) {
                if (chg[j]<=i||chg[j]>b||(j>0&&chg[j]==chg[j-1])) continue;
                num++;
            }
        }
        printf("Case #%d: %d\n",++kk,num);
    }
    return 0;
}
