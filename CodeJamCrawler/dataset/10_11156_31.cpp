#include <cstdio>
#include <cstring>

using namespace std;

const int N = 512;
int mas[N][N];

bool update() {
  bool end = true;
  for (int i = N - 1; i >= 1; -- i) {
    for (int j = N - 1; j >= 1; -- j) {
      if (mas[i][j]) {
        end = false;
      }
      if (mas[i][j] && !mas[i - 1][j] && !mas[i][j - 1]) {
        mas[i][j] = 0;
      }
      if (!mas[i][j] && mas[i - 1][j] && mas[i][j - 1]) {
        mas[i][j] = 1;
      }
    }
  }
  return !end;
}

void fill(int x1, int y1, int x2, int y2) {
  for (int i = x1; i <= x2; ++ i) {
    for (int j = y1; j <= y2; ++ j) {
      mas[i][j] = 1;
    }
  }
}

int main()
{
  int tests;
  scanf("%d", &tests);
  for (int tc = 1; tc <= tests; ++ tc) {
    memset(mas, 0, sizeof(mas));
    int r;
    scanf("%d", &r);
    for (int i = 0; i < r; ++ i) {
      int x1, y1, x2, y2;
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
      fill(x1, y1, x2, y2);
    }
    int ans;
    for (ans = 0; update(); ++ ans);
    printf("Case #%d: %d\n", tc, ans);
  }
  return 0;
}
