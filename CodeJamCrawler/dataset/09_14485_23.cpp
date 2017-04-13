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

int main()
{
    int nC = GI;
    for(int nc = 1; nc <= nC; ++nc)
    {
        int N = GI;
        int Arr[N][N];
        int Pos[N][N];
        memset(Arr, 0, sizeof Arr);
        memset(Pos, 0, sizeof Pos);
        vector<int> Vec;
        int Assn[N];
        memset(Assn, 0, sizeof Assn);
        FORZ(i, N)
        {
            string s;
            cin >> s;
            int f1 = 0;
            FORZ(j, N)
            {
                Arr[i][j] = s[j] == '1';
                if(Arr[i][j])
                    f1 = j;
            }
            for(int j = f1; j < N; ++j)
                Pos[i][j] = 1;
            while(Assn[f1])
                f1++;
            Assn[f1] = 1;
            Vec.PB(f1);
        }
        int val = 0;
        FORZ(i, N)
            for(int j = i + 1; j < N; ++j)
                if(Vec[i] > Vec[j])
                    val++;
        /*vector<int> vec;
        FORZ(i, N)
            vec.PB(i);
        int ret = 1e8;
        do
        {
            int pos = 1;
            FORZ(i, vec.SZ)
            {
                if(!Pos[vec[i]][i])
                {
                    pos = 0;
                    break;
                }
            }
            if(pos)
            {
               int rr = 0;
                vector<int> vec1 = vec;
                bool vis[N];
                memset(vis, 0, sizeof vis);
                FORZ(i, N)
                {
                    if(vis[i])
                        continue;
                    int sw = 0;
                    int st = i;
                    while(!vis[st])
                    {
                        int o = st;
                        vis[st] = 1;
                        st = vec1[o], sw++;
                    }
                    dbge(sw);
                    rr += sw - 1;
                }
                int rr = 0;
                FORZ(i,N)
                    for(int j = i + 1; j < N; ++j)
                        if(vec[i] > vec[j])
                            rr++;
                ret <?= rr;
            }

        }while(next_permutation(vec.begin(), vec.end()));
        */
        printf("Case #%d: %d\n", nc,val);
    }
}
