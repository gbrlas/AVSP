#include <cstdio>
#define MAXN 50
using namespace std;
int main()
{
  int C, B, i, T, X[MAXN], V[MAXN], ats, t, prieaugis, N, K;
  scanf("%d", &C);
  for (t = 1; t <= C; t++)
  {
    ats = 0;
    prieaugis = 0;
    scanf("%d %d %d %d", &N, &K, &B, &T);
    for (i = 0; i < N; i++)
      scanf("%d", X + i);
    for (i = 0; i < N; i++)
      scanf("%d", V + i);
    for (i = N - 1; K > 0 && i >= 0; i--)
    {
      if ((B - X[i] + V[i] - 1) / V[i] <= T)
      {
        K--;
        ats += prieaugis;
      }
      else
        prieaugis++;
    }
    if (K == 0)
      printf("Case #%d: %d\n", t, ats);
    else
      printf("Case #%d: IMPOSSIBLE\n", t);
  }
}
