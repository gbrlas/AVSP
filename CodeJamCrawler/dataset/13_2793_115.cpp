#include <stdio.h>

int a[100][100];
int m, n;

int check()
{
  for (int i=0; i<m; i++)
    for(int j=0; j<n; j++)
    {
      int good = 1;
      for (int k=0; good && k<m; k++)
        if (a[k][j] > a[i][j])
          good = 0;
      if (good)
        continue;
      good = 1;
      for (int k=0; good && k<n; k++)
        if (a[i][k] > a[i][j])
          good = 0;
      if (good)
        continue;
      return 0;
    }
  return 1;
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++)
  {
    scanf("%d %d", &m, &n);
    for (int i=0; i<m; i++)
      for (int j=0; j<n; j++)
        scanf("%d", &a[i][j]);
    printf("Case #%d: %s\n", t, check() ? "YES" : "NO");
  }
  return 0;
}
