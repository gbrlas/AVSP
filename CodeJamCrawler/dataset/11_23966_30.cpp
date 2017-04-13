#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<string>
#include<math.h>
#include<vector>
#include<map>
#include<iostream>
using namespace std;
__int64 k1[50000],ans;
int main()
{
   // freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    int a,b,c,m,i,j,k,kk,n,p2;
    scanf("%d",&kk);
    for(int pp=1; pp<=kk; pp++)
    {
        ans=-10;
        scanf("%d %d %d",&n,&j,&k);
        for(i=1; i<=n; i++)
            scanf("%I64d",&k1[i]);
        for(__int64 p1=j; p1<=k; p1++)
        {

            for(p2=1; p2<=n; p2++)
            {
                if(!(((p1%k1[p2])==0)||((k1[p2]%p1)==0)))
                    break;
            }
            if(p2==n+1)
            {
                ans=p1;
                break;
            }
        }
        printf("Case #%d: ",pp);
        if(ans==-10)
          printf("NO\n");
        else
          printf("%d\n",ans);
    }
}
