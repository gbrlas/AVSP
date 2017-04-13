#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int mem[1 << 20];

int rek(int l, int p, int c) {
  int val = (1 << 30);
  if (l * c >= p) return 0;
  int hash = l * 1024 + p;
  if (mem[hash] == -1) {
    for (int i = l + 1; i * c < p + c; ++ i) {
      if (i >= p) break;
      int x = 1 + max(rek(l, i, c), rek(i, p, c));
      if (x < val) {
        val = x;
        //pos = i;
      }
    }
    mem[hash] = val;
  }
  return mem[hash];
}

int main() {
  int tc;
  scanf("%d", &tc);
  for (int t = 1; t <= tc; ++ t) {
    memset(mem, -1, sizeof(mem));
    int l, p, c;
    scanf("%d %d %d", &l, &p, &c);
    printf("Case #%d: %d\n", t, rek(l, p, c));
  }
  return 0;
}
