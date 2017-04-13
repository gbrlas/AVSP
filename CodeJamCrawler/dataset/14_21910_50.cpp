#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#define REP(i,n) for(int i = 0; i < (n); i++)

using namespace std;

struct edge {
    int u, v, f, c;
    int rev;
};

const int MAXN = 4000000;
vector<edge> G[MAXN];

int n;
vector<int> vis;
int dfs(int u, int iter, int target) {
    //cout << u << " " << target << endl;
    if (u == target) {
        //cout << "found" << endl;
        return 1;
    }
    if (vis[u] == iter) {
        return 0;
    }
    vis[u] = iter;
    for (edge& e : G[u]) {
        //cout << u << "->" << e.v << " " << e.f << endl;
        if (e.c - e.f == 0) continue;
        int res = dfs(e.v, iter, target);
        if (res > 0) {
            e.f += 1;
            G[e.v][e.rev].f -= 1;
            return 1;
        }
    }
    return 0;
}

int flow(int s, int t) {
    vis.clear();
    vis.resize(n);
    int res = 0;
    for(int i = 1;;i++) {
        int delta = dfs(s, i, t);
        res += delta;
        if (delta == 0) break;
    }
    return res;
}

int di[] = {-1,0,1,0};
int dj[] = {0,1,0,-1};

int srepr(int r, int c, int w) {
    return (r * w + c) * 2;
}

int drepr(int r, int c, int w) {
    return (r * w + c) * 2 + 1;
}

void add_edge(int u, int v, int c) {
    int uid = G[u].size();
    int vid = G[v].size();
    G[u].push_back(edge({u, v, 0, c, vid}));
    G[v].push_back(edge({v, u, 0, 0, uid}));
}

/*
void add_edge(int r, int c, int nr, int nc, int w) {
    int u = repr(r, c, w);
    int v = repr(nr, nc, w);
    add_edge(u, v, 1);
}
*/

void generate(vector<vector<int>> tab) {
    int h = tab.size();
    int w = tab[0].size();
    REP(i, h) {
        REP(j, w) {
            REP(k, 4) {
                int ni = di[k] + i;
                int nj = dj[k] + j;
                if (ni >= 0 and ni < h and nj >= 0 and nj < w) {
                    if (tab[i][j] and tab[di[k] + i][dj[k] + j]) {
                        add_edge(srepr(i, j, w), drepr(di[k] + i, dj[k] + j, w), 1);
                    }
                }
            }
            if (tab[i][j]) {
                add_edge(drepr(i, j, w), srepr(i, j, w), 1);
            }
        }
    }
    REP(i, w) {
        if (tab[0][i]) {
            add_edge(2 * w * h, drepr(0, i, w), 1);
        }
    }
    REP(i, w) {
        if (tab[h-1][i]) {
            add_edge(srepr(h-1, i, w), 2 * w * h + 1, 1);
        }
    }
    /*
    REP(i, 2 * w * h + 2) {
        cout << i << " : ";
        for (edge e : G[i]) {
            cout << "(" << e.v << ") ";
        }
        cout << endl;
    }
    */
}

void solve(int cas) {
    int w, h, B;
    cin >> w >> h >> B;
    n = 2 * w * h + 2;
    REP(i, n) G[i].clear();
    vector<vector<int>> tab(h, vector<int>(w, 1));
    REP(i, B) {
        int x0, y0, x1, y1;
        cin >> x0 >> y0 >> x1 >> y1;
        if (x0 > x1) swap(x0, x1);
        if (y0 > y1) swap(y0, y1);
        for(int a = x0; a <= x1; a++) for(int b = y0; b <= y1; b++) {
            tab[b][a] = 0;
        }
    }
    generate(tab);
    int res = flow(2*w*h, 2*w*h+1);
    cout << "Case #" << cas+1 << ": " << res << endl;
    REP(i, n) G[i].clear();
}

int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) solve(i);
    return 0;
}
