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

#define NMAX 55

int n, k;
int a[NMAX][NMAX], b[NMAX][NMAX];

void out()
{
    forn(i, n)
    {
        forn(j, n)
        {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void rotate()
{
    forn(i, n)
    {
        forn(j, n)
        {
            b[i][j] = a[n - j - 1][i];
        }
    }    

    memcpy(a, b, sizeof(a));

//    out();
}

void gravity()
{
    forn(j, n)
    {
        int k = n - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i][j] != '.')
            {
                a[k][j] = a[i][j];
                k--;
            }
        }

        forn(i, k + 1)
        {
            a[i][j] = '.';
        }
    }

//    out();
}

int dx[4] = {0, 1, 1, 1};
int dy[4] = {1, -1, 0, 1};

bool valid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool row(int x, int y, char c, int t)
{
    forn(i, k)
    {
        if (!valid(x, y)) return false;
        if (a[x][y] != c) return false;
        x += dx[t];
        y += dy[t];
    }

    return true;
}

void solve(int test)
{
    printf("Case #%d: ", test);
    scanf("%d %d\n", &n, &k);
    forn(i, n)
    {
        forn(j, n)
        {
            scanf("%c", &a[i][j]);
        }
        scanf("\n");
    }

    rotate();

    gravity();

    bool red = false;
    bool blue = false;

    forn(i, n)
    {
        forn(j, n)
        {
            forn(t, 4)
            {
                if (row(i, j, 'R', t)) red = true;
                if (row(i, j, 'B', t)) blue = true;
            }
        }
    }

    if (!red && !blue)
    {
        cout << "Neither\n";    
    }

    if (red && blue)
    {
        cout << "Both\n";
    }

    if (red && !blue)
    {
        cout << "Red\n";
    }

    if (!red && blue)
    {
        cout << "Blue\n";
    }
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