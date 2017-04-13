#include<iostream>
using namespace std;
int a[1050],b[1050];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);

    int t,i,j,k,n;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
         scanf("%d%d",&a[j],&b[j]);
        int ans=0;
        for(j=0;j<n-1;j++)
         for(k=j+1;k<n;k++)
        if((a[k]<a[j] && b[k]>b[j])||(a[k]>a[j]&& b[k]<b[j])) ans++;
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}
