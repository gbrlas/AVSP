#include <cstdio>
#include <iostream>
int main()
{
    //freopen("blas.in","r",stdin);
    //freopen("blas.txt","w",stdout);
    int t,cas;
    scanf("%d",&t);
    for(cas=1;cas<=t;cas++)
    {
        int a1,arr1[5][5];
        scanf("%d",&a1);
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                scanf("%d",&arr1[i][j]);
            }
        }
        int a2,arr2[5][5];
        scanf("%d",&a2);
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                scanf("%d",&arr2[i][j]);
            }
        }
        int ans,no=0;
        a1--;a2--;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(arr1[a1][i]==arr2[a2][j])
                {
                    ans=arr1[a1][i];
                    no++;
                }
            }
        }
        printf("Case #%d: ",cas);
        if(no==0)printf("Volunteer cheated!\n");
        else if(no==1)printf("%d\n",ans);
        else
        {
            printf("Bad magician!\n");
        }
    }
    return 0;
}
