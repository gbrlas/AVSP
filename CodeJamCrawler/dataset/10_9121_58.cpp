#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define MAXN 1050
using namespace std;
int t,n,ans,a[MAXN],b[MAXN];
int main()
{
    freopen("2010d.in","r",stdin);
    freopen("1010d.out","w",stdout);
    scanf("%d",&t);
    for(int k=1;k<=t;k++){
        scanf("%d",&n);
        ans=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d",a+i,b+i);
            for(int j=1;j<i;j++)
                if((a[i]-a[j])*(b[i]-b[j])<0)
                    ans++;
        }
        printf("Case #%d: %d\n",k,ans);
    }
    return 0;
}
