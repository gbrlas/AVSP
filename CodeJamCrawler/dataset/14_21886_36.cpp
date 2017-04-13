#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>

#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(u) (u).begin(), (u).end()

using namespace std;

set<int> getset() {
    int ans;
    int tab[4][4];
    cin >> ans;
    REP(i, 4) REP(j, 4) cin >> tab[i][j];
    set<int> S;
    REP(i, 4) S.insert(tab[ans-1][i]);
    return S;
}

void solve(int cas) {
    set<int> A = getset();
    set<int> B = getset();
    set<int> I;
    vector<int> res;
    set_intersection(ALL(A), ALL(B), std::back_inserter(res));
    if (res.size() == 1) {
        cout << "Case #" << cas << ": " << res[0] << endl;
    } else if (res.size() > 1) {
        cout << "Case #" << cas << ": Bad magician!" << endl;
    } else {
        cout << "Case #" << cas << ": Volunteer cheated!" << endl;
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
