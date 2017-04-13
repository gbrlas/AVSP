#include<cstdio>
using namespace std;
main()
{
      int tc;
      scanf("%d",&tc);
      int k=1;
      while(tc--)
      {
        int m1[4][4],m2[4][4],ans1,ans2;
        scanf("%d",&ans1);
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            scanf("%d",&m1[i][j]);
        } 
           scanf("%d",&ans2);
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            scanf("%d",&m2[i][j]);
        }         
       // int ans1,ans2;
     
        ans1--;
        ans2--;
        int count =0,u;
        for(int i=0;i<4;i++)
        {
           for(int j=0;j<4;j++)
           {
                   if(m1[ans1][i]==m2[ans2][j])
                   {
                      u=m1[ans1][i];
                      count++;
                   }
           }
        }
        if(count==1)
        printf("Case #%d: %d\n",k,u);
        else if(count==0)
        printf("Case #%d: Volunteer cheated!\n",k);
        else if(count>1)
        printf("Case #%d: Bad magician!\n",k);
        k++;
      }
}

