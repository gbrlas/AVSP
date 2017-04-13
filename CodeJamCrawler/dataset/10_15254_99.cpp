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

#define NMAX 1005

int r, n, k;
int g[NMAX];
int cnt[NMAX];
int next[NMAX];

void solve(int test)
{
    printf("Case #%d: ", test);
    cerr << test << endl;

    cin >> r >> k >> n;
    forn(i, n)
    {
        cin >> g[i];
    } 

    forn(i, n)
    {
        cnt[i] = 0;
        forn(j, n + 1)
        {
            if (cnt[i] + g[(i + j) % n] > k || j == n)
            {
                next[i] = (i + j) % n;
                break;                
            }
            cnt[i] += g[(i + j) % n];
        }
    }

    ll ans = 0;
    int cur = 0;
    forn(i, r)
    {
        ans +=  cnt[cur];
        cur = next[cur];        
    }

    cout << ans << endl;
}
int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    int tc;
    scanf("%d\n", &tc);
    forn(it, tc)
    {
        solve(it + 1);
    }
    return 0;
}