#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>

#define N 100
#define H 100

using namespace std;

int a[N][N];
int b[N][N];
int rmax[N];

int main()
{
  int tests;

  scanf("%d", &tests);

  for(int t = 0; t < tests; ++t)
  {
    int n;
    int m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; ++i)
    {
      rmax[i] = 0;
      for(int j = 0; j < m; ++j)
      {
        b[i][j] = H;
        scanf("%d", &(a[i][j]));
        rmax[i] = max(rmax[i], a[i][j]);
      }
    }

    int diffRow = -1;

    for(int i = 0; i < n; ++i)
    {
      for(int j = 1; j < m; ++j)
      {
        if(a[i][j] != a[i][0])
        {
          diffRow = i;
        }
      }
    }

    printf("Case #%d: ", t + 1);

    if(diffRow != -1)
    {
      bool correct = true;
      for(int i = 0; i < n; ++i)
      {
        for(int j = 0; j < m; ++j)
        {
          b[i][j] = (a[diffRow][j] == rmax[diffRow]) ? rmax[i] : a[diffRow][j];
          if(a[i][j] != b[i][j])
          {
            correct = false;
          }
        }
      }
      printf("%s\n", correct ? "YES" : "NO");

    }
    else
    {
      printf("YES\n");
    }
  }



  return 0;
}
