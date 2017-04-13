#include <iostream>
using namespace std;

int main () {

  int T, N, K;
  scanf("%d", &T);
  for (int c = 1; c <= T; ++c) {
    scanf("%d %d", &N, &K);
    bool on = true;
    for (int i = 0; i < N; ++i)
      if (!(K&(1<<i)))
        on = false;
    printf("Case #%d: %s\n", c, on ? "ON" : "OFF");
  }
  return 0;
}
