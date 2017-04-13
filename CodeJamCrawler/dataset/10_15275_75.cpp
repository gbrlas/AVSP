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

typedef long long ll;

#define NMAX 105
#define INF 1000000009

int D, I, M, n;
int a[NMAX];
int d[NMAX][257];

int tmp[257];
bool used[257];

void dijkstra(int i)
{
    forn(j, 257) tmp[j] = d[i][j];
    memset(used, 0, sizeof(used));

    while (true)
    {
        int p = -1;
        forn(j, 257)
        {
            if (!used[j] && (p == -1 || tmp[p] > tmp[j])) p = j;
        }
        if (p == -1 || tmp[p] == INF) break;
        used[p] = true;

        forn(j, 256)
        {
            if (p == 256 || abs(j - p) <= M)
            {
                tmp[j] = min(tmp[j], tmp[p] + I);
            }
        }
    }     

    forn(j, 257) d[i][j] = tmp[j];
}
void solve(int test)
{
    printf("Case #%d: ", test);
    cin >> D >> I >> M >> n;

    forn(i, n)
    {
        cin >> a[i];
    }

    forn(i, NMAX)
    {
        forn(j, 257)
        {
            d[i][j] = INF;
        }
    }

    d[0][256] = 0;

    for1(i, n)
    {
        d[i][256] = d[i - 1][256] + D;

        forn(j, 256)
        {
            d[i][j] = min(d[i][j], d[i - 1][j] + D);
            forn(k, 256)
            {
                if (d[i-1][k] == INF) continue;
                if (abs(j - k) > M) continue;
                d[i][j] = min(d[i][j], d[i - 1][k] + abs(a[i - 1] - j));
            }

            d[i][j] = min(d[i][j], d[i - 1][256] + abs(a[i - 1] - j));
        } 
        dijkstra(i);
    }

    int ans = INF;
    forn(j, 257)
    {
        ans = min(ans, d[n][j]);
    }

    cout << ans << endl;
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