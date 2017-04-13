#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    int TTT; cin >> TTT;
    for (int ZZZ = 1; ZZZ <= TTT; ZZZ++) {
        int R, C, D; cin >> R >> C >> D;
        int mat[11][11];
        for (int i=0; i < R; i++) {
            for (int j=0; j < C; j++) {
                char w; cin >> w;
                mat[i][j] = w - '0';
            }
        }
        
        int best = -1;
        long double eps = 1e-9;
        
        for (int w = 10; w >= 3; w--) {
            for (int i=0; i <= R-w; i++) {
                for (int j=0; j <= C-w; j++) {
                    long double cm_x = 0, cm_y = 0;
                    for (int ii = 0; ii < w; ii++) {
                        for (int jj = 0; jj < w; jj++) {
                            if ((ii == 0 && jj == 0) || (ii == 0 && jj == w-1) || (ii == w-1 && jj == 0) || (ii == w-1 && jj == w-1)) continue;
                            cm_x += (mat[i+ii][j+jj]) * ((w-1)/2.0-ii);
                            cm_y += (mat[i+ii][j+jj]) * ((w-1)/2.0-jj);
                        }
                    }
                    if (cm_x > -eps && cm_x < eps && cm_y < eps && cm_y > -eps) {
                        best = w;
                        goto end;
                    }
                }
            }
        }
        end:
        cout << "Case #" << ZZZ << ": ";
        if (best == -1) cout << "IMPOSSIBLE";
        else cout << best;
        cout << endl;
    }
}
