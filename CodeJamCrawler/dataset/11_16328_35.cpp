#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

const int MAX=120;
const int oo=1e8;

int kk;
int kase;
int d,c;
int a[MAX][2];
double pos[MAX];
int sum;
double left,right,mid;

bool solve(double ans) {
    int l=0;
    double last=-oo,ll;
    for (int i=0;i<d;i++) {
        ll=a[i][0]-ans;
        if (ll<last+c) ll=last+c;
        ll+=(a[i][1]-1)*c;
        if (fabs(ll-a[i][0])>ans) return false;
        last=ll;
    }
    return true;
}

int main() {
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B.out","w",stdout);
    scanf("%d",&kase);
    while (kase--) {
        scanf("%d%d",&d,&c);
        sum=0;
        for (int i=0;i<d;i++) {
            scanf("%d%d",&a[i][0],&a[i][1]);
            sum+=a[i][1];
        }
        left=0,right=oo;
        while (right-left>1e-8) {
            mid=(left+right)/2;
            if (solve(mid)) right=mid;
            else left=mid;
        }
        printf("Case #%d: %.9f\n",++kk,left);
    }
    return 0;
}
