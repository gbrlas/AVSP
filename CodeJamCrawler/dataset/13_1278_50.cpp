#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    ofstream f("a.txt");
    int k = 1;
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        int h = -1;
        int a[n][m];
        int final = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &a[i][j]);
                if (a[i][j] > h) {
                    h = a[i][j];
                }
            }
        }

        if (h == 1) {
            goto l;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cr = 0;
                int cc = 0;
                if (a[i][j] < h) {
                    for (int k = 0; k < n; k++) {
                        if (a[k][j] > a[i][j]) {
                            cr++;
                        }
                    }
                    for (int x = 0; x < m; x++) {
                        if (a[i][x] > a[i][j]) {
                            cc++;
                        }
                    }
                    if (cr > 0 && cc > 0) {
                        final = -1;
                        goto l;
                    }

                }
            }
        }
        l:
            if (final == 0) {
                cout << "Case #" << k++ << ": YES\n";
                f << "Case #" << k - 1 << ": YES\n";
            } else if (final == -1) {
                cout << "Case #" << k++ << ": NO\n";
                f << "Case #" << k - 1 << ": NO\n";
            }
    }
    return 0;
}