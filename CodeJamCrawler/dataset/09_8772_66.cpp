#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
typedef pair<int,int> ii;

struct WaterShed
{
    int levelMatrix[105][105];
    int from[105][105][5];
    int to[105][105];
    int out[105][105];
    int w,h;

    enum {
        North = 1,
        West = 2,
        East = 3,
        South = 4
    };

    void input()
    {
        memset(levelMatrix, 0, sizeof levelMatrix);
        memset(from, 0, sizeof from);
        memset(to, 0, sizeof to);
        memset(out, 0, sizeof out);
        cin >> h >> w;
        for (int r = 1; r <= h; ++r) {
            for (int c = 1; c <= w; ++c) {
                cin >> levelMatrix[r][c];
            }
        }
    }

    void bfs(int r, int c, int a)
    {
        queue<ii> q;
        q.push(ii(r, c));
        ii last;
        while (!q.empty()) {
            ii v = q.front();
            q.pop();
            last = v;
            switch (to[v.first][v.second]) {
                case North: q.push(ii(v.first-1, v.second)); break;
                case West: q.push(ii(v.first, v.second-1)); break;
                case East: q.push(ii(v.first, v.second+1)); break;
                case South: q.push(ii(v.first+1, v.second)); break;
            }
        }

        q.push(last);
        while (!q.empty()) {
            ii v = q.front();
            q.pop();
            out[v.first][v.second] = a;
            if (from[v.first][v.second][North] == 1) {
                ii n = ii(v.first-1, v.second);
                if (out[n.first][n.second] == 0) {
                    q.push(n);
                }
            }
            if (from[v.first][v.second][West] == 1) {
                ii n = ii(v.first, v.second-1);
                if (out[n.first][n.second] == 0) {
                    q.push(n);
                }
            }
            if (from[v.first][v.second][East] == 1) {
                ii n = ii(v.first, v.second+1);
                if (out[n.first][n.second] == 0) {
                    q.push(n);
                }
            }
            if (from[v.first][v.second][South] == 1) {
                ii n = ii(v.first+1, v.second);
                if (out[n.first][n.second] == 0) {
                    q.push(n);
                }
            }
        }
    }

    void buildBasinMatrix()
    {
        int infinity = numeric_limits<int>::max();
        for (int r = 1; r <= h; ++r) {
            for (int c = 1; c <= w; ++c) {
                int north = r > 1 ? levelMatrix[r-1][c] : infinity;
                int west = c > 1 ? levelMatrix[r][c-1] : infinity;
                int east = c < w ? levelMatrix[r][c+1] : infinity;
                int south = r < h ? levelMatrix[r+1][c] : infinity;

                int value = min(min(north, west), min(east, south));
                if (value >= levelMatrix[r][c]) continue;
                if (value == north) {
                    to[r][c] = North;
                    from[r-1][c][South] = 1;
                } else if (value == west) {
                    to[r][c] = West;
                    from[r][c-1][East] = 1;
                } else if (value == east) {
                    to[r][c] = East;
                    from[r][c+1][West] = 1;
                } else {
                    to[r][c] = South;
                    from[r+1][c][North] = 1;
                }
            }
        }

        int alpha = 'a';
        for (int r = 1; r <= h; ++r) {
            for (int c = 1; c <= w; ++c) {
                if (out[r][c] == 0) {
                    bfs(r, c, alpha);
                    ++alpha;
                }
            }
        }
    }

    void output()
    {
        for (int r = 1; r <= h; ++r) {
            for (int c = 1; c <= w; ++c) {
                cout << (char)out[r][c] << " ";
            }
            cout << endl;
        }
    }
};



int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        WaterShed shed;
        shed.input();
        shed.buildBasinMatrix();
        cout << "Case #" << i << ":" << endl;
        shed.output();
    }
    return 0;
}

