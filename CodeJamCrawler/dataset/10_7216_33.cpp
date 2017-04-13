#include <cstdio>
using namespace std;
int main ()
{
  int T, N, K, i;
  freopen("A-small.out", "w", stdout);
  scanf("%d", &T);
  for (i = 1; i <= T; i++)
  {
    scanf("%d %d", &N, &K);
    if ((K + 1) % (1 << N))
      printf("Case #%d: OFF\n", i);
    else
      printf("Case #%d: ON\n", i);
  }
  return 0;
}
