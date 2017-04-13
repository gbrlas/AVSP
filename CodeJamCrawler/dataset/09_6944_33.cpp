#include <cstdio>
#include <set>
#define MAXL 15
#define MAXD 5000
using namespace std;
int main ()
  {
  int i, j, k, L, D, N, ats;
  set <char> raides[MAXL];
  char zodynas[MAXD][MAXL + 1], c;
  scanf("%d %d %d", &L, &D, &N);
  for (i = 0; i < D; i++)
    scanf("%s", zodynas[i]);
  for (i = 0; i < N; i++)
    {
    for (j = 0; j < L; j++)
      {
      raides[j].clear();
      c = getchar();
      if (c == '(')
        while ((c = getchar()) != ')')
          raides[j].insert(c);
        else if (c >= 'a' && c <= 'z')
        raides[j].insert(c);
        else
        j--;
      }
    ats = 0;
    for (j = 0; j < D; j++)
      {
      for (k = 0; k < L; k++)
        if (raides[k].find(zodynas[j][k]) == raides[k].end())
          break;
      if (k == L)
        ats++;
      }
    printf("Case #%d: %d\n", i + 1, ats);
    }
  return 0;
  }
