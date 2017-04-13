#include <stdio.h>
#include <iostream>
#define MAX 105
#define INF 0x3f3f3f3f
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define CLEAR(t) memset(t, 0, sizeof(t))

int h[MAX][MAX];
int edge[MAX][MAX];
int comp[MAX][MAX];
char label[MAX][MAX];
int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };

int fill(int y, int x) {
    int to = edge[y][x];
    if (comp[y][x] == 0) 
        comp[y][x] = fill(y+dy[to], x+dx[to]);
    return comp[y][x];
}

void relabel(int y, int x, char color) {
    if (label[y][x] != 0) return;
    label[y][x] = color;
    REP(dir, 4)
        if (comp[y][x] == comp[y+dy[dir]][x+dx[dir]])
            relabel(y+dy[dir], x+dx[dir], color);
}

int main() {
    FILE *fin = fopen("basin.in", "r"), *fout = fopen("basin.out", "w");

    int T; fscanf(fin, "%d", &T);
    REP(tests, T) {
        int H, W; fscanf(fin, "%d %d", &H, &W);
        FOR(i, 0, H+1) FOR(j, 0, W+1) h[i][j] = INF;
        FOR(i, 1, H) FOR(j, 1, W) fscanf(fin, "%d", &h[i][j]);
        
        FOR(i, 1, H) FOR(j, 1, W) {
            int dir = 0, drop = INF;
            REP(k, 4) {
                int val = h[i+dy[k]][j+dx[k]];
                if (val < drop) {
                    drop = val;
                    dir = k;
                }
            }
            if (drop >= h[i][j]) edge[i][j] = -1;
            else edge[i][j] = dir;
        }

        CLEAR(comp);
        int color = 1;
        FOR(i, 1, H) FOR(j, 1, W)
            if (edge[i][j] == -1) comp[i][j] = color++;

        FOR(i, 1, H) FOR(j, 1, W)
            if (comp[i][j] == 0) fill(i, j);

        CLEAR(label);
        color = 'a';
        FOR(i, 1, H) FOR(j, 1, W)
            if (label[i][j] == 0) relabel(i, j, color++);

        fprintf(fout, "Case #%d:\n", tests+1);
        FOR(i, 1, H) {
            FOR(j, 1, W) fprintf(fout, "%c ", label[i][j]);
            fprintf(fout, "\n");
        }
   }
    return 0;
}
