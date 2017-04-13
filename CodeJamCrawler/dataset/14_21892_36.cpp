#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>
#include <iomanip>

#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(u) (u).begin(), (u).end()

using namespace std;

typedef long double K;
typedef pair<int,int> PII;

char tab[10][10];
int R, C, m;

int dr[8] = {-1,-1,-1,0,1,1,1,0};
int dc[8] = {-1,0,1,1,1,0,-1,-1};

int vis[10][10];

void init_dfs() {
    REP(i, R) REP(j, C) vis[i][j] = 0;
}

bool is_zero(int r, int c) {
    if (tab[r][c] != '.') return false;
    for(int k = 0; k < 8; k++) {
        int nr = r + dr[k];
        int nc = c + dc[k];
        if (nr >= 0 and nr < R and nc >= 0 and nc < C) {
            if (tab[nr][nc] != '.') return false;
        }
    }
    return true;
}

int dfs(int r, int c, int first) {
    if (!(r >= 0 and r < R and c >= 0 and c < C)) {
        return 0;
    }
    if (vis[r][c] != 0) return 0;
    if (tab[r][c] != '.') return 0;
    vis[r][c] = 1;
    if (first == 0 and (!is_zero(r, c))) {
        return 1;
    }
    int cnt = 1;
    for(int k = 0; k < 8; k++) {
        int nr = r + dr[k];
        int nc = c + dc[k];
        cnt += dfs(nr, nc, 0);
    }
    return cnt;
}

PII backtrack(int r, int c, int cnt) {
    if (r == R and c == 0) {
        if (cnt > 0) return PII(-1, -1);
        PII ret(-1, -1);
        REP(i, R) REP(j, C) {
            if (is_zero(i, j)) {
                init_dfs();
                int sp = dfs(i, j, 1);
                if (sp == R * C - m) {
                    return PII(i, j);
                } else {
                    return PII(-1, -1);
                }
            }
            if (tab[i][j] == '.') {
                ret = PII(i, j);
            }
        }
        if (R * C - m <= 1) {
            return ret;
        }
        return PII(-1, -1);
    }
    int nr = r + ((c == C-1)?1:0);
    int nc = ((c == C-1)?0:c+1);
    if (cnt > 0) {
        tab[r][c] = '*';
        PII res = backtrack(nr, nc, cnt-1);
        if (res.first != -1) return res;
    }
    tab[r][c] = '.';
    PII res = backtrack(nr, nc, cnt);
    if (res.first != -1) return res;
    return PII(-1,-1);
}

void solve(int cas) {
    cin >> R >> C >> m;
    REP(i, R) REP(j, C+1) tab[i][j] = '\0';
    REP(i, R) REP(j, C) tab[i][j] = '.';
    PII res = backtrack(0, 0, m);
    cout << "Case #" << cas << ":" << endl;
    //cout << R << " " << C << " " << m << endl;
    if (res.first == -1) {
        cout << "Impossible" << endl;
    } else {
        tab[res.first][res.second] = 'c';
        REP(i, R) cout << tab[i] << endl;
    }
}

int main() {
    int T;
    cin >> T;
    for(int cas = 1; cas <= T; cas++) {
        solve(cas);
    }
    return 0;
}
