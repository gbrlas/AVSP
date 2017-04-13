#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define MAXN 15
using namespace std;
int main()
{
freopen("C-small-attempt0.in","r",stdin);
freopen("out.txt","w",stdout);
    int ans,index,left,count,t,n,k,r,g[MAXN];
    scanf("%d",&t);
    for(int cases=1;cases<=t;cases++){
        scanf("%d%d%d",&r,&k,&n);
        for(int i=0;i<n;i++)
            scanf("%d",g+i);
        ans=0;
        index=0;
        while(r--){
            left=k;
            count=0;
            while(g[index%n]<=left&&count<n){
                ans+=g[index%n];
                left-=g[index%n];
                index++;
                count++;
            }
        }
        printf("Case #%d: %d\n",cases,ans);
    }
    return 0;
}
