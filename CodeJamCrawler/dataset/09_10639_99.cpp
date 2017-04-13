#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>

using namespace std;

const int SIZE = 128;
int land[SIZE][SIZE];
int res[SIZE][SIZE];
int h, w;

// North, West, East, South.
const int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void rek(int x, int y)
{
  if (res[x][y] == -1)
  {
    int minH = land[x][y];
    for (int i = 0; i < 4; ++ i)
    {
      int nx = x + dir[i][0], ny = y + dir[i][1];
      if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if (land[nx][ny] < minH)
      {
        minH = land[nx][ny];
        rek(nx, ny);
        res[x][y] = res[nx][ny];
      }
    }
    if (minH == land[x][y])
    {
      res[x][y] = x * w + y;
    }
  }
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  scanf("%d", &t);
  for (int _c = 0; _c < t; ++ _c) {
    memset(res, -1, sizeof(res));
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; ++ i)
      for (int j = 0; j < w; ++ j)
        scanf("%d", land[i] + j);
    for (int i = 0; i < h; ++ i)
      for (int j = 0; j < w; ++ j)
        rek(i, j);
    map <int, char> mp;
    char c = 'a';
    for (int i = 0; i < h; ++ i)
      for (int j = 0; j < w; ++ j)
        if (mp.find(res[i][j]) == mp.end())
          mp[res[i][j]] = c ++;
    printf("Case #%d:\n", _c + 1);
    for (int i = 0; i < h; ++ i)
    {
      printf("%c", mp[res[i][0]]);
      for (int j = 1; j < w; ++ j)
        printf(" %c", mp[res[i][j]]);
      printf("\n");
    }
  }
  return 0;
}