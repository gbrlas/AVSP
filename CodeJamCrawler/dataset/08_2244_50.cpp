#include <iostream>
#include <algorithm>
using namespace std;
double a[1010],b[1010],res;
int main()
{
    int cas,ca=1,n,i;
    freopen("in.txt","r",stdin);
    freopen("o.txt","w",stdout);
    cin>>cas;
    while(cas--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lf",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%lf",&b[i]);
        }
        sort(a,a+n);
        sort(b,b+n);
        res=0;
        for(i=0;i<n;i++)
        {
            res+=a[i]*b[n-1-i];
        }
        printf("Case #%d: %.0lf\n",ca++,res);
    }
    return 0;
}
