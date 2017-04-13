#include <cstdio>
using namespace std;
int solve ()
{
  int ats = 0, N, i, j, laidai[1000][2];
  scanf("%d", &N);
  for (i = 0; i < N; i++)
    scanf("%d %d", &laidai[i][0], &laidai[i][1]);
  for (i = 0; i < N; i++)
    for (j = i + 1; j < N; j++)
      if (
        (laidai[i][0] > laidai[j][0] && laidai[i][1] < laidai[j][1])
        ||
        (laidai[i][0] < laidai[j][0] && laidai[i][1] > laidai[j][1])
        )
        ats++;
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
