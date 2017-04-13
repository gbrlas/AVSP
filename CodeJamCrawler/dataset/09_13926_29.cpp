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

#define NMAX 105
#define ALP 26
#define KMAX 15
#define mod 10009

string p;
int n, k;
int cnt[NMAX][ALP];

vector<string> divide(string s)
{
    s += '+';
    int l = 0;
    vector<string> ret;
    while (l < (int)s.size())
    {
        int r = l;
        while (s[r] != '+') r++;
        ret.pb(s.substr(l, r - l));
        l = r + 1;
    }
    return ret;
}

int ans[KMAX];

int tmp[ALP];

void rec(int idx, string& s)
{
    int p = 1;
    forv(i, s)
    {
        p = (p * tmp[s[i] - 'a']) % mod;
    }             
    ans[idx] = (ans[idx] + p) % mod;

    if (idx == k) return;

    forn(i, n)
    {
        forv(j, s)
        {
            if (j > 0 && s[j] == s[j-1]) continue;
            tmp[s[j] - 'a'] += cnt[i][s[j] - 'a'];
        }
        rec(idx + 1, s);
        forv(j, s)
        {
            if (j > 0 && s[j] == s[j-1]) continue;
            tmp[s[j] - 'a'] -= cnt[i][s[j] - 'a'];
        }
    }

}
void calc(string& s)
{
    sort(all(s));
    rec(0, s);        
}

void solve(int test)
{
    printf("Case #%d:", test);
    cin >> p >> k >> n;
    string s;
    memset(cnt, 0, sizeof(cnt));
    forn(i, n)
    {
        cin >> s;
        forv(j, s)
        {
           cnt[i][s[j] - 'a']++;
        }
    }

    vector<string> terms = divide(p);
    memset(ans, 0, sizeof(ans));
    memset(tmp, 0, sizeof(tmp));
    forv(i, terms)
    {
        calc(terms[i]);        
    }
    for1(i, k)
    {
        printf(" %d", ans[i]);
    }
    printf("\n");
    cerr << test << endl;
}
int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    int tc; scanf("%d\n", &tc);
    forn(it, tc)
    {
        solve(it + 1);
    }
    return 0;
}