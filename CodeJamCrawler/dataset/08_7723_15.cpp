#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

#define pb push_back
#define pii pair<int, int>
#define int64 long long
#define vi vector<int>
#define forr(i, n) for(int i = 0; i < (n); i++)
#define be(v) v.begin(), v.end()
#define sstr stringstream

int main()
{
    freopen("D.in", "rt", stdin);
    freopen("D.out", "wt", stdout);

    int test;
    cin >> test;
    for(int t = 1; t <= test; t++) 
    {
        int k;
        string s;
        cin >> k >> s;
        vi p;
        forr(i, k)
            p.pb(i);

        int sz = s.length();
        int res = sz;
        do
        {
            string s2=s;
            forr(i, sz / k)
                forr(j, k)
                    s2[i*k + j] = s[i*k + p[j]];
            int cur = 0, ix = 0;
            while(ix != -1)
            {
                cur++;
                ix = s2.find_first_not_of(s2[ix], ix + 1);
            }
            res = min(res, cur);
        } while(next_permutation(be(p)));
        cout << "Case #" << t << ": " << res << endl;
    }
    return 0;
}