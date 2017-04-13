#include<iostream>
using namespace std;
int used[1010],g[1010];
long long s[1005];
int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    int t,tt,i,j,l,x,r,k,n,h;
    long long ans,sum,S;
    scanf("%d",&t);
    for(tt=1;tt<=t;tt++)
    {
        scanf("%d%d%d",&r,&k,&n);
        S=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&g[i]);
            S+=g[i];
        }
        if(S<=k)
        {
            ans=r*S;
            printf("Case #%d: %lld\n",tt,ans);
            continue;
        }
        memset(used,0,sizeof(used));
        j=0;x=0;ans=0;
        memset(s,0,sizeof(s));
        while(r>0)
        {
            if(used[j]>0) break;
            x++;used[j]=x;
            sum=0;
            for(l=j;;l=(l+1)%n)
            {
                if(sum+g[l]<=k) sum+=g[l];
                else break;
            }
            s[x]=s[x-1]+sum;
            ans+=sum;r--;
            j=l;
        }
        if(r>0)
        {
            int kk=r/(x-used[j]+1);
            ans+=kk*(s[x]-s[used[j]-1]);
            r%=(x-used[j]+1);
            while(r--)
            {
                sum=0;
                for(l=j;;l=(l+1)%n)
                if(sum+g[l]<=k) sum+=g[l];
                else break;
                ans+=sum;
                j=l;
            }
        }
        printf("Case #%d: %lld\n",tt,ans);
    }
}
