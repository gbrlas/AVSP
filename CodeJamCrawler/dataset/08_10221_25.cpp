#include <cstdio>
#include <algorithm>
#include <cstring>
#include <deque>
using namespace std;

const int UP = 0;
const int LEFT = 1;
const int DOWN = 2;
const int RIGHT = 3;

const int SIZE = 6100;

int left(int dir) {
  return (dir + 1) % 4;
}

int right(int dir) {
  return (dir + 3) % 4;
}

char tab[SIZE][SIZE][4];
int mark[SIZE][SIZE];

int minx[SIZE];
int maxx[SIZE];
int miny[SIZE];
int maxy[SIZE];
int glminx, glminy, glmaxx, glmaxy;

pair<short, short> Q[SIZE * SIZE];

int main() {
  int zz;
  scanf("%d", &zz);

  for (int z = 1; z <= zz; ++z) {

    for (int i = 0; i < SIZE; ++i)
      for (int j = 0; j < SIZE; ++j) {
        mark[i][j] = 0;
        for (int k = 0; k < 4; ++k)
          tab[i][j][k] = 0;
      }

    for (int i = 0; i < SIZE; ++i) {
      maxx[i] = maxy[i] = -10000;
      minx[i] = miny[i] = 10000;
    }

    int L;
    scanf("%d", &L);
    int posx = SIZE / 2, posy = SIZE / 2;
    glmaxx = glminx = posx;
    glmaxy = glminy = posy;
    int dir = UP;

    for (int i = 0; i < L; ++i) {
      char S[SIZE];
      int T;
      scanf("%s%d", S, &T);

      int len = strlen(S);

      for (int j = 0; j < T; ++j) {
        for (int k = 0; k < len; ++k) {
          if (S[k] == 'L')
            dir = left(dir);
          else if (S[k] == 'R')
            dir = right(dir);
          else {
            if (dir == UP) {
              minx[posy] = min(minx[posy], posx);
              maxx[posy] = max(maxx[posy], posx);
              tab[posx][posy][LEFT] = 1;
              tab[posx - 1][posy][RIGHT] = 1;
              ++posy;
            } else if (dir == DOWN) {
              --posy;
              minx[posy] = min(minx[posy], posx);
              maxx[posy] = max(maxx[posy], posx);
              tab[posx][posy][LEFT] = 1;
              tab[posx - 1][posy][RIGHT] = 1;
            } else if (dir == LEFT) {
              --posx;
              miny[posx] = min(miny[posx], posy);
              maxy[posx] = max(maxy[posx], posy);
              tab[posx][posy][DOWN] = 1;
              tab[posx][posy - 1][UP] = 1;
            } else {
              miny[posx] = min(miny[posx], posy);
              maxy[posx] = max(maxy[posx], posy);
              tab[posx][posy][DOWN] = 1;
              tab[posx][posy - 1][UP] = 1;
              ++posx;
            }

            glmaxx = max(glmaxx, posx + 1);
            glminx = min(glminx, posx - 1);
            glmaxy = max(glmaxy, posy + 1);
            glminy = min(glminy, posy - 1);
          }
        }
      }
    }

    mark[glminx-1][glminy-1] = 1;
    int qs = 0, qe = 0;
    Q[qe] = make_pair<short, short>(glminx-1, glminy-1);
    ++qe;

    while (qe != qs) {
      pair<int, int> p = Q[qs];
      ++qs;

      int dx[] = { 0, -1, 0, 1 };
      int dy[] = { 1, 0, -1, 0 };

      for (int dir = 0; dir < 4; ++dir) {
        if (!tab[p.first][p.second][dir]) {
          int nx = p.first + dx[dir];
          int ny = p.second + dy[dir];

          if (nx < glminx -1 || nx > glmaxx || ny < glminy-1 || ny > glmaxy || mark[nx][ny] != 0)
            continue;

          mark[nx][ny] = 1;
          Q[qe] = make_pair<short, short>(nx, ny);
          ++qe;
        }
      }
    }
      
    int res = 0;

    for (int x = 0; x < SIZE; ++x) {
      for (int y = 0; y < SIZE; ++y) {
        if (mark[x][y]) {
          if (y >= miny[x] && y < maxy[x])
            ++res;
          else if (x >= minx[y] && x < maxx[y])
            ++res;
        }
      }
    }

    printf("Case #%d: %d\n", z, res);
  }

  return 0;
}