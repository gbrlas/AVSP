#include<cstdio>
#include<cstring>
#include<cmath>
int a[10010];
int main()
{
        freopen("2.in","r",stdin);
        freopen("2.out","w",stdout);
    int cas;
    scanf("%d",&cas);
    for(int g=1;g<=cas;g++)
    {
        

        int n,p,s;
        scanf("%d%d%d",&n,&s,&p);
        for(int j=1;j<=n;j++)
            scanf("%d",&a[j]);
        int l=0,ans=0,sum=0;
        for(int i=1;i<=n;i++)
        { //printf("#%d %d\n",i,a[i]);
            if(a[i]<2)
            {
                if(a[i]>=p) ans++;
            }
            else
            {
                int b=a[i]%3,c=a[i]/3;
               // printf("$%d %d %d\n",b,c,p);
                if( c+(b>0) >= p)
                {
                    ans++;
                    l++;
                }
                else
                    if(c+1+(b>1)>=p)
                        sum++;
                    else
                        l++;
            }
        }
        if(sum+l<s)
            printf("Case #%d: %d\n",g,0);
        else
        {
            if(sum<s)
                ans+=sum;
            else
                ans+=s;
            printf("Case #%d: %d\n",g,ans);
        }




    }
    return 0;
}