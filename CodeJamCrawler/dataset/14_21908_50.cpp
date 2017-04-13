#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#define REP(i,n) for(int i = 0; i < (n); i++)

using namespace std;

void solve(int cas) {
    int n;
    cin >> n;
    vector<int> tab(n);
    vector<int> ord(n);
    REP(i, n) {
        cin >> tab[i];
        ord[i] = tab[i];
    }
    sort(ord.begin(), ord.end());
    int op = 0;
    REP(i, n) {
        int pos = -1;
        REP(j, tab.size()) {
            if (tab[j] == ord[i]) {
                pos = j;
                break;
            }
        }
        int val = min(pos, (int)tab.size() - 1 - pos);
        op += val;
        tab.erase(tab.begin() + pos);
    }
    cout << "Case #" << cas+1 << ": " << op << endl;
}

int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) solve(i);
    return 0;
}
