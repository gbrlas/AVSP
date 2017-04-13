/* 
 * File:   b.cc
 * Author: cain
 *
 * Created on 4 Сентябрь 2009 г., 1:37
 */

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#define mp make_pair
#define X first
#define Y second
using namespace std;
int q[100][100];
pair<int, int> a[100][100];

pair<int, int> get(int x, int y) {
    pair<int, int> tt = a[x][y], bb = mp(x, y);
    return (tt == bb) ? bb : a[x][y] = get(tt.X, tt.Y);
}

void conc(int x1, int y1, int x2, int y2) {
    pair<int, int> a1, a2;
    a1 = get(x1, y1);
    a2 = get(x2, y2);
    if (a1 != a2)
        if (rand() & 1)
            a[a1.X][a1.Y] = a2;
        else
            a[a2.X][a2.Y] = a1;
}

int dx[] = {0, -1, 0, 0, 1}, dy[] = {0, 0, -1, 1, 0};

/*
 * 
 */
int main(int argc, char** argv) {
    int t;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;

    for (int z = 0; z < t; ++z) {
        map<pair<int, int>, char> r;
        for (int i = 0; i < 100; ++i)
            for (int j = 0; j < 100; ++j)
                a[i][j] = mp(i, j);
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> q[i][j];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                int minx = i, miny = j;
                //                cerr << i << ' ' << j << ' ' << q[i][j];
                for (int k = 1; k < 5; ++k) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    //                    cerr << ' ' << nx << ' ' << ny << ' ' << q[nx][ny];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (q[nx][ny] < q[minx][miny])
                        minx = nx, miny = ny;
                }
                //                 cerr << ' ' << minx << ' ' << miny << ' ' << q[minx][miny] << endl;
                conc(i, j, minx, miny);
            }
        char er = 'a';
        cout << "Case #" << z + 1 << ":\n";
        for (int i = 0; i < n; ++i) {


            for (int j = 0; j < m; ++j) {
                if (r[get(i, j)] == 0)
                    r[get(i, j)] = er++;
                if (j) cout << ' ';
                cout << r[get(i, j)];
            }
            cout << endl;
        }
    }
    return (EXIT_SUCCESS);
}

