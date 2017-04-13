#include<stdio.h>
#include<stdlib.h>
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t,n,m,a[101][101],i,j,k,temp,b[101][101],flag;


    scanf("%d",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                scanf("%d",&a[i][j]);
                b[i][j]=100;
            }
        for(i=1;i<=n;i++)
        {
            temp=0;
            for(j=1;j<=m;j++)
            {
                if(a[i][j]>temp)
                    temp=a[i][j];
            }
            for(j=1;j<=m;j++)
                b[i][j]=temp;
        }
        flag=0;
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(a[j][i]!=b[j][i])
                    break;
            }
            if(j!=n+1)
            {
                temp=a[1][i];
                for(j=2;j<=n;j++)
                {
                    if(a[j][i]!=temp)
                    {
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==1)
                break;


        }
        if(flag==0)
            printf("Case #%d: YES\n",k);
        else
            printf("Case #%d: NO\n",k);


    }
    return 0;
}
