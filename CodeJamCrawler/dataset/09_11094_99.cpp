#include <cstdio>
#include <cstring>
using namespace std;

char phrase[] = "welcome to code jam";

int tab[501][20];

char line[501];

int digit(int number, int which) {
  int temp = 1;

  for (int i = 0; i < which; ++i)
    temp *= 10;

  return (number % (10 * temp)) / temp;
}

int main() {
  int N;
  scanf("%d ", &N);

  for (int nn = 1; nn <= N; ++nn) {
    scanf("%[^\n]\n", line);

    int len = strlen(line);

    tab[0][0] = 1;

    for (int i = 1; i <= 19; ++i)
      tab[0][i] = 0;

    for (int i = 1; i <= len; ++i) {
      for (int j = 0; j <= 19; ++j) {
        tab[i][j] = tab[i - 1][j];

        if (j > 0 && line[i - 1] == phrase[j - 1]) {
          tab[i][j] += tab[i - 1][j - 1];
          tab[i][j] %= 10000;
        }
      }
    }

    printf("Case #%d: ", nn);
    for (int i = 3; i >= 0; --i)
      putchar('0' + digit(tab[len][19], i));

    putchar('\n');
  }

  return 0;
}
