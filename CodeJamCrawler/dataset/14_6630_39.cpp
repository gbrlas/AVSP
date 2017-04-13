#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <deque>
#include <sstream>
#include <iostream>
#include <queue>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <set>
#include <cstring>
#include <climits>
#include <map>
#include <cassert>
#define mod  1000000007
#define PHI 1000000006
#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(i=(a);i<(n);++i)
#define FD(i,a,n) for(i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define VI vector <int>
#define VII vector < vector <int> >
#define S1(x) scanf("%llu",&x)
#define MAX 100009
#define LOGMAXN 20
#define EPS 0.000001
using namespace std;

vector < vector <int> > s;

vector <pair <int, int> > res;
bool kuhn (int v, vector <bool> &used, vector <int> &pair)
{
    if (used[v]) {
        return false;
    }
    int i;
    used[v] = true;
    for (i = 0; i < s[v].size(); i++) {
        int to = s[v][i];
        if (pair[to] == -1 || kuhn (pair[to], used, pair)) {
            pair[to] = v;
            return true;
        }
    }
    return false;
}

int bpm(int n, int k)
{
    vector <int> pair (k, -1);
    vector <bool> used (n, false);
    res.clear();
    int i;
    for (i = 0; i < n; i++) {
        fill (used.begin(), used.end(), false);
        kuhn (i, used, pair);
    }
    int sum=0;

    for (i = 0; i < k; i++) {
        if (pair[i] != -1) {
            res.push_back (make_pair (pair[i], i));
            sum++;
        }
    }
    return sum;
}

int get( vector <double> a, vector <double> b)
{
    s.clear();
    s.resize (15);

    int i,j;
    for (i = 0; i < a.size(); i++) {
            for (j = 0; j < b.size(); j++) {
                    if (a[i] > b[j]) {
                        s[i].pb (j);
                    }
            }
    }
    return bpm (11,11);
}vector <double> a,b;
int dp[1LL<<10][1LL<<10][11];
int n;

bool check (int mask , int x)
{
    x = (1LL<<x);
    int xx = (mask | x);
    return (mask == xx);
}

int f (int aa, int bb, int flag)
{
   // .. cout << aa << " " << bb << " " << flag << endl;
    if (bb == (1LL<<n)-1) {
        return 0;
    }
    int &result = dp[aa][bb][flag];
    if (result != -1) {
        return result;
    }
    int i;
    result = 0;
    if (flag == 0) {
        for (i = 0; i < n; i++) {
            if (check (aa, i)) {
                continue;
            }
            result = max (result, f (aa|(1LL<<i), bb, i+1));
        }
        return result;
    }
    result = 10000000;

    for (i = 0; i < n; i++) {
        if (check (bb, i)) {
            continue;
        }
        if (b[i] > a[flag-1]) {
            result = min (result, f (aa, bb|(1LL<<i), 0));
            continue;
        }
        result = min (result, 1+f (aa, bb|(1LL<<i), 0));
    }
    return result;
}

int ff( vector <double> a, vector <double> b)
{
    memset (dp, -1, sizeof(dp));
    return f (0, 0, 0);
}

int main()
{
    //    freopen ("input.txt", "r", stdin);
    freopen ("D-small-attempt0.in", "r", stdin);
    freopen ("output.txt", "w", stdout);

    int t;
    S (t);
    int ii = 1;
    while (t--) {

        cout << "Case #" << ii++ << ": ";
        cin >> n;
        a.resize (n);
        b.resize (n);
        int i;
        F (i, 0, n) {
            cin >> a[i];
        }
        F (i, 0, n) {
            cin >> b[i];
        }

        sort (a.begin(), a.end());
        sort (b.begin(), b.end());
        int sum = get (a, b);
        cout << sum << " ";



        cout << ff(a, b) << endl;
    }

    return 0;
}
