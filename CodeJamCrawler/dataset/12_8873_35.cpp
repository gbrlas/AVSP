/* 
 * File:   b.cc
 * Author: cheshire
 *
 * Created on 14 Апрель 2012 г., 16:46
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
#define PROBLEM "B-small-attempt0"

#define all(x) (x).begin(), (x).end()
#define START clock_t _clock = clock();
#define END cerr << (clock() - _clock) / (LD) CLOCKS_PER_SEC << endl;

/*
 * 
 */
void solve (int test)
{
    int n, s, p;
    cin >> n >> s >> p;
    int res = 0;
    int tmp = 0;
    for (int i = 0; i < n; ++ i)
    {
        cin >> tmp;
        if (tmp > 3 * p - 3)
            res ++;
        else if (tmp > 3 * p - 5 && tmp > 1 && s)
            s --, res ++;
    }
    cout << "Case #" << test << ": " << res << endl;
    return;
}
int main() {
    START;
    freopen(PROBLEM ".in", "r", stdin); freopen(PROBLEM ".out", "w", stdout);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int test = 1; test <= n; ++ test)
        solve(test);


    END;
    return (EXIT_SUCCESS);
}

#endif
