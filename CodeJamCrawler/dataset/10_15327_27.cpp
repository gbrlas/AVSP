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

#define NMAX 1000006
#define KMAX 15

int d, k;
bool prime[NMAX];
vector<int> p;
int s[KMAX];
int pow10[7];

int ee(int a, int b, int& x, int& y)
{
    if (b == 0)
    {
        x = 1; y = 0; return a;
    }
    int x0, y0;
    int d = ee(b, a % b, x0, y0);
    x = y0; y = x0 - (a / b) * y0;
    return d;
}
void solve(int test)
{
    printf("Case #%d: ", test);
    cin >> d >> k;
    forn(i, k)
    {
        cin >> s[i];
    }

    if (k == 1)
    {
        cout << "I don't know.\n";
        return;
    }

    if (s[0] == s[1])
    {
        cout << s[0] << endl;
        return;
    }

    if (k == 2)
    {
        cout << "I don't know.\n";
        return;
    }

    int cnt = 0;
    int ans = -1;
    forv(i, p)
    {
        if (p[i] > pow10[d]) break;
		bool ok = true;
        forn(j, k)
        {
            if (s[j] >= p[i]) 
			{
				ok = false;
			}
        }

		if (!ok) continue;

        int x, y;
		int P = p[i];
        ee((p[i] + s[0] - s[1]) % p[i], p[i], x, y);
        x = (x % p[i] + p[i]) % p[i];
        int A = (ll(x) * (s[1] - s[2] + p[i])) % p[i];
        int B = (s[1] - (ll(A) * s[0]) % p[i] + p[i]) % p[i];

       
        int sn;
        forn(j, k - 1)
        {
            sn = (ll(s[j]) * A + B) % p[i];
            if (sn != s[j + 1])
            {
                ok = false;
                break;
            }
        } 

        if (!ok) continue;

        sn = (ll(s[k - 1]) * A + B) % p[i];

        if (cnt == 0)
        {
            cnt++;
            ans = sn;
        } 
        else if (cnt == 1)
        {   
            if (ans != sn)
            {
                cnt++;
                break;
            }
        }

    }

    assert(cnt > 0);
    if (cnt > 1) cout << "I don't know.\n";
    else cout << ans << endl;
}
int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    pow10[0] = 1;
    for1(i, 6)
    {
        pow10[i] = pow10[i - 1] * 10;
    }
    forn(i, NMAX) prime[i] = true;
    prime[0] = prime[1] = false;

    for (int i = 2; i < NMAX; i++)
    {
        if (!prime[i]) continue;
        p.pb(i);
        for (int j = i + i; j < NMAX; j += i)
        {
            prime[j] = false;
        }
    }

    int tc;
    scanf("%d\n", &tc);
    forn(it, tc) solve(it + 1);
    
    return 0;
}