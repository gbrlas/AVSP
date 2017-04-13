#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n, m;
        cin >> n >> m;
        vector <vector <int> > field(n, vector <int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; j++) {
                cin >> field[i][j];
            }
        }

        bool ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int mx = 0;
                for (int k = 0; k < n; k++) {
                    mx = max(mx, field[k][j]);
                }

                bool curOk = false;

                if (mx <= field[i][j])
                    curOk = true;

                mx = 0;

                for (int k = 0; k < m; k++) {
                    mx = max(mx, field[i][k]);
                }

                if (mx <= field[i][j])
                    curOk = true;

                if (!curOk)
                    ok = false;
            }
        }

        cout << "Case #" << (t + 1) << ": " << (ok ? "YES" : "NO") << endl;        
    }
}