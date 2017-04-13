#include<stdio.h>

void main()
{
    int t,a1,a2,i,j,ctr=0,ans,r=1;
    int m[4][4],n[4][4];

    scanf("%d",&t);
    while(t--)
    {
        ctr=0;
        scanf("%d",&a1);
        for(i=0;i<4;i++)
        {
            for(j=0;j<=3;j++)
            {
                scanf("%d",&m[i][j]);
            }
        }
        scanf("%d",&a2);
        for(i=0;i<4;i++)
        {
            for(j=0;j<=3;j++)
            {
                scanf("%d",&n[i][j]);
            }
            printf("\n");
        }
        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
            {
                if(m[a1-1][i]==n[a2-1][j])
                {
                    ctr++;
                    ans=n[a2-1][j];
                }
            }
        if(ctr==1)
            printf("Case #%d: %d",r,ans);
        else if(ctr==0)
            printf("Case #%d: Volunteer cheated!",r);
        else
            printf("Case #%d: Bad magician!",r);

        r++;
    }

}
