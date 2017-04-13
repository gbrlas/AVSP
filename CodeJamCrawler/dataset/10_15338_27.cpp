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

vector<pii> v;
    
void norm(vector<pii>& v)
{
//    sort(all(v));
    vector<pii> v1;
    v1.pb(v[0]);
    forv(i, v)
    {
        if (i == 0) continue;
        if (v[i].first == v1.back().first)
        {
            v1[v1.size()-1].second += v[i].second;
        }    
        else
        {
            v1.pb(v[i]);
        }
    }
    v = v1;
}

void move(vector<pii>& v)
{
    vector<pii> v1;
    bool f = false;
    forv(i, v)
    {
        if (v[i].second >= 2 && !f)
        {
            v1.pb(mp(v[i].first - 1, 1));
            if (v[i].second > 2) v1.pb(mp(v[i].first, v[i].second - 2));            
            v1.pb(mp(v[i].first + 1, 1));
            f = true;
        }
        else
        {
            v1.pb(v[i]);
        }
    }
    v = v1;
    norm(v);
}
void solve(int test)
{
    cerr << test << endl;
    printf("Case #%d: ", test);
    
    int c;
    cin >> c;

    v.clear();
    v.resize(c);

    int all = 0;
    forn(i, c)
    {
        int p, cnt;
        cin >> p >> cnt;
        v[i] = mp(p, cnt);    
        all += cnt;
    }

    sort(all(v));
    norm(v);

    int ans = 0;
    while (v.size() != all)
    {
        ans++;
        move(v);
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