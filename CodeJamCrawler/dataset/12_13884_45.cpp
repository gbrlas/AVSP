#include<cstdio>
using namespace std;
int t,n,s,p,a[1000];
int main()
{
    int i,j,l,k,br;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        br=0;
        scanf("%d%d%d",&n,&s,&p);
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[j]);
            l=a[j]/3;
            if(a[j]%3)l++;
            if(l>=p)br++;
            else
            {
                if(s&&(l||a[j]%3==2))
                {
                    if(a[j]%3)l--;
                    l++;
                    if(a[j]%3==2)l++;
                    if(l>=p){br++;s--;}
                }
            }
        }
        printf("Case #%d: %d\n",i,br);
    }
}