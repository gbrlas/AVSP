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

map<vector<int>, bool> win;

bool calc(vector<int>& v)
{
    if (win.count(v)) return win[v];

    if (v.size() == 1)
    {
        if (v[0] == 1) return win[v] = false;
        return win[v] = true;
    }
    vector<int> tmp;
    for (int i = 1; i < (int)v.size(); i++) 
    {
        tmp.pb(v[i]);
    }

    if (!calc(tmp))
    {
        return win[v] = true;
    }

	if (v[0] == 2)
	{
		tmp = v;
		tmp[0]--;

		if (!calc(tmp))
		{
			return win[v] = true;
		}
	}
    return win[v] = false;
}

vector<int> get_vector(int a, int b)
{
    vector<int> v;

    if (b > a) swap(a, b);

    while (b > 0)
    {
        v.pb(a / b);
        a %= b;
        swap(a, b);
    }

    forv(i, v) v[i] = min(v[i], 2);

    return v;
}
void solve(int test)
{
    printf("Case #%d: ", test);
    
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;

    int ans = 0;
    for (int a = a1; a <= a2; a++)
    {
        for (int b = b1; b <= b2; b++)
        {
            vector<int> v = get_vector(a, b);
            ans += calc(v);
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