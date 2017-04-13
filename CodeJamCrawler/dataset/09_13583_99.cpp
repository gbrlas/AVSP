#include <iostream>
using namespace std;

int W, H;
int map[101][101];
char out[101][101];

char calc (int i, int j, char & cc) {

  if (out[i][j])
    return out[i][j];
  int m = map[i][j];
  int dx = 0;
  int dy = 0;
  if (i > 0 && map[i-1][j] < m) {
    m = map[i-1][j];
    dx = 0;
    dy = -1;
  }
  if (j > 0 && map[i][j-1] < m) {
    m = map[i][j-1];
    dx = -1;
    dy = 0;
  }
  if (j < W-1 && map[i][j+1] < m) {
    m = map[i][j+1];
    dx = 1;
    dy = 0;
  }
  if (i < H-1 && map[i+1][j] < m) {
    m = map[i+1][j];
    dx = 0;
    dy = 1;
  }
  if (dx || dy) {
    out[i][j] = calc(i+dy, j+dx, cc);
    return out[i][j];
  }
  /*
  if (i > 0 && map[i-1][j] == m && out[i-1][j]) {
    out[i][j] = out[i-1][j];
    return out[i][j];
  }
  if (j > 0 && map[i][j-1] == m && out[i][j-1]) {
    out[i][j] = out[i][j-1];
    return out[i][j];
  }
  if (j < W-1 && map[i][j+1] == m && out[i][j+1]) {
    out[i][j] = out[i][j+1];
    return out[i][j];
  }
  if (i < H-1 && map[i+1][j] == m && out[i+1][j]) {
    out[i][j] = out[i+1][j];
    return out[i][j];
  }
  */
  return out[i][j] = cc++;
}

int main () {

  int T;
  scanf("%d", &T);
  for (int c = 1; c <= T; ++c) {
    scanf("%d %d", &H, &W);
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
	out[i][j] = 0;
	scanf("%d", &map[i][j]);
      }
    }
    char cc = 'a';
    for (int i = 0; i < H; ++i)
      for (int j = 0; j < W; ++j)
	calc(i, j, cc);
    printf("Case #%d:\n", c);
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W-1; ++j)
	printf("%c ", out[i][j]);
      printf("%c\n", out[i][W-1]);
    }
  }
}
