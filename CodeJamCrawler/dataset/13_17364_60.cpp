//source here
#include<cstdio>
#include<map>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;
int a[105][105];
int da[105][2];
int main()
{
   // freopen("B-large.in","r",stdin);
   // freopen("B.out","w",stdout);
    int t,n,m,f;
    scanf("%d",&t);
    for(int kk=1; kk<=t; ++kk)
    {
        printf("Case #%d: ",kk);
        //getchar();
        memset(da,0,sizeof(da));

        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j]>da[i][0])
                 da[i][0]=a[i][j];

                if(a[i][j]>da[j][1])
                 da[j][1]=a[i][j];

            }
        }
        f=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(a[i][j]<da[i][0]&&a[i][j]<da[j][1])
                {
                    f=1;break;
                }
            }
            if(f)break;
        }
        if(f)printf("NO\n");
        else
        printf("YES\n");
    }
    return 0;
}
