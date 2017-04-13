#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
using namespace std;

ifstream fin("B-large.in");
ofstream fout("B-large.out");

int t;
int h, w;
int map[101][101], f[10001], rank[10001];
char g[101][101];
int dirc[4][2] = {
    {-1, 0},
    {0, -1},
    {0, 1},
    {1, 0}
};

int find(int x) {
    if (f[x] == x) return x;
    else {
        f[x] = find(f[x]);
        return f[x];
    }
}

void merge(int a, int b) {
    if (rank[a] > rank[b]) f[b] = a;
    else {
        f[a] = b;
        if (rank[a] == rank[b]) rank[b]++;
    }
}

bool inbound(int x, int y) {
    if (x >= 1 && x <= h && y >= 1 && y <= w) return true;
    return false;
}

int main() {
    fin >> t;
    for (int o = 1; o <= t; o++) {
        fin >> h >> w;
        for (int i = 1; i <= h; i++)
            for (int j = 1; j <= w; j++) fin >> map[i][j];
        for (int i = 1; i <= h * w; i++) f[i] = i;
        memset(rank, 0, sizeof (rank));
        int tx, ty;

        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                int minh = map[i][j];
                int mind = -1;
                for (int k = 0; k < 4; k++) {
                    tx = i + dirc[k][0];
                    ty = j + dirc[k][1];
                    if (inbound(tx, ty) && map[tx][ty] < minh) {
                        minh = map[tx][ty];
                        mind = k;
                    }
                }
                if (mind != -1) {
                    tx = i + dirc[mind][0];
                    ty = j + dirc[mind][1];
                    merge(find((i - 1) * w + j), find((tx - 1) * w + ty));
                    continue;
                }
                mind = 1;
            }
        }


        for (int i=1;i<=h;i++)
            for (int j=1;j<=w;j++)
                f[(i-1)*w+j]=find(f[(i-1)*w+j]);
        char ch = 'a';
        int now = f[1], count;
        count = 0;
        while (true) {
            for (int i = 1; i <= h; i++)
                for (int j = 1; j <= w; j++)
                    if (f[(i - 1) * w + j] == now) {
                        g[i][j] = ch;
                        f[(i-1)*w+j]=-1;
                        count++;
                    }
            for (int i = 1; i <= h; i++)
                for (int j = 1; j <= w; j++)
                    if (f[(i - 1) * w + j] != now&&f[(i-1)*w+j]!=-1){
                        now = f[(i - 1) * w + j];
                        goto label;
                    }
            label: ch++;
            if (count==w*h) break;
        }
        fout << "Case #" << o << ":" << endl;
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++) fout << g[i][j]<<" ";
            fout<<endl;
        }
    }
    return 0;
}
