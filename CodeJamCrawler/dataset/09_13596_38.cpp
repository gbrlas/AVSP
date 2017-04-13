#include <iostream>
using namespace std;

int main () {

  int T, base;
  char buf[64];
  char real[64];
  char used[128];
  scanf("%d\n", &T);
  for (int c = 1; c <= T; ++c) {
    scanf("%s\n", buf);
    for (int i = 0; i < 128; ++i)
      used[i] = -1;
    base = -1;
    int len = strlen(buf);
    for (int i = 0; i < len; ++i) {
      if (used[buf[i]] == -1) {
	if (base == -1) {
	  used[buf[i]] = 1;
	  base = 0;
	}
	else if (base == 0) {
	  used[buf[i]] = 0;
	  base = 1;
	}
	else
	  used[buf[i]] = ++base;
      }
      real[i] = used[buf[i]];
    }
    ++base;
    if (base < 2)
      base = 2;
    long long ans = 0;
    long long add = 1;
    for (int i = len-1; i >= 0; --i) {
      ans += add*real[i];
      add *= base;
    }
    printf("Case #%d: %lld\n", c, ans);
  }
}
