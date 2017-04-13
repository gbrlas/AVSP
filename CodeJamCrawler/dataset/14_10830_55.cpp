#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream cin("A-small-attempt0.in");
    ofstream cout("a.out");
    long num_case; cin>>num_case;
    for(long i_case = 1; i_case <= num_case; i_case++)
    {
        cout<<"Case #"<<i_case<<": ";
        long ans1,ans2,card1[5][5],card2[5][5];
        cin>>ans1;
        for(long i = 1; i <= 4; i++)
            for(long j = 1; j <= 4; j++)
                cin>>card1[i][j];
        cin>>ans2;
        for(long i = 1; i <= 4; i++)
            for(long j = 1; j <= 4; j++)
                cin>>card2[i][j];
        long cnt = 0,ans;
        for(long i = 1; i <= 4; i++)
        {
            for(long j = 1; j <= 4; j++)
                if(card1[ans1][i] == card2[ans2][j])
                {
                    cnt++;         
                    ans = card1[ans1][i];
                }
        }         
        if(0 == cnt)
            cout<<"Volunteer cheated!";
        if(1 == cnt)
            cout<<ans;
        if(cnt > 1)
            cout<<"Bad magician!";
        cout<<endl;
    }
    cin.close(); cout.close();
    return 0;
}
