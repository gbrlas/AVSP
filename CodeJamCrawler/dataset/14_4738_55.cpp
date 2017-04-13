#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

double a[1111],b[1111];
int n;
bool cmp(double x,double y)
{
    return x<y;
}
int main()
{
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for (int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%lf",&a[i]);
        for (int i=1;i<=n;i++) scanf("%lf",&b[i]);
        sort(a+1,a+1+n,cmp);
        sort(b+1,b+1+n,cmp);
        /*for (int i=1;i<=n;i++) printf("%.3f ",a[i]);
        puts("");
        for (int i=1;i<=n;i++) printf("%.3f ",b[i]);*/
        int l1,r1,l2,r2,s1,s2;
        l1=l2=1;
        r1=r2=n;
        s1=s2=0;
        while (l1<=r1)
        {
            if (a[l1]<b[l2])
            {
                l1++;
                r2--;
            }
            else
            {
                l1++;
                l2++;
                s1++;
            }
        }
        l1=l2=1;
        r1=r2=n;
        while (l1<=r1)
        {
            if (a[r1]>b[r2])
            {
                r1--;
                l2++;
                s2++;
            }
            else
            {
                r1--;
                r2--;
            }
        }
        printf("Case #%d: %d %d\n",cas,s1,s2);
    }
    return 0;
}
