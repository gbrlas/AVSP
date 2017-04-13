#include <iostream>
#include <cstdio>
using namespace std;

int x[800];
int y[800];

int main()
{
  int cases;
  scanf("%d", &cases);
  for(int c = 1; c <= cases; c++)
  {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
      scanf("%d", &x[i]);
    for(int i = 0; i < n; i++)
      scanf("%d", &y[i]);
    sort(x, x + n);
    sort(y, y + n);
    int tot = 0;
    for(int i = 0; i < n; i++)
      tot += x[i] * y[n - 1 - i];
    printf("Case #%d: %d\n", c, tot);
  }
  return 0;
}
