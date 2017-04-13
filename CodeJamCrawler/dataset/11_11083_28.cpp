#include <iostream>
using namespace std;

int main() {
    int T, R, C;
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> R >> C;
        char tab[R][C];

        for(int j = 0; j < R; j++) {
            for(int k = 0; k < C; k++) {
                cin >> tab[j][k];
            }
        }

        bool ok = true;
        for(int j = 0; j < R; j++) {
            for(int k = 0; k < C; k++) {
                if(tab[j][k] == '#') {
                    tab[j][k] = '/';
                    if(k + 1 < C && tab[j][k + 1] == '#') tab[j][k + 1] = '\\'; else ok = false;
                    if(j + 1 < R && tab[j + 1][k] == '#') tab[j + 1][k] = '\\'; else ok = false;
                    if(j + 1 < R && k + 1 < C && tab[j + 1][k + 1] == '#') tab[j + 1][k + 1] = '/'; else ok = false;
                }
            }
        }


        for(int j = 0; j < R; j++) {
            for(int k = 0; k < C; k++) {
                if(tab[j][k] == '#') ok = false;
            }
        }

        if(ok) {
            cout << "Case #" << (i + 1) << ":" << endl;
            for(int j = 0; j < R; j++) {
                for(int k = 0; k < C; k++) {
                    cout << tab[j][k];
                }
                cout << endl;
            }
        } else cout << "Case #" << (i + 1) << ":" << endl << "Impossible" << endl;
    }

    return 0;
}
