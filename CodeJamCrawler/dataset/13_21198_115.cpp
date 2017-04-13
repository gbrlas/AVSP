#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i, n) for(int i = 0;i<n;i++)
#define ALL(u) u.begin(),u.end()

struct field {
    int row, col, h;
    bool operator<(field a) const {
        return h < a.h;
    }
};

typedef vector <vector <int> > M;

bool execute(field f, M & t) {
    bool success = false;
    {
        bool ok = true;
        REP(i, t.size()) {
            if (t[i][f.col] > f.h) {
                ok = false;
                break;
            }
        }
        if (ok) success = true;
    }
    {
        bool ok = true;
        REP(i, t[0].size()) {
            if (t[f.row][i] > f.h) {
                ok = false;
                break;
            }
        }
        if (ok) success = true;
    }
    return success;
}

void yes(int cas) {
    cout << "Case #" << cas << ": YES" << endl;
}

void no(int cas) {
    cout << "Case #" << cas << ": NO" << endl;
}

void solve(int cas) {
    vector <vector<int> > t;
    int n, m;
    cin >> n >> m;
    t.resize(n, vector<int> (m, 0));
    vector <field> V;
    REP(i, n) REP(j, m) {
        cin >> t[i][j];
        field f;
        f.row = i; f.col = j; f.h = t[i][j];
        V.push_back(f);
    }
    sort(ALL(V));
    REP(i, V.size()) {
        field f = V[i];
        if (!execute(f, t)) {
            no(cas);
            return;
        }
    }
    yes(cas);
}

int main() {
    int T;
    cin >> T;
    REP(i, T) solve(i+1);
    return 0;
}
