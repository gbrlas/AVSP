#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;

#define GI ({int t;scanf("%d",&t);t;})
#define dbg(x) cout << #x << " -> " << x << "\t" << flush;
#define dbge(x) cout << #x << " -> " << x << "\t" << endl;
#define LET(x,a) typeof(a) x(a)
#define FORI(i,a,b) for(LET(i,a);i!=(b);++i)
#define FOR(i,a,b) for(LET(i,a);i < (b);++i)
#define FORZ(i,n) FOR(i,0,n)
#define EACH(i,v) FOR(i,(v).begin(),(v).end())
#define CS c_str()
#define PB push_back
#define SZ size()
#define INF (int)1e9+1
typedef long long LL;

bool isIntersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
    /*dbge(x1);
    dbge(y1);
    dbge(x2);
    dbge(y2);
    dbge(x3);
    dbge(y3);
    dbge(x4);
    dbge(y4);
    dbge("jkhkjhk");
    */
    double A1 = y2 - y1;
    double B1 = x1 - x2;
    double C1 = A1*x1 + B1*y1;
    double A2 = y4 - y3;
    double B2 = x3 - x4;
    double C2 = A2*x3 + B2*y3;
    double det = A1*B2 - A2*B1;
    if(det == 0)
    {
        if(A1*x3 + B1*y3 == C1)
            return 1;
        return 0;
    }
    double x = (B2*C1 - B1*C2)/det;
    double y = (A1*C2 - A2*C1)/det;
    /*dbge(x);
    dbge(x);
    */
    if(x >= min(x1, x2) && x <= max(x1, x2))
        if(x >= min(x3, x4) && x <= max(x3, x4))
            if(y >= min(y1, y2) && y <= max(y1, y2))
                if(y >= min(y3, y4) && y <= max(y3, y4))
                    return 1;
    return 0;
}

int dp[1<<16];
int n;
int Arr[17][17];
bool canDo(int m)
{
    vector<int> st;
    FORZ(i,n)
        if(m&(1<<i))
            FOR(j,i+1,n)
                if(m&(1<<j))
                    if(!Arr[i][j])
                        return 0;
    return 1;
}
int CAN[1<<17];
int solve(int mask)
{
    //dbge(mask);
    if(mask == 0)
        return 0;
    int& ref = dp[mask];
    if(ref != -1)
        return ref;
    int yet = mask;
    ref = 100;
    for(int sup = mask; sup > 0; sup = (sup - 1) &mask)
    {
        if(CAN[sup])
        {
            ref <?= 1 + solve(mask^sup);
        }
    }
    return ref;
/*    FORZ(i,n)
    {
        if(yet&(1<<i))
        {
            bool ok = 1;
            FORZ(j,st.SZ)
                if(!Arr[i][st[j]])
                {
                    ok = 0;
                    break;
                }
            if(ok)
            {
                yet ^= 1 << i;
                st.PB(i);
                ref <?= 1 + solve(yet);
            }
        }
    }
    */
}

int main()
{
/*    dbge(isIntersect(1,2,2,6,1,5,2,1));
    return 0;
    */
    int nC = GI;
    for(int nc = 1; nc <= nC; ++nc)
    {
        n = GI;
        int k = GI;
        memset(Arr, 0, sizeof Arr);
        typedef pair<int, int> PII;
        vector<vector<PII> > Vec;
        FORZ(i,n)
        {
            vector<PII> vec;
            FORZ(j,k)
            {
                int a = GI;
                vec.PB(PII(j,a));
            }
            Vec.PB(vec);

        }
        FORZ(i, n)
        {
            FOR(j,i+1,n)
            {
                bool ok = 1;
                FORZ(l,k-1)
                {
                    FORZ(m,k-1)
                    {
                        if(isIntersect(Vec[i][l].first, Vec[i][l].second, Vec[i][l+1].first, Vec[i][l+1].second, Vec[j][m].first, Vec[j][m].second, Vec[j][m+1].first, Vec[j][m+1].second))
                        {
                            ok = 0;
                            break;
                        }
                    }
                    if(!ok)
                        break;
                }
                Arr[i][j] = Arr[j][i] = ok;
            }
            Arr[i][i] = 1;
        }
        memset(dp, -1, sizeof dp);
        FORZ(i,(1<<n))
            if(canDo(i))
                CAN[i] = 1;
            else
                CAN[i] = 0;
        printf("Case #%d: %d\n", nc, solve((1<<n)-1));
    }
}
