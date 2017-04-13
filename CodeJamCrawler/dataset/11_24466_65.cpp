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

#define MAX 55

int T, R, C;

char ifield[MAX][MAX];
char ofield[MAX][MAX];



#if 1
int main() {


    cin >> T;
    FORN(casen, T) {

        FORN(i, MAX) FORN(j, MAX) { ifield[i][j] = ofield[i][j] = '.'; }

        cin >> R >> C;
        string s;
        FORN(i, R) {
            cin >> s;
            FOR(j, 0, s.size()) ifield[i+1][j+1] = s[j];
        }

        bool possible = true;
        int icount = 0;
        int tcount = 0;

        FOR(i, 1, R + 1)
            FOR(j, 1, C + 1) {
            ofield[i][j] = ifield[i][j];
            if (ofield[i][j] == '#') ++icount;
            if (ofield[i][j] == '#' && ofield[i-1][j] == '#' && ofield[i][j-1] == '#' && ofield[i-1][j-1] == '#') {
                ofield[i][j] = '/';
                ofield[i-1][j] = '\\';
                ofield[i][j-1] = '\\';
                ofield[i-1][j-1] = '/';
                tcount += 4;
            }
        }

        //cout << icount << " " << tcount << endl;

        cout << "Case #" << casen + 1 << ":\n";
        if (icount == tcount) {
            FORN(i, R) {
                FORN(j, C) {
                    cout << ofield[i+1][j+1];
                }
                cout << '\n';
            }
        } else {
            cout << "Impossible\n";
        }
    }

    return 0;
}
#endif
