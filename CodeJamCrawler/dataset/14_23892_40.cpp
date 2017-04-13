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

        for(int i=0; i<N; i++)
        {
            int lg = 0, rg = 0;
            for(int j=0; j<N; j++)
            {
                if(arr[j] > arr[i])
                {
                    if(j<i)lg++;
                    if(j>i)rg++;
                }
            }
            if(lg < rg)team[i] = 1;
            else team[i] = 2;

        }

        int minans = 11111111;

        // for(int a=0; a<(1<<N); a++)
        // {
            // for(int b=0; b<N; b++)
            // {
                // team[b] = (a&(1<<b) ? 1 : 2);
            // }
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
        // }

        // cout<<swapcnt<<endl;
        // for(int i=0; i<N; i++)cout<<team[i]<<" ";cout<<endl;
        cout<<"Case #"<<t<<": "<<minans<<endl;
    }

    return 0;
}
