#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FOR(i, n) for (int i = 0; i < n; i++)

using namespace std;

int main()
{
    int T, A, B, digits, p, x, f, n, nope;
    vector<int> used;

    cin >> T;
    FOR (t, T) {
        cout << "Case #" << t + 1 << ": ";
        cin >> A;
        cin >> B;
        digits = 0;
        p = 1;
        FOR (i,100) {
            if (A < p)
                break;
            digits++;
            p *= 10;
        }
        p /= 10;
        n = 0;
        for (int i = A; i <= B; i++) {
            x = i;
            used.clear();
            for (int j = 0; j < digits - 1; j++) {
                f = x / p;
                x = (x - f * p) * 10;
                x += f;
                if (x > i && x <= B) {
                    nope = 0;
                    FOR (k, used.size())
                        if (used[k] == x)
                            nope = 1;
                    if (!nope)
                        n++;
                    used.push_back(x);
                    //cout << i << " " << x << endl;
                }
            }
        }
        cout << n;
        cout << endl;
    }
    return 0;
}
