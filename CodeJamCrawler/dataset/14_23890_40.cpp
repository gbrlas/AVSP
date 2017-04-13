#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

int T, N;
int arr[MAXN];
int team[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);

    cin>>T;
    for(int t=1; t<=T; t++)
    {
        cin>>N;
        for(int i=0; i<N; i++)
            cin>>arr[i];

        for(int i=0; i<N; i++)
        {
            team[i] = 1;
        }

        int swapcnt = 0;
        while(true)
        {
            swapcnt++;
            bool sw = false;

            for(int i=0; i<N; i++)
            {
                int cost1 = 0, cost2 = 0;
                for(int j=0; j<N; j++)
                {
                    if((team[j]==1 && (j-i)*(arr[j]-arr[i])<0) || (team[j]==2 && j<i))cost1++;
                    if((team[j]==2 && (j-i)*(arr[j]-arr[i])>0) || (team[j]==1 && j>i))cost2++;
                }
                int newteam = 1;
                if(cost2 < cost1)newteam = 2;
                if(newteam != team[i])
                {
                    team[i] = newteam;
                    sw = true;
                }
            }
            if(!sw)break;
        }

        int minans = 11111111;

        for(int a=0; a<(1<<N); a++)
        {
            for(int b=0; b<N; b++)
            {
                team[b] = (a&(1<<b) ? 1 : 2);
            }
        int ans = 0;
        for(int i=0; i<N; i++)
        {
            for(int j=i+1; j<N; j++)
            {
                if(team[i]==2 && team[j]==1)ans++;
                if(team[i]==1 && team[j]==1 && arr[i]>arr[j])ans++;
                if(team[i]==2 && team[j]==2 && arr[i]<arr[j])ans++;
            }
        }
        minans = min(ans, minans);
        }

        // cout<<swapcnt<<endl;
        // for(int i=0; i<N; i++)cout<<team[i]<<" ";cout<<endl;
        cout<<"Case #"<<t<<": "<<minans<<endl;
    }

    return 0;
}
