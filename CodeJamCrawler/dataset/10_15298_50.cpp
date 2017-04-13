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

int p;
bool r[PMAX][RMAX];
int m[RMAX];
int cost[PMAX][RMAX];
    
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

    memset(r, 0, sizeof(r));

    forn(i, (1 << p))
    {
        for (int j = m[i]; j < p; j++)
        {
            r[j][i >> (j + 1)] = true;
        }
    }

    int ans = 0;
    forn(i, p)
    {
        forn(j, (1 << (p - i - 1)))
        {
            ans += r[i][j];
        }
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