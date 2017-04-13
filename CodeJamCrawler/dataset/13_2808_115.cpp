#include <stdio.h>

long long rev(long long x)
{
  long long res = 0;
  while(x > 0)
  {
    res = (10 * res) + (x%10);
    x /= 10;
  }
  return res;
}

long long v[39];

int main()
{
  int k = 0;
  for (long long i=1; i<=10000000; i++)
  {
    if (i != rev(i))
      continue;
    long long j = i*i;
    if (j != rev(j))
      continue;
    v[k++] = i*i;
  }
  int T;
  scanf("%d", &T);
  for (int t=1; t<=T; t++)
  {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    int cnt = 0;
    for (int i=0; i<k; i++)
      if (v[i] >= a && v[i] <= b)
        cnt++;
    printf("Case #%d: %d\n", t, cnt);
  }
  return 0;
}
