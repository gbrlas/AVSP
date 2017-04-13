#include <cstdio>
using namespace std;

typedef unsigned long long ull;

ull dbl_area(ull x1, ull y1, ull x2, ull y2, ull x3, ull y3) {
  return x1 * (y3 - y2) + x2 * (y1 - y3) + x3 * (y2 - y1);
}

int main() {
  int zz;
  scanf("%d", &zz);

  for (int z = 1; z <= zz; ++z) {
    int N, M, A;
    scanf("%d%d%d", &N, &M, &A);
    int found = 0;

    for (int x2 = 0; x2 <= N; ++x2)
      for (int y2 = 0; y2 <= M; ++y2)
        for (int x3 = 0; x3 <= N; ++x3)
          for (int y3 = 0; y3 <= M; ++y3) {
            if (dbl_area(0, 0, x2, y2, x3, y3) == A) {
              printf("Case #%d: 0 0 %d %d %d %d\n", z, x2, y2, x3, y3);
              found = 1;
              goto end;
            }
          }

end:
    if (!found)
      printf("Case #%d: IMPOSSIBLE\n", z);
  }

  return 0;
}