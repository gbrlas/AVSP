#include<iostream>
using namespace std;
int main()
{
    int j,k,tc,ans1,ans2,case1[4][4],case2[4][4],i=0;
    cin>>tc;
    while(i<tc)
    {
        cin>>ans1;
        for(j=0;j<4;j++)
            for(k=0;k<4;k++)
                cin>>case1[j][k];

        cin>>ans2;
        for(j=0;j<4;j++)
            for(k=0;k<4;k++)
                cin>>case2[j][k];

        int count=0,ans;
        for(j=0;j<4;j++)
        {
            for(k=0;k<4;k++)
            {
                if(case1[ans1-1][j]==case2[ans2-1][k])
                {
                    ans=case1[ans1-1][j];
                    count++;
                    cout<<count;
                }
            }
        }
        if(count==1)
            cout<<"Case #"<<i+1<<": "<<ans<<endl;
        else if(count==0)
            cout<<"Case #"<<i+1<<": Volunteer cheated!"<<endl;
        else
            cout<<"Case #"<<i+1<<": Bad magician!"<<endl;

       i++;
    }
}
