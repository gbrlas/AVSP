#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 128;

int n;
double mas[4][N];
double cnt[4][N];
double table[4][N][N];
char buff[N];

void read() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    scanf("%s", buff);
    for (int j = 0; j < n; ++ j) {
      switch (buff[j]) {
        case '0':
          table[0][i][j] = 0;
          break;

        case '1':
          table[0][i][j] = 1;
          break;

        default:
          table[0][i][j] = -1;
      }
    }
  }
}

void computeAverage(int x) {
  for (int i = 0; i < n; ++ i) {
    mas[x][i] = 0;
    cnt[x][i] = 0;
    for (int j = 0; j < n; ++ j) {
      if (table[x][i][j] >= 0) {
        mas[x][i] += table[x][i][j];
        cnt[x][i] += 1;
      }
    }
  }
}

void populateNext(int x) {
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) {
      if (table[x][i][j] >= 0) {
        if (x == 0) {
          table[x + 1][i][j] = (mas[x][j] - table[x][j][i]) / (cnt[x][j] - 1);
        } else {
          table[x + 1][i][j] = mas[x][j] / cnt[x][j];
        }
      } else {
        table[x + 1][i][j] = -1;
      }
    }
  }
}

void debug(int x) {
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) {
      printf("%lf ", table[x][i][j]);
    }
  }
}

void computeAnswer() {
  for (int i = 0; i < n; ++ i) {
    mas[3][i] = 0.25 * mas[0][i] / cnt[0][i] +
                0.5  * mas[1][i] / cnt[1][i] +
                0.25 * mas[2][i] / cnt[2][i];
    printf("%.12lf\n", mas[3][i]);
  }
}

int main(int argc, char *argv[]) {
  int tc;
  scanf("%d", &tc);
  for (int i = 1; i <= tc; ++i) {
    read();
    computeAverage(0);
    populateNext(0);
    computeAverage(1);
    populateNext(1);
    computeAverage(2);
    printf("Case #%d:\n", i);
    computeAnswer();
  }
  return 0;
}
