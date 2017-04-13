#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;

int team[1024];
int nextTeam[1024];

void Game(int t[], int nxtT[], int n)
{
    if(n==1) return;
    for(int i=0; i<n; ++i)
    nxtT[i] = t[i];

    for(int i=0, j=n/2; i<n; i+=2, j++)
    {
        t[i/2] = min(nxtT[i], nxtT[i+1]);
        t[j] = max(nxtT[i], nxtT[i+1]);
    }
    Game(t, nxtT, n/2);
    Game(t+n/2, nxtT+n/2, n/2);
}

void test(int N, int P)
{
    bool isWin[1025];
    int reserveTeam[1025];
    for(int i=0; i<(1<<N); ++i)
    {
        isWin[i] = true;
        reserveTeam[i] = i;
    }

    int maxTeam = -1;
    do
    {
        for(int i=0; i<(1<<N); ++i)
            team[i] = reserveTeam[i];

        Game(team, nextTeam, (1<<N));

//        for(int i=0; i<(1<<N); ++i)
//            cout << team[i] << " ";
//        cout << endl;

        for(int i=0; i<P; ++i)
            maxTeam = max(maxTeam, team[i]);

        for(int i=P; i<(1<<N); ++i)
        {
            isWin[ team[i] ] = false;
        }
    }while(next_permutation(reserveTeam, reserveTeam+(1<<N)));

    for(int i=0; i<(1<<N); ++i)
        if(!isWin[i]) {
            cout << N <<" " << P << " Garanteed " << i-1;
            break;
        }
    cout << "   max " << maxTeam << endl;
}

int main()
{
    freopen("B2.in", "r", stdin);
    freopen("B2.out", "w", stdout);
//    for(int i=1; i<10; ++i)
//    {
//        for(int p=1; p<=(1<<i); ++p)
//            test(i, p);
//        cout << endl;
//    }

    int T;
    cin>>T;

    for(int ca=1; ca<=T; ++ca)
    {
        int N;
        long long P;
        cin>>N>>P;
        long long r1, r2;
        r1 = 0;

        long long s1 = 0 ;
        long long ans1 = 0, ans2 = 0;
        long long curP = P;
        long long curN = (1LL<<(N-1));

        if(curP == (1LL<<N)) ans1 = ans2 = curP-1;
        else{
            while( (curP-=curN) > 0)
            {
                ++s1;
                ans1 += (1LL<<s1);
                curN>>=1;
            }
            int m = 1;
            int p = N-1;
            while((1LL<<m) <= P)
            {
                m++;
                ans2 += (1LL<<p);
                --p;
            }
        }
        cout << "Case #" << ca <<": " << ans1 << " "<< ans2 << endl;
    }

    return 0;
}
