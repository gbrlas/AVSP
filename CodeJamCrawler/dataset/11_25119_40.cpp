#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int t,n,L,H,a[105];
bool mark;
bool check(int h)
{
        for(int i=0;i<n;i++)
        {
                if(h%a[i]!=0 && a[i]%h!=0)
                {
                        return 0;
                }
        }
        return 1;
}
int main()
{
        freopen("inC.txt","r",stdin);
        freopen("outC.txt","w",stdout);
        scanf("%d",&t);
        for(int rr=1;rr<=t;rr++)
        {
                scanf("%d %d %d",&n,&L,&H);
                for(int i=0;i<n;i++)
                {
                        scanf("%d",&a[i]);
                }
                mark=0;
                printf("Case #%d: ",rr);
                for(int i=L;i<=H;i++)
                {
                        if(check(i))
                        {
                                printf("%d\n",i);
                                mark=1;
                                break;
                        }
                }
                if(!mark)
                {
                        printf("NO\n");
                }
        }
        //system("pause");
}
