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

string w = "welcome to code jam";

#define NMAX 505
#define MMAX 20

int mod = 10000;

string s;
int d[NMAX][MMAX];

void solve(int test)
{
    printf("Case #%d: ", test);
    getline(cin, s);
    
    int n = (int)s.size();
    int m = (int)w.size();

    forn(i, n + 1) forn(j, m + 1) d[i][j] = 0;

    d[0][0] = 1;

    forn(i, n + 1)
    {
        forn(j, m + 1)
        {
            if (i < n) d[i + 1][j] = (d[i + 1][j] + d[i][j]) % mod;        
            if (s[i] == w[j]) d[i + 1][j + 1] = (d[i + 1][j + 1] + d[i][j]) % mod;
        }
    }

    if (d[n][m] < 1000) printf("0");
    if (d[n][m] < 100) printf("0");
    if (d[n][m] < 10) printf("0");

    printf("%d\n", d[n][m]);
            
}
int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    int tc; scanf("%d\n", &tc);

    forn(it, tc) solve(it + 1);

    return 0;
}
            
