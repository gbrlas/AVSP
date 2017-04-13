#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAXN 1050
using namespace std;
int n,a[MAXN],b[MAXN];
int main()
{
    freopen("D-small-attempt0.in","r",stdin);
    freopen("D-small-attempt0.out","w",stdout);
    int t,cas=0;
    double ans;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",a+i);
            b[i]=a[i];
        }
        sort(b+1,b+n+1);
        ans=0;
        for(int i=1;i<=n;i++)
            if(a[i]^b[i])
                ans+=1;
        printf("Case #%d: %.6f\n",++cas,ans);
    }
    //while(1);
    return 0;
}
