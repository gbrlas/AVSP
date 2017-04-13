#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<iostream>
#include<map>
#include<vector>
#define MAXN 1000050
#define inf 1000000005
#define eps 0.0000001
using namespace std;
int n;
double d;
int p[MAXN],v[MAXN];
bool judge(double x)
{
    double tmp,last=-inf,next;
    for(int i=1;i<=n;i++){
        last+=d;
        last=max(last,p[i]-x);
        next=last+(v[i]-1)*d;
        if(p[i]+x+eps<next)
            return false;
        else
            last=next;
    }
    return true;
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int t,cas=0;
    double l,r,mid;
    scanf("%d",&t);
    while(t--){
        scanf("%d%lf",&n,&d);
        for(int i=1;i<=n;i++)
            scanf("%d%d",p+i,v+i);
        l=0;
        r=inf;
        while(l+eps<r){
            mid=(l+r)/2;
            if(judge(mid))
                r=mid;
            else
                l=mid;
        }
        printf("Case #%d: ",++cas);
        cout<<(l+r)/2<<endl;
    }
    //while(1);
    return 0;
}
