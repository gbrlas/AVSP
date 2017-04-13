#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;

const int MAXM = 2010;
const int mod = 1000002013;
#define UP 0
#define DOWN 1
struct TRAVEL
{
    int stop;
    int flag;
    int p;
    bool operator<(const TRAVEL& tr)const{
        if(stop < tr.stop) return true;
        else if(stop > tr.stop) return false;
        else return (flag < tr.flag);
    }
}travel[MAXM];

TRAVEL stk[MAXM];

long long calcCost(int N, int s, int e)
{
    long long stopN = (e-s);
    return (N+N-stopN+1)*stopN/2 % mod;
}

int main()
{
    freopen("A.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int T;
    cin>>T;

    for(int ca=1; ca<=T; ++ca)
    {
        long long originPrice = 0;
        int N, M;
        cin>>N>>M;
        for(int i=0; i<M; ++i)
        {
            int s, e, p;
            cin>>s>>e>>p;
            travel[i*2].flag = UP;
            travel[i*2+1].flag = DOWN;
            travel[i*2].p = travel[i*2+1].p = p;
            travel[i*2].stop = s;
            travel[i*2+1].stop = e;
            long long tmp = calcCost(N, s, e);
            originPrice += tmp*p;
            originPrice %= mod;
        }

        sort(travel, travel + M*2);

        int top = -1;
        int minCost = 0;
        for(int i=0; i<2*M; ++i)
        {
            if(travel[i].flag == UP)
            {
                stk[++top] = travel[i];
            }
            else{
                int curP = travel[i].p;
                int curStop = travel[i].stop;
                while(curP > 0)
                {
                    int pp = min(curP, stk[top].p);
                    stk[top].p -= pp;
                    curP-=pp;
                    minCost += pp*calcCost(N, stk[top].stop, curStop);
                    minCost %= mod;
                    if(stk[top].p == 0) --top;
                }
            }
        }
        long long res = (originPrice - minCost + mod) % mod;
        cout << "Case #" << ca <<": " << res << endl;

    }

    return 0;
}
