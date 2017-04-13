#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    int cases=0;
    while(t--)
        {
            cases++;
            int row1;
            int arr1[4][4];
            scanf("%d",&row1);
            for(int i=0;i<4;i++)
                for(int j=0;j<4;j++)
                    {
                        scanf("%d",&arr1[i][j]);
                    }
            int row2;
            int arr2[4][4];
            scanf("%d",&row2);
            for(int i=0;i<4;i++)
                for(int j=0;j<4;j++)
                    {
                        scanf("%d",&arr2[i][j]);
                    }
            int answer=0;
            int count=0;
            row1--; row2--;
            for(int i=0;i<4;i++)
                {
                    for(int j=0;j<4;j++)
                        {
                            if(arr1[row1][i]==arr2[row2][j])
                                {
                                    count++;
                                    answer = arr1[row1][i];
                                }
                        }
                }
            if(count==1)
                printf("Case #%d: %d\n",cases,answer);
            else if(count>1)
                printf("Case #%d: Bad magician!\n",cases);
            else
                printf("Case #%d: Volunteer cheated!\n",cases);

        }
    return 0;
}
