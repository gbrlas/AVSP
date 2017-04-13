#include <iostream>

using namespace std;

long long getint() {
    char ch;
    do {
        cin >> ch;
    } while (ch < '0' || ch > '9');
    return ch - '0';
}

int R, C, D;
long long a[551][551];
long long mass[551][551];
long long X[551][551];
long long Y[551][551];

int solve() {
    cin >> R >> C >> D;
    
    for (int i = 0; i <= R; i++) {
        for (int j = 0; j <= C; j++) {
            if (i == 0 || j == 0) {
                a[i][j] = 0;
            } else {
                a[i][j] = getint() + D;
            }
        }
    }
    
    for (int i = 0; i <= R; i++) {
        for (int j = 0; j <= C; j++) {
            if (i == 0 || j == 0) {
                mass[i][j] = 0;
                X[i][j] = 0;
                Y[i][j] = 0;
            } else {
                mass[i][j] = mass[i - 1][j] + mass[i][j - 1] - mass[i - 1][j - 1] + a[i][j];
                X[i][j] = X[i - 1][j] + X[i][j - 1] - X[i - 1][j - 1] + i * a[i][j];
                Y[i][j] = Y[i - 1][j] + Y[i][j - 1] - Y[i - 1][j - 1] + j * a[i][j];
            }
        }
    }
    
    for (int k = min(R, C); k >= 3; k--) {
        for (int i = 0; i <= R - k; i++) {
            for (int j = 0; j <= C - k; j++) {
                long long Umass = mass[i + k][j + k] - mass[i + k][j] - mass[i][j + k] + mass[i][j];
                long long UX = X[i + k][j + k] - X[i + k][j] - X[i][j + k] + X[i][j];
                long long UY = Y[i + k][j + k] - Y[i + k][j] - Y[i][j + k] + Y[i][j];
                Umass -= a[i + 1][j + 1] + a[i + 1][j + k] + a[i + k][j + 1] + a[i + k][j + k];
                UX -= a[i + 1][j + 1] * (i + 1) + a[i + 1][j + k] * (i + 1) + a[i + k][j + 1] * (i + k) + a[i + k][j + k] * (i + k);
                UY -= a[i + 1][j + 1] * (j + 1) + a[i + 1][j + k] * (j + k) + a[i + k][j + 1] * (j + 1) + a[i + k][j + k] * (j + k);
                if (2 * UX == (2 * i + k + 1) * Umass && 2 * UY == (2 * j + k + 1) * Umass) return k;
            }
        }
    }
    
    return 0;
}

int T;

int main() {
    freopen("B-large.in.txt", "r", stdin);
    
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        int ret = solve();
        if (ret > 0) {
            cout << ret;
        } else {
            cout << "IMPOSSIBLE";
        }
        cout << endl;
    }
    return 0;
}
