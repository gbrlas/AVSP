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
#define forr(i, a, n) for(int i = (a); i < (n); i++)
#define be(v) v.begin(), v.end()
#define sstr stringstream


int main()
{
    freopen("A.in", "rt", stdin);
    freopen("A.out", "wt", stdout);

    int test;
    cin >> test;
    for(int t = 1; t <= test; t++) 
    {
        int n, x;
        cin >> n;
        vi a, b;
        for(int i = 0; i < n; i++) 
        {
            cin >> x; a.pb(x);
        }
        for(int i = 0; i < n; i++) 
        {
            cin >> x; b.pb(-x);
        }
        sort(be(a));
        sort(be(b));
        long long res = 0;
        for(int i = 0; i < n; i++)
            res += a[i] * (-b[i]);
        cout << "Case #" << t << ": " << res << endl;
    }
    return 0;
}