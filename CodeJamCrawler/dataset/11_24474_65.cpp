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

#define MAX_C 1000100
#define MAX_N 1000100
typedef long long ll;

int T, C, N, L;
ll t;

ll a[MAX_C];
ll d[MAX_N];  // расстояние от i до i+1

#if 1
int main() {

    cin >> T;
    FORN(casen, T) {
        cin >> L >> t >> N >> C;
        FORN(i, C) cin >> a[i];
        ll all = 0;
        for (int i = 0; i < N; ++i) {
            d[i] = a[i % C];
            all += d[i] * 2;
        }

        //PRINT<ll>(d, d + N);

        ll ans;

        ll lapsed = 0;
        int current = 0;
        // current - первая звезда, на скорость отлета с которой
        // может повлиять бустер
        while (current < N && lapsed + d[current] * 2 <= t) {
            lapsed += d[current] * 2;
            ++current;
        }

        //cout << all << '\n';
        //cout << "Boundary star - " << current << '\n';

        if (current == N) {
            ans = lapsed;
        } else if (L > 0) {
            // создадим массив ожидаемых уменьшений времени от
            // использования бустера на звезде
            vector<ll> bonus;
            // для пограничной звезды
            //bonus.push_back(d[current] - (t - lapsed) / 2);
            //cout << "time ordinary:" << t - lapsed << '\n';
            //cout << "distance left: " << d[current] - (t - lapsed) / 2 << '\n';
            bonus.push_back(d[current] - (t - lapsed) / 2);
            // для остальных
            FOR(i, current + 1, N) {
                bonus.push_back(d[i]);
            }
            sort(bonus.begin(), bonus.end(), greater<ll>());
            //PRINT<ll>(bonus.begin(), bonus.end());
            ll economy = 0;
            for (int i = 0; i < bonus.size() && i < L; ++i) {
                economy += bonus[i];
            }
            //PRINT<ll>(bonus.begin(), bonus.end());

            ans = all - economy/* + (t - lapsed)*/;
        } else {
            ans = all;
        }

        cout << "Case #" << casen + 1 << ": " << ans << endl;

    }

    return 0;
}
#endif
