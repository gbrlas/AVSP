#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 512;
const int R = 0;
const int C = 1;

typedef long long ll;

int r, c, d;
int biggest;
int mark;
char buff[N];
int input[N][N];
int sum[N][N];
char table[N][N][N];

void read() {
  biggest = 0;
  scanf("%d %d %d", &r, &c, &d);
  for (int i = 0; i < r; ++i) {
    scanf("%s", buff);
    for (int j = 0; j < c; ++j) {
      input[i][j] = buff[j] - '0';
    }
  }
}

void computeSum() {
  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= c; ++j) {
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + input[i - 1][j - 1];
    }
  }
}

ll query(int r, int c, int h, int w) {
  return sum[r + h][c + w] - sum[r][c + w] - sum[r + h][c] + sum[r][c];
}

void solveR(int x) {
  if (x > r || x > c) {
    return;
  }
  ll initR = 0;
  for (int i = 0; i < x; ++i) {
    initR += query(i, 0, 1, x) * (x - 2 * i - 1);
  }
  for (int j = 0; j + x <= c; ++j) {
    if (j) {
      for (int i = 0; i < x; ++i) {
        initR -= input[i][j - 1] * (x - 2 * i - 1);
        initR += input[i][j - 1 + x] * (x - 2 * i - 1);
      }
    }
    ll currR = initR;
    for (int i = 0; i + x <= r; ++i) {
      if (i) {
        //printf("R %lld\n", currR);
        currR -= query(i - 1, j, 1, x) * (x - 1);
        //printf("R %lld\n", currR);
        currR += 2 * query(i, j, x - 1, x);
        //printf("R %lld\n", currR);
        currR -= query(i - 1 + x, j, 1, x) * (x - 1);
        //printf("R %lld\n", currR);
      }
      ll t = currR
          - input[i][j] * (x - 1)
          - input[i][j + x - 1] * (x - 1)
          + input[i + x - 1][j] * (x - 1)
          + input[i + x - 1][j + x - 1] * (x - 1);
      //printf("R %d %d %d -> %lld\n", x, i, j, currR);
      if (!t) {
        table[x][i][j] = mark;
      }
    }
  }
}

void solveC(int x) {
  if (x > r || x > c) {
    return;
  }
  ll initC = 0;
  for (int j = 0; j < x; ++j) {
    initC += query(0, j, x, 1) * (x - 2 * j - 1);
  }
  for (int i = 0; i + x <= r; ++i) {
    if (i) {
      for (int j = 0; j < x; ++j) {
        initC -= input[i - 1][j] * (x - 2 * j - 1);
        initC += input[i - 1 + x][j] * (x - 2 * j - 1);
      }
    }
    ll currC = initC;
    for (int j = 0; j + x <= c; ++j) {
      if (j) {
        currC -= query(i, j - 1, x, 1) * (x - 1);
        currC += 2 * query(i, j, x, x - 1);
        currC -= query(i, j - 1 + x, x, 1) * (x - 1);
      }
      ll t = currC
          - input[i][j] * (x - 1)
          - input[i + x - 1][j] * (x - 1)
          + input[i][j + x - 1] * (x - 1)
          + input[i + x - 1][j + x - 1] * (x - 1);
      //printf("C %d %d %d -> %lld\n", x, i, j, currC);
      if (!t) {
        if (table[x][i][j] == mark) {
          biggest = x;
        }
      }
    }
  }
}

void solve() {
  int up = min(r, c);
  for (int i = 3; i <= up; ++ i) {
    solveR(i);
    solveC(i);
  }
}

void answer(int x) {
  printf("Case #%d: ", x);
  if (biggest >= 3) {
    printf("%d\n", biggest);
  } else {
    printf("IMPOSSIBLE\n");
  }
}

int main(int argc, char *argv[]) {
  int tc;
  scanf("%d", &tc);
  for (int i = 1; i <= tc; ++i) {
    mark = i;
    read();
    computeSum();
    solve();
    answer(i);
  }
  return 0;
}
