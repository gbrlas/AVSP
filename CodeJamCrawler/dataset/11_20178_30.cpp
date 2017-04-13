#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <algorithm>

using namespace std;
bool work(long long n, long long pd, long long pg)
{
      if (pd != 100 && pg == 100)return false;
      if (pd != 0 && pg == 0)return false;
      long long g = __gcd(pd, 100ll);
      long long mn = 100 / g;
      return n >= mn;
}

int main()
{
      int cas, t;
      freopen("A-small-attempt0.in", "r", stdin);
      freopen("aout.txt", "w", stdout);
      scanf("%d", &t);
      for (cas = 1; cas <= t; cas++)
      {
            long long  n, pd, pg;
            scanf("%lld%lld%lld", &n, &pd, &pg);
            if (work(n, pd, pg))
            {
                  printf("Case #%d: Possible\n", cas);
            } else
            {
                  printf("Case #%d: Broken\n", cas);
            }
      }
      return 0;
}
