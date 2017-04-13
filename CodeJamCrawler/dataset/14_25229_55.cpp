#include<stdio.h>

int main()
{
    int T,i,j,iter=1;
    scanf("%d",&T);

    while(iter <=  T)
    {   int ans1,ans2,arr1[4][4],arr2[4][4],match_count=0,match_pos=0;
        scanf("%d",&ans1);
        for (i=0;i<4;i++)
        {
            for (j=0;j<4;j++)
                scanf("%d",&arr1[i][j]);
        }

        scanf("%d",&ans2);
        for (i=0;i<4;i++)
        {
            for (j=0;j<4;j++)
                scanf("%d",&arr2[i][j]);
        }

        for (i=0;i<4;i++)
        {
            for (j=0;j<4;j++)
            {
                if (arr1[ans1-1][i] == arr2[ans2-1][j])
                {
                    match_count++;
                    match_pos = i;
                }
            }
        }

        if (match_count > 1)
            printf("Case #%d: Bad magician!\n",iter);
        else if (match_count == 0)
            printf("Case #%d: Volunteer cheated!\n",iter);
        else
            printf("Case #%d: %d\n",iter,arr1[ans1-1][match_pos]);

        iter++;
    }
}
