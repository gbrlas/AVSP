#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
  int zz;
  scanf("%d", &zz);

  for (int z = 1; z <= zz; ++z) {
    int k;
    scanf("%d", &k);

    int perm[5] = { 0, 1, 2, 3, 4 };

    char str[1010];
    scanf("%s", str);
    int len = strlen(str);

    int best = (int) 2e9;

    do {
      char temp[1010];

      char lastc = 0;
      int res = 0;

      for (int i = 0; i < len; ++i) {
        int mod = i % k;
        int base = i - mod;

        temp[i] = str[base + perm[mod]];

        if (temp[i] != lastc) {
          ++res;
          lastc = temp[i];
        }
      }

      best = min(best, res);
    } while (next_permutation(perm, perm + k));

    printf("Case #%d: %d\n", z, best);
  }

  return 0;
}