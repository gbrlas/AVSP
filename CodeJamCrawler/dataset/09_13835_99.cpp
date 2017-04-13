#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>
#include <sstream>
#include <ctime>

using namespace std;

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define for1(i, n) for(int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define NMAX 105

int n, m;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int h[NMAX][NMAX];
int comp[NMAX][NMAX];
int cnt;

bool valid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

int calc(int x, int y)
{
    if (comp[x][y] != -1) return comp[x][y];

    int minh = h[x][y];

    forn(k, 4)
    {
        if (!valid(x + dx[k], y + dy[k])) continue;
        minh = min(minh, h[x + dx[k]][y + dy[k]]);
    }    

    if (minh == h[x][y])
    {
        comp[x][y] = cnt;
        cnt++;
        return comp[x][y];
    }

    forn(k, 4)
    {
        if (!valid(x + dx[k], y + dy[k])) continue;
        if (h[x + dx[k]][y + dy[k]] == minh)
        {
            return comp[x][y] = calc(x + dx[k], y + dy[k]);
        }        
    }
}
void solve(int test)
{
    printf("Case #%d:\n", test);
    
    scanf("%d %d", &n, &m);
    forn(i, n)
    {
        forn(j, m)
        {
            scanf("%d", &h[i][j]);
        }
    }

    cnt = 0;
    forn(i, n) forn(j, m) comp[i][j] = -1;

    forn(i, n)
    {
        forn(j, m)
        {
            if (j) printf(" ");
            printf("%c", 'a' + calc(i, j));
        }
        printf("\n");
    } 

}
int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    int tc; scanf("%d", &tc);
    forn(it, tc) solve(it + 1);

    return 0;
}
            
