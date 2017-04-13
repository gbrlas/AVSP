#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include <cmath>
#include <cassert>
#include <iomanip>

using namespace std;

// --------------------- Template ---------------------------------------------

#define FOR(i, f, t) for (int i = (int)(f); i < (int)(t); ++i)
#define FORN(i, n) for (int i = 0; i < (int)(n); ++i)

template <class T, class IT>
inline void PRINT(IT i1, IT i2) {
    cout << '['; copy(i1, i2, ostream_iterator<T>(cout, ", ")); cout << "]\n";
}

#if defined(M_H_HOME) && (0)
#define DBG(x) (x)
#else
#define DBG(x)
#endif

typedef long long ll;
typedef long double ld;

// ------------------ Template end --------------------------------------------

struct walkway {
    ll B, E, len, w;
};

ld try_move(ll dist, ll v) {
    return 1.0 * dist / v;
}

bool compf(const walkway& a, const walkway& b) {
    return a.w < b.w;
}

#if 1
int main() {

#if defined(M_H_HOME) && (0)
    ifstream ___ifs("a.in.1");
    cin.rdbuf(___ifs.rdbuf());
#endif

    ll T;
    ll X, S, R, t, N;
    walkway walkways[1111]; 

    cin >> T;
    for (int casen = 1; casen <= T; ++ casen) {
        cin >> X >> S >> R >> t >> N;

        ll total_ww_length = 0;
        FORN(i, N) {
            cin >> walkways[i].B >> walkways[i].E >> walkways[i].w;
            walkways[i].len = walkways[i].E - walkways[i].B;
            total_ww_length += walkways[i].len;
        }
        walkways[N].B = 0;
        walkways[N].E = X - total_ww_length;
        walkways[N].len = walkways[N].E - walkways[N].B;
        walkways[N].w = 0;
        ++N;
        sort(walkways, walkways + N, compf);

        ld walking_time = 0;
        ld t_left = t;
        FORN(i, N) { 
            if (try_move(walkways[i].len, walkways[i].w + R) <= t_left) {
                walking_time += 1.0 * (walkways[i].len) / (walkways[i].w + R);
                t_left -= try_move(walkways[i].len, walkways[i].w + R);
            } else {
                ld l1 = t_left * (walkways[i].w + R);
                walking_time += t_left + (1.0 * walkways[i].len - l1) / (walkways[i].w + S);
                t_left = 0;
            }
        }
        cout << "Case #" << casen << ": " << setprecision(12) << fixed << walking_time << '\n';
    }
    return 0;
}
#endif
