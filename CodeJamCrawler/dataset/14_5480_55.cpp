#include<stdio.h>
int main()
{
    int i,j=1,k=0,count=0,t,n,m,l=0,x;
    int arr[4][4];
    int brr[4][4];
    scanf("%d",&t);
    while(j<=t)
    {
        scanf("%d",&n);
         for(x=0;x<4;x++)
        {
            scanf("%d %d %d %d",&arr[x][0],&arr[x][1],&arr[x][2],&arr[x][3]);
        }

        scanf("%d",&m);
         for(x=0;x<4;x++)
        {
             scanf("%d %d %d %d",&brr[x][0],&brr[x][1],&brr[x][2],&brr[x][3]);
        }

        while(l<4)
        {
            for(i=0;i<4;i++)
            {
               if(arr[n-1][i]==brr[m-1][l])
               {
                   count++;
                   k=arr[n-1][i];
               }

            }
            l++;
        }

        if(count==1)
        {
            printf("Case #%d: %d\n",j,k);
        }
        else if(count>1)
        {

            printf("Case #%d: Bad magician!\n",j);

        }
        else
            {
            printf("Case #%d: Volunteer cheated!\n",j);
            }
        count=0;
        l=0;
        j++;
    }
    return 0;
}
