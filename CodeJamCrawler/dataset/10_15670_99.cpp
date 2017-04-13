#include<iostream>
using namespace std;
int a[1000];
int gcd(int x, int y)
{
  if (!x || !y) return x > y ? x : y;
  for (int t; t = x % y; x = y, y = t);
  return y;
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int i,j,t,temp,ans,n;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        for(j=1;j<=n;j++)
        scanf("%d",&a[j]);
        sort(a+1,a+1+n);
        temp=a[n]-a[n-1];
        for(j=n-2;j>=1;j--)
        temp=gcd(temp,a[j+1]-a[j]);
        if(a[1]%temp==0) ans=0;
        else ans=temp-a[1]%temp;
        printf("Case #%d: %d\n",i,ans);
    }
}
