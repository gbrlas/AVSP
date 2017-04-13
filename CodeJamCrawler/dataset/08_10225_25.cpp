#include <cstdio>
#include <algorithm>
using namespace std;

int n_tab[110][110];

const int MOD = 10007;

int newton(int a, int b) {
//  printf("newton %d %d\n", a, b);
  if (b == 0)
    return 1;
  if (a <= 0)
    return 0;
  if (a == b)
    return 1;
  if (b == 1)
    return a % MOD;
  if (b == a - 1)
    return a % MOD;
//  printf("no easy case\n");

  if (n_tab[a][b] != -1) {
    return n_tab[a][b];
  }

  n_tab[a][b] = (newton(a - 1, b - 1) + newton(a - 1, b)) % 10007;
//  printf("returning %d\n", n_tab[a][b]);
  return n_tab[a][b];
}

pair<int, int> rooks[20];

int countMoves(int dx, int dy) {
  if ((dx + dy) % 3 != 0)
    return 0;

  if (dx <= 0 || dy <= 0)
    return 0;

  int total_moves = (dx + dy) / 3;
//  printf("%d %d - total moves: %d\n", dx, dy, total_moves);

  if(dx < total_moves || dy < total_moves)
    return 0;

  int moves_right = dx - total_moves;
//  printf("moves right: %d\n", moves_right);

  return newton(total_moves, moves_right);
}

int countbits(int a) {
  int res = 0;

  while (a != 0) {
    if (a % 2 == 1)
      ++res;
    a /= 2;
  }

  return res;
}

int main() {
  for (int i = 0; i < 105; ++i)
    for (int j = 0; j < 105; ++j)
      n_tab[i][j] = -1;

  int zz;
  scanf("%d", &zz);

  for (int z = 1; z <= zz; ++z) {
    int X, Y, N;

    scanf("%d%d%d", &Y, &X, &N);
//    printf("%d rooks\n", N);

    for (int i = 0; i < N; ++i) {
      scanf("%d%d", &rooks[i].second, &rooks[i].first);
    }

    sort(&rooks[0], &rooks[N]);

    if ((X - 1 + Y - 1) % 3 != 0) {
      printf("Case #%d: 0\n", z);
      continue;
    }

    int total;
    if (X > 1 || Y > 1)
     total = countMoves(X - 1, Y - 1);
    else
      total = 1;

//    printf("Base: %d\n", total);

    for (int mask = 1; mask < (1 << N); ++mask) {
//      printf("mask 0x%x\n", mask);
      int bits = countbits(mask);
      int lastx = 1, lasty = 1;

      int ways = 1;

      for (int i = 0; i < N; ++i) {
        if (mask & (1 << i)) {
          ways *= countMoves(rooks[i].first - lastx, rooks[i].second - lasty);
          ways %= MOD;
          lastx = rooks[i].first;
          lasty = rooks[i].second;
        }
      }

      ways *= countMoves(X - lastx, Y - lasty);
      ways %= MOD;

//      printf("baddies: %d\n", ways);

      if (bits % 2 == 1)
        total = (total - ways + MOD) % MOD;
      else
        total = (total + ways) % MOD;
    }

    printf("Case #%d: %d\n", z, total);
  }

  return 0;
}
