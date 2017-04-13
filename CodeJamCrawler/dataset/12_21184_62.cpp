#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int N=2000+5;

int fa[N],k[N],h[N];
int n,sta[N],top;
int main()
{
    freopen("in2.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int total,cc=0;
    cin>>total;
    while (total--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<n;i++)
            scanf("%d",fa+i);
        k[n]=0;
        sta[top=0]=n;
        memset(k,0,sizeof(k));
        bool ok=true;
        for (int i=n-1;i>=1;i--)
        {
            while (fa[i]>sta[top])
            {
                int u=sta[top];
                for (int j=i+1;j<u;j++)
                    k[j]++;
                top--;
            }
            if (sta[top]!=fa[i]){ok=false;break;}
            for (int j=i+1;j<fa[i];j++)
                k[j]++;
            sta[++top]=i;
        }

        if (!ok)
        {
            printf("Case #%d: Impossible\n",++cc);
            continue;
        }

        while (top>=0)
        {
            int u=sta[top];
            for (int j=1;j<u;j++)
                k[j]++;
            top--;
        }

        int loo=0;
        h[n]=0;
        for (int i=n-1;i>=1;i--)
        {
            h[i]=h[fa[i]]-k[i]*(fa[i]-i);
            loo=min(loo,h[i]);
        }
        printf("Case #%d:",++cc);
        for (int i=1;i<=n;i++)
            printf(" %d",h[i]-loo+1);
        printf("\n");
    }
}