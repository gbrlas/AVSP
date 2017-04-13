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

#define NMAX 105

int r;
int a[2][NMAX][NMAX];


void solve(int test)
{
    printf("Case #%d: ", test);
    memset(a, 0, sizeof(a));

    scanf("%d", &r);
    forn(i, r)
    {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        for (int j = x1; j <= x2; j++)
        {
            for (int k = y1; k <= y2; k++)
            {
                a[0][j][k] = 1;
            }
        }
    }

    int iter = 0;
    while (true)
    {
        int i1 = iter & 1;
        int i2 = i1 ^ 1;

        memset(a[i2], 0, sizeof(a[i2]));
        bool ok = false;
        forn(i, NMAX)
        {
            forn(j, NMAX)
            {
                a[i2][i][j] = a[i1][i][j];
                if (a[i1][i][j]) ok = true;
                if (a[i1][i - 1][j] == 0 && a[i1][i][j - 1] == 0) a[i2][i][j] = 0;
                if (a[i1][i - 1][j] == 1 && a[i1][i][j - 1] == 1) a[i2][i][j] = 1;
            }
        }

        if (!ok) break;

        iter++;
    }

    cout << iter << endl;

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