#include<stdio.h>
int main()
{
    int n,a1,a2,i=0,j=0,c=0,d=0,t;
    int a[4][4],b[4][4];
    scanf("%d",&n);
    int f[n],g[n];
    t=n;
    while(n>=1&&n<=100)
    {
        d=0;
        scanf("%d",&a1);
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        scanf("%d",&a2);
         for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                scanf("%d",&b[i][j]);
            }
        }
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
           {
               if(a[a1-1][i]==b[a2-1][j])
               {g[c]=b[a2-1][j];
                   d++;
                   }

           }
        }

f[c]=d;
 c++;
n--;
        }
int k=0;
        for(k=0;k<t;k++)
        {
            if(f[k]==1)
        {
            printf("Case #%d: %d\n",k+1,g[k]);
        }
        else if(f[k]>=2)
        {
            printf("Case #%d: Bad magician!\n",k+1);
        }
        else
        {
            printf("Case #%d: Volunteer cheated!\n",k+1);
        }
    }
   return 0;
}

