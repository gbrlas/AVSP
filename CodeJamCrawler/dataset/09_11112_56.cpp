#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
  int z;
  scanf("%d", &z);

  for (int zz = 1; zz <= z; ++zz) {
    char temp[100];
    scanf("%s", temp);
    int len = strlen(temp);

    printf("Case #%d: ", zz);

    if (next_permutation(temp, temp+len)) {
      printf("%s\n", temp);
    } else {
      sort(temp, temp + len);

      int t = 0;
      while (temp[t] == '0')
        ++t;

      swap(temp[0], temp[t]);

      putchar(temp[0]);
      putchar('0');
      printf("%s\n", temp + 1);
    }
  }

  return 0;
}