#include <cstdio>
#include <algorithm>
using namespace std;

int lson(int a) {
  return 2 * a;
}

int rson(int a) {
  return 2 * a + 1;
}

int M;

int is_leaf(int a) {
  return rson(a) <= M;
}

int nodes[11000];
int chang[11000];
int val[11000];
int minch[11000];

const int INF = (int) 1e9;

int main() {
  int zz;
  scanf("%d", &zz);

  for (int z = 1; z <= zz; ++z) {
    int goal;
    scanf("%d%d", &M, &goal);

    for (int i = 1; i <= (M - 1) / 2; ++i) {
      scanf("%d%d", &nodes[i], &chang[i]);

      if (!goal)
        nodes[i] = 1 - nodes[i];
    }

    for (int i = (M + 1) / 2; i <= M; ++i) {
      scanf("%d", &val[i]);
      if (!goal)
        val[i] = 1 - val[i];

      if (val[i])
        minch[i] = 0;
      else
        minch[i] = INF;
    }

    for (int i = (M - 1) / 2; i >= 1; --i) {
      if (nodes[i] == 0) {
        /* OR node */
        minch[i] = min(minch[lson(i)], minch[rson(i)]);
      } else {
        /* AND node */
        int cand1 = minch[lson(i)] + minch[rson(i)];
        if (cand1 >= INF)
          cand1 = INF;

        if (chang[i]) {
          int cand2 = 1 + min(minch[lson(i)], minch[rson(i)]);

          minch[i] = min(cand1, cand2);
        } else {
          minch[i] = cand1;
        }
      }
    }

    printf("Case #%d: ", z);
    if (minch[1] == INF) {
      printf("IMPOSSIBLE\n");
    } else {
      printf("%d\n", minch[1]);
    }
  }

  return 0;
}
