#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
double a[1005],b[1005];
int main()
{
    freopen("D-small-attempt0.in","r",stdin);
    freopen("D-small-attempt0.out","w",stdout);
    int i,j,t,n,g=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%lf",&a[i]);
        sort(a,a+n);
        for(i=0;i<n;i++)
            scanf("%lf",&b[i]);
        sort(b,b+n);
        j=0;
        int countx=0,countxx=0;
        for(i=0;i<n&&j<n;i++)
        {
            while(b[j]<a[i]&&j<n)
                j++;
            if(j>=n) break;
            countx++;
            j++;
        }
        countx=n-countx;
        j=0;
        int last=n-1;
        for(i=0;i<=last&&j<n;i++)
        {
            while(a[j]<b[i]&&i<=last&&j<n)
            {
                last--;
                j++;
            }
            if(i>last||j>=n) break;
            countxx++;
            j++;
        }
        printf("Case #%d: ",g++);
        printf("%d %d\n",countxx,countx);
    }
    return 0;
}
