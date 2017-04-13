#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#define REP(i,n) for(int i = 0; i < (n); i++)

using namespace std;

void solve(int cas) {
    int n, S;
    cin >> n >> S;
    vector<int> tab(n);
    REP(i, n) {
        cin >> tab[i];
    }
    sort(tab.begin(), tab.end());
    int first = 0, last = tab.size() - 1;
    int res = 0;
    while(last >= first) {
        if (last == first) {
            res++;
            break;
        }
        while(last > first and tab[last] + tab[first] > S) {
            res++;
            last--;
        }
        if (last > first and tab[last] + tab[first] <= S) {
            res++;
            last--;
            first++;
        }
    }
    cout << "Case #" << cas+1 << ": " << res << endl;
}

int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) solve(i);
    return 0;
}
