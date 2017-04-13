#include<iostream>
using namespace std;
int main()
{
    freopen("A-small-attempt3.in","r",stdin);
    freopen("A-small-attempt3.out","w",stdout);
    int t,r1,r2,i,j,a[5][5],b[5][5],x=1,cnt,ans;
    cin>>t;
    while(t--)
    {
        cin>>r1;
        for(i=1;i<5;i++)
        {
            for(j=1;j<5;j++)
            {
                cin>>a[i][j];
            }
        }
        cin>>r2;
        for(i=1;i<5;i++)
        {
            for(j=1;j<5;j++)
            {
                cin>>b[i][j];
            }
        }
        cnt = 0;
        for(i=1;i<5;i++)
        {
            for(j=1;j<5;j++)
            {
                if(a[r1][i]==b[r2][j])
                {
                    cnt++;
                    ans = a[r1][i];
                }
            }
        }
        if(cnt==1)
        {
            cout<<"Case #"<<x++<<": "<<ans<<endl;
        }
        else if(cnt==0)
        {
            cout<<"Case #"<<x++<<": Volunteer cheated!"<<endl;
        }
        else
        {
            cout<<"Case #"<<x++<<": Bad magician!"<<endl;
        }
    }
    return 0;
}
