#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>
#include <iomanip>

#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(u) (u).begin(), (u).end()

using namespace std;

typedef long double K;

void solve(int cas) {
    K c, f, x;
    cin >> c >> f >> x;
    K now = 0;
    K dps = 2;
    K result = 1e9;
    for(int il = 0; il <= x; il++) {
        result = min(result, now + x / dps);
        K to_farm = c / dps;
        now += to_farm;
        dps += f;
    }
    cout << setprecision(7) << fixed;
    cout << "Case #" << cas << ": " << result << endl;
}

int main() {
    int T;
    cin >> T;
    for(int cas = 1; cas <= T; cas++) {
        solve(cas);
    }
    return 0;
}
