#include <algorithm>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <vector>

#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int N = 64;
const long double EPS = 1e-10;

long double prob[2][N];
long double newton[N][N];

void precomp()
{
  for (int i = 0; i <= N; ++ i)
  {
    newton[i][0] = 1;
    for (int j = 1; j <= i; ++ j)
      newton[i][j] = newton[i - 1][j - 1] + newton[i - 1][j];
  }
}

inline long double fract(int X, int Y, int x, int y)
{
  return newton[X][x] * newton[Y][y] / newton[X + Y][x + y];
}

int main(int argc, char *argv[])
{
  int casesNumber;
  scanf("%d", &casesNumber);
  precomp();
  for (int __tc = 0; __tc < casesNumber; ++ __tc)
  {
    int c, n;
    scanf("%d %d", &c, &n);
    memset(prob, 0, sizeof(prob));
    long double ans = 0;
    prob[0][0] = 1;
    for (int mov = 0; ; ++ mov)
    {
      int cr = mov % 2;
      int nx = !cr;
      long double s = mov * prob[cr][c];
      if (mov > 128 && s < EPS) break;
      ans += s;

      memset(prob[nx], 0, sizeof(prob[nx]));
      for (int i = 0; i < c; ++ i)
        if (prob[cr][i])
        {
          for (int j = 0; j <= i && j <= n; ++ j)
            prob[nx][i + n - j] += fract(i, c - i, j, n - j) * prob[cr][i];
        }
    }
    printf("Case #%d: %Lf\n", __tc + 1, ans);
  }
  return 0;
}
