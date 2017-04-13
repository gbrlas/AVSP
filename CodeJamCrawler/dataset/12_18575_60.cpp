#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FOR(i, n) for (int i = 0; i < n; i++)

using namespace std;

int main()
{
    int T, N, S, p, x, res, maybe;

    cin >> T;
    FOR (t, T) {
        cout << "Case #" << t + 1 << ": ";
        cin >> N;
        cin >> S;
        cin >> p;
        res = 0;
        maybe = 0;
        FOR (i,N) {
            cin >> x;
            if (x >= 3*p - 2)
                res++;
            else if (p > 1 && x >= 3*p - 4)
                maybe++;
        }
        if (maybe > S)
            res += S;
        else
            res += maybe;
        cout << res;
        cout << endl;
    }
    return 0;
}
