/* 
 * File:   c.cc
 * Author: cheshire
 *
 * Created on 5 Май 2012 г., 16:10
 */
#if 1

#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <complex>
#include <functional>
#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef vector<int> veci;
typedef vector<veci> graph;

const LD eps = 1e-9;
const LD pi = acos(-1.0);
const int inf = 1000 * 1000 * 1000;
const LL inf64 = LL(inf) * inf;

#define pb push_back
#define mp make_pair
#define X first
#define Y second

#ifdef DEBUG
#define dbg(x) { cerr << #x << " = " << x << endl; }
#define dbgv(x) { cerr << #x << " = {"; for(size_t _i = 0; _i < (x).size(); ++_i) { if(_i) cerr << ", "; cerr << (x)[_i]; } cerr << "}" << endl; }
#define dbgi(start, end, label) {cerr << #label << " = {"; for (auto _it = start; _it != end; ++ _it) { if (_it != start) cerr << ", "; cerr << *(_it);} << cerr << "}" << endl; }
#else
#define dbg(x) 
#define dbgv(x)
#define dbgi(start, end, label)

#endif
#define PROBLEM "c"

#define all(x) (x).begin(), (x).end()
#define START clock_t _clock = clock();
#define END cerr << (clock() - _clock) / (LD) CLOCKS_PER_SEC << endl;

/*
 * 
 */
int get(int mask, const vector<int>& cs) {
    int res = 0;
    for (int i = 0; i < cs.size(); ++ i)
        if ((1 << i) & mask)
            res += cs[i];
    return res;
}
vector<int> extract(int mask, const vector<int>& cs) {
    vector<int> res;
    for (int i = 0; i < cs.size(); ++ i)
        if ((1 << i) & mask)
            res.pb(cs[i]);
    return res;
}
void output(const vector<int>& a) {
    for (int i = 0; i < a.size(); ++ i)
        printf("%d%c", a[i], " \n"[i + 1 == a.size()]);
}
int solve(int test) {
    int n;
    cin >> n;
    vector<int> cs(n);
    for (int i = 0; i < n; ++ i)
        cin >> cs[i];
    sort(all(cs));
    int q = 1 << n;
    cout << "Case #" << test << ":" << endl;
    for (int mask = 1; mask < q; ++ mask)
        for (int sm = mask; sm > 0; sm = mask & (sm - 1))
            if (get(sm, cs) == get(mask ^ sm, cs))
            {
                output(extract(sm, cs));
                output(extract(mask ^ sm, cs));
                return 0;
            }
    cout << "Impossible" << endl;
    return 0;
}

int main() {
    START;
    freopen(PROBLEM ".in", "r", stdin); freopen(PROBLEM ".out", "w", stdout);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test)
        solve(test);

    END;
    return (EXIT_SUCCESS);
}

#endif
