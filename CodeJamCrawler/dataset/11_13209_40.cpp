#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void printTiles(const vector<string> &tiles) {
    for (int i = 0; i < tiles.size(); ++i) {
        cout<<tiles[i]<<endl;
    }
}
bool changeTile(vector<string> &tiles, int r, int c) {
    if (r + 1 >= tiles.size() || c + 1 >= tiles[r].size()) {
        return false;
    }
    for (int i = r; i <= r + 1; ++i) {
        for (int j = c; j <= c + 1; ++j) {
            if (tiles[i][j] != '#') {
                return false;
            }
        }
    }
    tiles[r    ][c    ] = '/';
    tiles[r    ][c + 1] = '\\';
    tiles[r + 1][c    ] = '\\';
    tiles[r + 1][c + 1] = '/';
    return true;
}
int main() {
    int T;
    cin>>T;

    for (int tt = 1; tt <= T; tt++) {
        int R, C;
        cin>>R>>C;

        vector<string> tiles(R);
        for (int i = 0; i < R; ++i) {
            cin>>tiles[i];
        }

        bool possible = true;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (tiles[i][j] == '#') {
                    if (!changeTile(tiles, i, j)) {
                        possible = false;
                        goto END;
                    }
                }
            }
        }

    END:
        cout<<"Case #"<<tt<<":"<<endl;
        if (possible) {
            printTiles(tiles);
        }
        else {
            cout<<"Impossible"<<endl;
        }
    }

    return 0;
}
