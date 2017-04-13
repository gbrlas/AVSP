#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);

    int cas = 1;
    while(t--)
    {
        int r1,r2;
        int grid1[5][5],grid2[5][5];
        int ans1[5],ans2[5];

        scanf("%d",&r1);
        int i,j;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
              scanf("%d",&grid1[i][j]);
              if(i+1==r1)
                ans1[j]=grid1[i][j];
            }
        }
        
        scanf("%d",&r2);
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
              scanf("%d",&grid2[i][j]);
              if(i+1==r2)
                ans2[j]=grid2[i][j];
            }
        }
        int cnt = 0;
        int ans = -1;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(ans1[i]==ans2[j])
                {
                    cnt++;
                    ans=ans1[i];
                
                }

            
            }
        
        }
        cout<<"Case #"<<cas<<": ";
        if(cnt>1)
          cout<<"Bad magician!"<<endl;
        else if(cnt==1)
          cout<<ans<<endl;
        else
          cout<<"Volunteer cheated!"<<endl;
        cas++;
    }

}
