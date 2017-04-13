#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <cmath>
#include <iomanip>

using namespace std;

// --------------------- Template ---------------------------------------------

#define FOR(i, f, t) for (int i = (int)(f); i < (int)(t); ++i)
#define FORN(i, n) for (int i = 0; i < (int)(n); ++i)

template <class T, class IT>
inline void PRINT(IT i1, IT i2) {
    cout << '['; copy(i1, i2, ostream_iterator<T>(cout, ", ")); cout << "]\n";
}

// ------------------ Template end --------------------------------------------

int T, N, L, H;
int fr[111];

#if 1
int main() {

    cin >> T;
    FORN(casen, T) {
        cin >> N >> L >> H;
        FORN(i, N) cin >> fr[i];

        bool found = false;
        int res;
        for (int cand = L; !found && (cand <= H); ++cand) {
            bool f1 = true;
            FORN(i, N) {
                f1 = f1 && ((cand % fr[i] == 0) || (fr[i] % cand == 0));
            }
            if (f1) {
                res = cand; found = true;
            }
        }

        cout << "Case #" << casen + 1 << ": ";
        if (!found) cout << "NO\n"; else cout << res << "\n";

    }

    return 0;
}
#endif
