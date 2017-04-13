#include <cstdio>
#include <algorithm>
#include <cmath>
#define MAXN 3
using namespace std;
int apskr[MAXN][3];
double dist (int a, int b)
  {
  return sqrt((apskr[a][0] - apskr[b][0]) * (apskr[a][0] - apskr[b][0]) + (apskr[a][1] - apskr[b][1]) * (apskr[a][1] - apskr[b][1]));
  }
double r (int a, int b)
  {
  return (dist(a, b) + apskr[a][2] + apskr[b][2]) / 2;
  }
int main ()
  {
  int i, j, C, N;
  scanf("%d", &C);
  for (i = 0; i < C; i++)
    {
    scanf("%d", &N);
    for (j = 0; j < N; j++)
      scanf("%d %d %d", &apskr[j][0], &apskr[j][1], &apskr[j][2]);
    if (N == 1)
      printf("Case #%d: %d\n", i + 1, apskr[0][2]);
      else if (N == 2)
      printf("Case #%d: %d\n", i + 1, max(apskr[0][2], apskr[1][2]));
      else
      printf("Case #%d: %.7lf\n", i + 1, min(min(max((double)apskr[0][2], r(1, 2)), max((double)apskr[1][2], r(0, 2))), max((double)apskr[2][2], r(0, 1))));
    }
  return 0;
  }
