#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

int main() {
  int zz;
  scanf("%d ", &zz);

  for (int z = 1; z <= zz; ++z) {
    int S, Q;
    char temp[256];
    map<string, int> M;
    scanf("%d", &S);
    gets(temp);

    int avail = S;
    set<int> impossible;

    for (int i = 0; i < S; ++i) {
      gets(temp);
      M[temp] = i;
    }

    scanf("%d", &Q);
    gets(temp);
    int res = 0;

    for (int i = 0; i < Q; ++i) {
      gets(temp);

      if (M.find(temp) != M.end()) {
        int srceng = M[temp];

        if (impossible.find(srceng) == impossible.end()) {
          --avail;
          if (avail == 0) {
            avail = S - 1;
            impossible.clear();
            ++res;
          }
          impossible.insert(srceng);
        }
      }
    }

    printf("Case #%d: %d\n", z, res);
  }

  return 0;
}
