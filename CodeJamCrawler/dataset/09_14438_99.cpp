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
typedef unsigned long long LL;

int L, D, N;

int main()
{
    L = GI, D = GI, N = GI;
    char vec[D+10][L+10];
    FORZ(i, D)
    {
        cin >> vec[i];
    }
    for(int nc = 1; nc <= N; ++nc)
    {
        printf("Case #%d: ", nc);
        string str;
        cin >> str;
        int mine[17][255] = {0};
        int pos = -1;
        FORZ(i, str.SZ)
        {
            pos++;
            if(str[i] == '(')
            {
                i++;
                while(str[i] != ')')
                {
                    mine[pos][(str[i])] = 1;
                    i++;
                }
            }
            else
                mine[pos][(str[i])] = 1;
        }
        int cnt = 0;
        FORZ(i, D)
        {
            bool f = 1;
            FORZ(j, L)
            {
                if(!mine[j][vec[i][j]])
                {
                    f = 0;
                    break;
                }
            }
            cnt += f;
        }
        printf("%d\n",cnt);
    }
}
