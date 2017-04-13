#include <cstdio>
using namespace std;

char words[5000][16];

char allowed[15][26];

int main() {
  int L, D, N;

  scanf("%d%d%d", &L, &D, &N);

  for (int i = 0; i < D; ++i) {
    scanf("%s", words[i]);
  }

  char temp[10000];

  for (int i = 0; i < N; ++i) {
    scanf("%s", temp);
    int res = 0;

    for (int a = 0; a < 15; ++a)
      for (int b = 0; b < 26; ++b)
        allowed[a][b] = 0;

    int off = 0;

    for (int j = 0; j < L; ++j) {
      if (temp[off] == '(') {
        ++off;

        while (temp[off] != ')') {
          allowed[j][temp[off++] - 'a'] = 1;
        }

        ++off;
      } else {
        allowed[j][temp[off++] - 'a'] = 1;
      }
    }

    for (int j = 0; j < D; ++j) {
      int OK = 1;

      for (int k = 0; k < L; ++k)
        if (!allowed[k][words[j][k] - 'a'])
          OK = 0;

      res += OK;
    }

    printf("Case #%d: %d\n", i + 1, res);
  }

  return 0;
}
