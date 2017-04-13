#include<iostream>
#include<stdio.h>
using namespace std;
int t,i,j,n,cnt,cs,ar[5],grd[5][5],res;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        cs++;
        scanf("%d",&n);
        for(i=1;i<=4;i++)
        {
            for(j=1;j<=4;j++)
            {
                scanf("%d",&grd[i][j]);
                if(i==n)
                ar[j]=grd[i][j];
            }
        }
        scanf("%d",&n);
        for(i=1;i<=4;i++)
        {
            for(j=1;j<=4;j++)
            {
                scanf("%d",&grd[i][j]);
            }
        }
        for(i=1;i<=4;i++)
        {
            for(j=1;j<=4;j++)
            {
                if(ar[i]==grd[n][j])
                {
                   cnt++;
                   res=ar[i];
                   break;
                }
            }
            if(cnt>1)
               break;
        }
        if(cnt==1)
        printf("Case #%d: %d\n",cs,res);
        else if(cnt<1)
        printf("Case #%d: Volunteer cheated!\n",cs);
        else
        printf("Case #%d: Bad magician!\n",cs);
    }
    return 0;
}
