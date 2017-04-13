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

#define NMAX 55

int n;
int a[NMAX][NMAX];
int b[2 * NMAX][NMAX];
int cur[2 * NMAX];
bool sym1[2 * NMAX], sym2[2 * NMAX];

bool valid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}

void solve(int test)
{
    printf("Case #%d: ", test);
    scanf("%d", &n);

    forn(i, n)
    {
        forn(j, i + 1)
        {
            scanf("%d", &b[i][j]);
        }
    }
    for (int i = n; i < 2 * n - 1; i++)
    {
        forn(j, 2 * n - i - 1)
        {
            scanf("%d", &b[i][j]);
        }
    }

    memset(cur, 0, sizeof(cur));

    forn(i, n)
    {   
        forn(j, n)
        {
            a[i][j] = b[i + j][cur[i + j]];
            cur[i + j]++;
        }
    }

 /*   forn(i, n)
    {
        forn(j, n)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
 */

    for (int s = -(n - 1); s <= n - 1; s++)
    {
        bool ok = true;
        forn(i, n)
        {
            forn(j, n)
            {
                int si = j + s;
                int sj = i - s;

                if (!valid(si, sj)) continue;

                if (a[si][sj] != a[i][j])
                {
                    ok = false;
                }
            }
        }

        sym1[s + n] = ok;
    }

    for (int s = 0; s < 2 * n - 1; s++)
    {
        
        bool ok = true;
        forn(i, n)
        {
            forn(j, n)
            {
                int si = s - j;
                int sj = s - i;

                if (!valid(si, sj)) continue;

                if (a[si][sj] != a[i][j])
                {
                    ok = false;
                }
            }
        }

        sym2[s] = ok;
    }

    int ans = 1000;
    for (int s1 = -(n - 1); s1 <= (n - 1); s1++)
    {
        for (int s2 = 0; s2 < 2 * n - 1; s2++)
        {
            if (sym1[s1 + n] && sym2[s2])
            {
                int ci = s1 + s2;
                int cj = s2 - s1;

                int N = max(max(ci + 1, cj + 1), max(2 * n - ci - 1, 2 * n - cj - 1));
                ans = min(ans, N);
            } 
        }
    }

    cout << ans * ans - n * n << endl;
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