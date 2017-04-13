#include <stdio.h>
#include <string.h>
#define MAX 100080
typedef long long LL;

LL num[MAX], k, ans[MAX], sum, cycle;
int clen;
int flag[MAX];

int main()
{
   freopen("C-large.in", "r", stdin);
   freopen("C-large.out", "w", stdout);
   int i, t, r, n, ir, iCas = 1, pi;
   LL tot;
   scanf("%d", &t);
   while (t--)
   {
      scanf("%d%lld%d", &r, &k, &n);
      for (i = 0; i < n; ++i)
         scanf("%lld", &num[i]);
      i = 0;
      memset(flag, 0, sizeof(flag));
      sum = 0;
      for (ir = 1; ir <= r; ++ir)
      {
         tot = 0;
         pi = i;
         while (tot < k)
         {
            if (tot + num[i] > k)
               break;
            tot += num[i];
            i = (i + 1) % n;
            if (pi == i)
               break;
         }
         sum += tot;
         i = (i - 1 + n) % n;
         if (flag[i] == 0)
            flag[i] = ir;
         else
            break;
         ans[ir] = sum;
         i = (i + 1) % n;
      }
      if (ir < r)
      {
         cycle = sum - ans[flag[i]];
         clen = ir - flag[i];
         sum += (r - ir) / clen * cycle;
         sum += ans[flag[i] + (r - ir) % clen] - ans[flag[i]];
      }
      printf("Case #%d: %lld\n", iCas++, sum);
   }
}
