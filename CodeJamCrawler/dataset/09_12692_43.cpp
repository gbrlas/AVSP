#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int T;
    int H, W;
    cin >> T;
    for(int ca = 1; ca <= T; ca++) {
    cin >> H >> W;
    int a[110][110];
    char r[110][110];
    memset(r, 0, sizeof(r));
    int xx[4] = { 0,-1, 1, 0};
    int yy[4] = {-1, 0, 0, 1};
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> a[i][j];
        }
    }
    char now = 'a';
    r[0][0] = now;
    int tot = 0;
    while(tot < H * W) {
    tot =0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            int sink = 1, min = 10100, sinkx = -1, sinky = -1;
            for(int k = 0; k < 4; k++) {
                int ii = i + yy[k];
                int jj = j + xx[k];
                if(ii < 0 || ii >= H || jj < 0 || jj >= W)
                    continue;
                if(a[ii][jj] < a[i][j] && a[ii][jj] < min) {
                    sink = 0;
                    min = a[ii][jj];
                    sinkx = ii;
                    sinky = jj;
                }
            }
           // cout << "i: " << i << "j: " << j << "sinkx: " << sinkx << "sinky: " << sinky << endl;
            if(sink == 1 && r[i][j] == 0) {
                now++;
                r[i][j] = now;
                continue;
            }
            if(r[i][j] == 0 && r[sinkx][sinky] != 0) {
                r[i][j] = r[sinkx][sinky];
                continue;
            }
        //    if(r[i][j] == 0 && r[sinkx][sinky] == 0) {
        //        now++;
        //        r[i][j] = r[sinkx][sinky] = now;
        //        continue;
        //    }
            if(r[i][j] != 0 && r[sinkx][sinky] == 0) {
                r[sinkx][sinky] = r[i][j];
            }
        }
    }
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(r[i][j] != 0)
                tot++;
        }
    }
    }

    cout << "Case #" << ca << ": " << endl;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cout << r[i][j] << " ";
        }
        cout << endl;
    }
    }
    return 0;
}
