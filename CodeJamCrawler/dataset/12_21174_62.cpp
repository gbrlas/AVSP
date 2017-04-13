#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

const int N=10000+6;

int a[N],b[N],f[N];


int main()
{
    freopen("in1.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int total,cc=0;
    scanf("%d",&total);
    while (total--)
    {
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
            scanf("%d %d",a+i,b+i);
        scanf("%d",a+n);
        b[n]=a[n];
        memset(f,-1,sizeof(f));
        f[0]=min(a[0],b[0]);
        for (int i=1;i<=n;i++)
            for (int j=i-1;j>=0;j--)
            {
                int len=a[i]-a[j];

                //can catch
                if (f[j]>=len )
                {
                    if (b[i]<=len)
                    {
                        f[i]=b[i];
                        break;
                    }
                    if (len>f[i]) f[i]=len;
                }
            }
        //for (int i=0;i<=n;i++)printf("%d ",f[i]);printf("\n");
        printf("Case #%d: ",++cc);
        if (f[n]>=0)
            printf("YES\n");
        else printf("NO\n");
    }
}