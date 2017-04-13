/* 
 * File:   b.cc
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
#define PROBLEM "b"

#define all(x) (x).begin(), (x).end()
#define START clock_t _clock = clock();
#define END cerr << (clock() - _clock) / (LD) CLOCKS_PER_SEC << endl;

/*
 * 
 */
const int safe = 50;
const int fast = 20;
int h;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

pair<LL, LL> get(const vector<vector<pii> >& g, int x, int y, int nx, int ny) {
    if (g[nx][ny].X + safe > g[nx][ny].Y
            || g[x][y].X + safe > g[nx][ny].Y
            || g[nx][ny].X + safe > g[x][y].Y) {
        return mp(inf64, inf64);
    } else {
        LL t1, t2;
        t1 = max((LL) h + safe - g[nx][ny].Y, (LL) 0);
        t2 = (LL) h - (g[x][y].X + fast);
        return mp(t1, t2);
    }
}
typedef pair<LL, pair<int, int> > pdii;

LL dijkstra(const vector<vector<pii> >& g) {
    priority_queue<pdii, vector<pdii>, greater<pdii> > q;
    q.push(mp((LD) 0, mp(0, 0)));
    int n = g.size();
    int m = g[0].size();
    vector<vector<LL> > d(n, vector<LL > (m, (LL) inf64));
    d[0][0] = 0;
    while (!q.empty()) {
        pdii c = q.top();
        q.pop();
        int x = c.Y.X;
        int y = c.Y.Y;
        LL cd = c.X;
        if (fabs(d[x][y] - cd) < eps) {
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                cd = c.X;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    pair<LL, LL> ed = get(g, x, y, nx, ny);
                    cd = max(cd, ed.X);
                    if (cd > 0 && cd <= ed.Y)
                        cd += 10;
                    else if (cd > 0)
                        cd += 100;
                    if (cd < d[nx][ny]) {
                        d[nx][ny] = cd;
                        q.push(mp(cd, mp(nx, ny)));
                    }
                }
            }
        }
    }
    return d[n - 1][m - 1];
}

int solve(int test) {
    int n, m;
    cin >> h >> n >> m;
    vector<vector<pii> > cs(n, vector<pii > (m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> cs[i][j].Y;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> cs[i][j].X;
    LL res = dijkstra(cs);
    printf("Case #%d: %d.%d\n", test, res / 10, res % 10);
    //cout << "Case #" << test << ": " << res << endl;
    return 0;
}

int main() {
    START;
    freopen(PROBLEM ".in", "r", stdin);
    freopen(PROBLEM ".out", "w", stdout);
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test)
        solve(test);
    END;
    return (EXIT_SUCCESS);
}

#endif
