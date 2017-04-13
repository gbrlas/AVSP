#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <sstream>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define PMAX 10
#define RMAX 1024
#define INF 1000000000000000LL

int p;
int m[RMAX];
int cost[PMAX][RMAX];
ll d[PMAX][RMAX][PMAX + 1];
    
void solve(int test)
{
    printf("Case #%d: ", test);
    scanf("%d", &p);
    forn(i, (1 << p))
    {
        scanf("%d", &m[i]);
    }

    forn(i, p)
    {
        forn(j, (1 << (p - i - 1)))
        {
            scanf("%d", &cost[i][j]);
        }
    }

    forn(i, p)
    {
        forn(j, (1 << (p - i - 1)))
        {
            forn(k, p + 1)
            {
                d[i][j][k] = INF;              
            }
        }        
    }
    forn(j,  (1 << (p - 1)))
    {
        int j1 = p - m[(j << 1)];
        int j2 = p - m[(j << 1) + 1];

        d[0][j][max(j1, j2)] = min(d[0][j][max(j1, j2)], 0LL);
        if (j1 > 0 || j2 > 0)
        {
            d[0][j][max(j1 - 1, j2 - 1)] = min(d[0][j][max(j1 - 1, j2 - 1)], (ll)cost[0][j]);
        }        
    }

    for1(i, p - 1)
    {
        forn(j, (1 << (p - i - 1)))
        {
            int j1 = (j << 1);
            int j2 = (j << 1) + 1;

            forn(p1, p + 1)
            {
                if (d[i-1][j1][p1] == INF) continue;
                forn(p2, p + 1)
                {
                    if (d[i - 1][j2][p2] == INF) continue;

                    d[i][j][max(p1, p2)] = min(d[i][j][max(p1, p2)], d[i - 1][j1][p1] + d[i - 1][j2][p2]);

                    if (p1 > 0 || p2 > 0)
                    {
                        d[i][j][max(p1 - 1, p2 - 1)] = min(d[i][j][max(p1 - 1, p2 - 1)],
                        d[i - 1][j1][p1] + d[i - 1][j2][p2] + cost[i][j]);
                    }
                }
            }
        }
    }

    cout << d[p - 1][0][0] << endl;

}
int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    int tc;
    scanf("%d\n", &tc);
    forn(it, tc) solve(it + 1);
    
    return 0;
}