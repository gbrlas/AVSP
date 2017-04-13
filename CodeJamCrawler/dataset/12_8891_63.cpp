/* 
 * File:   a.cc
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
#define PROBLEM "a"

#define all(x) (x).begin(), (x).end()
#define START clock_t _clock = clock();
#define END cerr << (clock() - _clock) / (LD) CLOCKS_PER_SEC << endl;

/*
 * 
 */
int solve(int test) {
    cout.setf(ios::fixed);
    cout.precision(10);
    int n;
    cin >> n;
    vector<int> votes(n);
    for (int i = 0; i < n; ++i)
        cin >> votes[i];
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += votes[i];
    vector<pii> vs(n);
    int s1 = sum;
    for (int i = 0; i < n; ++i) {
        vs[i].X = votes[i];
        vs[i].Y = i;
    }
    sort(vs.begin(), vs.end());
    vector<int> added(n);
    vector<LD> res(n);
    int cur = 0;
    int cc = 0;
    for (int i = 0; i < n; ++ i) {
        if (vs[i].X == cur) {
            cc ++;
        } else {
            if ((vs[i].X - cur) * cc <= s1) {
                s1 -= (vs[i].X - cur) * cc;
                for (int j = 0; j < cc; ++ j)
                    added[vs[j].Y] += vs[i].X - cur;
                cur = vs[i].X;
                cc ++;
            } else {
                break;
            }
        }
    }
    for (int i = 0; i < cc; ++ i)
        res[vs[i].Y] = (added[vs[i].Y] + LD(s1) / cc) * 100. / sum;
    cout << "Case #" << test << ":";
    for (int i = 0; i < n; ++ i)
        cout << " " << res[i];
    cout << endl;
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
