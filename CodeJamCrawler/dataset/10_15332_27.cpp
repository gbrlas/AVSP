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

#define SMAX 20004
#define NMAX 105
#define INF 1000000009

ll L;
int n;
int b[NMAX];
int d[SMAX];

void solve(int test)
{
    printf("Case #%d: ", test);

    cin >> L >> n;
    forn(i, n)
    {
        cin >> b[i];
    }

    forn(i, SMAX)
    {
        d[i] = INF;
    }
    d[0] = 0;

    forn(i, n)
    {
        forn(j, SMAX)
        {
            if (d[j] == INF) continue;
            if (j + b[i] >= SMAX) break;
            d[j + b[i]] = min(d[j + b[i]], d[j] + 1);
        }
    }

    if (L < SMAX)
    {
        if (d[L] == INF) 
        {
            cout << "IMPOSSIBLE\n";
        }
        else cout << d[L] << endl;
        return;
    }

    int bmax = 0;
    forn(i, n)
    {
        bmax = max(bmax, b[i]);
    }

    ll c = L / bmax;

    ll ans = ll(2e18);
    for (ll i = c; i >= 0; i--)
    {
        if (L - i * bmax >= SMAX) break;
        if (d[L - i * bmax] == INF) continue;

        ans = min(ans, d[L - i * bmax] + i);
    }

    if (ans > ll(1e18)) cout << "IMPOSSIBLE\n";
    else cout << ans << endl;
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