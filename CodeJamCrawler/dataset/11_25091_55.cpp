#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,in,a[1005],ans,minn,sum;
int main()
{
        freopen("inC.txt","r",stdin);
        freopen("outC.txt","w",stdout);
        scanf("%d",&n);
        for(int k=0;k<n;k++)
        {
                scanf("%d",&in);
                ans=0;
                for(int i=0;i<in;i++)
                {
                        scanf("%d",&a[i]);
                        ans^=a[i];
                }
                printf("Case #%d: ",k+1);
                if(ans==0)
                {
                        minn=a[0];
                        sum=0;
                        for(int i=0;i<in;i++)
                        {
                                minn=min(minn,a[i]);
                                sum+=a[i];
                        }
                        printf("%d\n",sum-minn);
                }
                else
                {
                        printf("NO\n");
                }
        }
        //system("pause");
}
