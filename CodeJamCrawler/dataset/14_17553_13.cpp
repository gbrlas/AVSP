#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
#include<set>
#include<algorithm>
#include<map>
#define eps 1e-20
#define ll long long

using namespace std;

int t,n;
int s[10100];
int ans,m;
int main()
{
    //cout<<5000*5000;
    freopen("A-large.in","r",stdin);
    freopen("a.out","w",stdout);

   scanf("%d",&t);
   int __=0;
   while(t--){
        ans=0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i)
            scanf("%d",&s[i]);

        sort(s,s+n);
        int i=0,j=n-1;
        while(1)
        {
            if(s[i]+s[j]<=m)
            {
                j--;i++;
                ans++;
            }
            else
            {
                ans++;j--;
            }
            if(j==i){ans++;break;}
            if(j<i)break;
        }
        printf("Case #%d: %d\n",++__,ans);
   }
    return 0;
}
/*

*/
