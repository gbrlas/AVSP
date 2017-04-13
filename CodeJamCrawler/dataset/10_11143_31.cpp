#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1024;
const int P = 16;
int n, p;
int mas[P][N][P];

void opt(int i1, int i2, int i3, int val) {
  //printf("mas %d %d %d -> %d\n", i1, i2, i3, val);
  if (mas[i1][i2][i3] == -1 || mas[i1][i2][i3] > val) {
    mas[i1][i2][i3] = val;
  }
}

int main()
{
  int tests;
  scanf("%d", &tests);
  for (int tc = 1; tc <= tests; ++ tc) {
    scanf("%d", &p);
    memset(mas, -1, sizeof(mas));
    n = (1 << p);
    for (int i = 0; i < n; ++ i) {
      int t;
      scanf("%d", &t);
      mas[0][i][t] = 0;
    }

    int c = n;
    for (int i = 1; i <= p; ++ i)
    {
      c /= 2;
      for (int j = 0; j < c; ++ j)
      {
        int pr;
        scanf("%d", &pr);
        int l = j * 2, r = l + 1;
        for (int x = 0; x <= p; ++ x) {
          for (int y = 0; y <= p; ++ y) {
            //printf("%d %d %d %d\n", i, j, x, y);
            int v1 = mas[i - 1][l][x];
            int v2 = mas[i - 1][r][y];
            if (v1 == -1 || v2 == -1) {
              continue;
            }
            int z = min(x, y);
            opt(i, j, z, pr + v1 + v2);
            if (z > 0) {
              opt(i, j, z - 1, v1 + v2);
            }
          }
        }
      }
    }

    int ans = (1 << 30);
    for (int i = 0; i < p; ++ i) {
      if (mas[p][0][i] != -1) {
        ans = min(mas[p][0][i], ans);
      }
    }
    printf("Case #%d: %d\n", tc, ans);
  }
  return 0;
}
