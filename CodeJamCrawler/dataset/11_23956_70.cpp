#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
   // freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    int a,b,c,m,i,j,k,n,min1,sum;
    scanf("%d",&m);
    for(int kk=1; kk<=m; kk++)
    {
        scanf("%d",&n);
        scanf("%d",&a);
        sum=0;
        sum+=a;
        min1=0x7fffffff;
        if(a<min1)
            min1=a;
        for(i=2; i<=n; i++)
        {
            scanf("%d",&b);
            a=a^b;
            if(b<min1)
                min1=b;
            sum+=b;
        }
        if(a!=0)
            printf("Case #%d: NO\n",kk);
        else
            printf("Case #%d: %d\n",kk,sum-min1);
    }
}
