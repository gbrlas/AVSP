#include <cstdio>
#include <cmath>
using namespace std;
int solve ()
{
  int ats = 0, L, P, C, n;
  scanf("%d %d %d", &L, &P, &C);
  while (L * C < P)
  {
    n = round(sqrt(L) * sqrt(P));
    if (n / L > P / n)
      P = n;
    else
      L = n;
    ats++;
  }
  return ats;
}
int main()
{
  int T, t;
  scanf("%d", &T);
  for (t = 1; t <= T; t++)
  {
    printf("Case #%d: %d\n", t, solve());
  }
}
