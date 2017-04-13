#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long double ld;

const int SZ = 811111;
ld todo[SZ];
const ld EPS = 1e-8;

int main() {
    cout.precision(15);
    cout << fixed;
    int tcn; cin >> tcn;
    for (int tc = 1; tc <= tcn; ++tc) {
        ld c, f, x;
        cin >> c >> f >> x;
        todo[0] = 0;
        ld up = 2.L;
        ld curt = x / up;
        ld newt = x / up;
        int i = 0;
        do {
            curt = newt;
            todo[i + 1] = todo[i] + c / up;
            up += f;
            newt = x / up + todo[i + 1];
            ++i;
        } while (curt > newt + EPS);
        cout << "Case #" << tc << ": " << curt << endl;
    }
    return 0;
}
