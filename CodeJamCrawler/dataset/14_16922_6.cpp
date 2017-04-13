#include<stdio.h>
#include<stdlib.h>
int main()
{
    freopen("A-small-attempt2.in","r",stdin);
    freopen("output21.out","w",stdout);
    int t,a,b,ar1[4][4],ar2[4][4],i,j,k,count,res;
    scanf("%d",&t);
    k=0;
    while(t--)
    {
        k++;
        count=0;
        res=0;
        scanf("%d",&a);

        for(i=0;i<4;i++){
        for(j=0;j<4;j++)
            scanf("%d",&ar1[i][j]);
        }
        scanf("%d",&b);

        for(i=0;i<4;i++){
        for(j=0;j<4;j++)
            scanf("%d",&ar2[i][j]);
        }


        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(ar1[a-1][i]==ar2[b-1][j])
                {
                    count++;
                    res=ar1[a-1][i];
                    break;
                }
            }
        }
        if(count==1)
            printf("Case #%d: %d\n",k,res);
        if(count>1)
            printf("Case #%d: Bad magician!\n",k);
        if(count==0)
            printf("Case #%d: Volunteer cheated!\n",k);

    }
    return 0;
}
