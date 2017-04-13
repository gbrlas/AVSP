#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<list>
#include<queue>
#include<vector>
using namespace std;
int a[10005];
int main()
{
    int t,ca=0;
    freopen("A-small-attempt1 (1).in","r",stdin);
    freopen("out.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i)
            scanf("%d",a+i);
        int ans=0;
        sort(a,a+n);
        int j=0;
        for(int i=n-1;i>=0;--i)
        {
            if(i<j)
                break;
            if(a[i]+a[j]<=m)
                j++;
            ans++;
        }
        printf("Case #%d: %d\n",++ca,ans);
    }
}
