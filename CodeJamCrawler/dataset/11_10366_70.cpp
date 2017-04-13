#include<cstdio>
#include<list>
#define SIZE 'Z' + 1
using namespace std;
void solve () {
  list<char> l;
  int i, C, D, N;
  char combine[SIZE][SIZE], f1, f2, to;
  bool oppose[SIZE][SIZE];
  fill(&combine[0][0], &combine[SIZE][0], 0);
  fill(&oppose[0][0], &oppose[SIZE][0], false);
  scanf("%d ", &C);
  for (i = 0; i < C; i++) {
    scanf("%c%c%c ", &f1, &f2, &to);
    combine[f1][f2] = combine[f2][f1] = to;
  }
  scanf("%d ", &D);
  for (i = 0; i < D; i++) {
    scanf("%c%c ", &f1, &f2);
    oppose[f1][f2] = oppose[f2][f1] = true;
  }
  scanf("%d ", &N);
  for (i = 0; i < N; i++) {
    l.push_back(getchar());
    while (l.size() > 1) {
      f1 = *l.rbegin();
      f2 = *(++l.rbegin());
      if (combine[f1][f2]) {
        l.pop_back();
        l.pop_back();
        l.push_back(combine[f1][f2]);
      } else {
        break;
      }
    }
    for (list<char>::iterator it = l.begin(); it != l.end(); it++) {
      if (oppose[*it][l.back()]) {
        l.clear();
        break;
      }
    }
  }
  printf("[");
  if (!l.empty())
    putchar(l.front());
  for (list<char>::iterator it = ++l.begin(); it != l.end(); it++) {
    printf(", %c", *it);
  }
  printf("]\n");
}
int main() {
  int T, t;
  scanf("%d", &T);
  for (t = 1; t <= T; t++) {
    printf("Case #%d: ", t);
    solve();
  }
}
