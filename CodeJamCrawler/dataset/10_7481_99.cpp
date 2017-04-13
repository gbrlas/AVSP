#include <stdio.h>
#include <string.h>

int main()
{
   freopen("A-large.in", "r", stdin);
   freopen("A-large.out", "w", stdout);
   int i, n, k, t, nn, iCas = 1;
   scanf("%d", &t);
   while (t--)
   {
      scanf("%d%d", &n, &k);
      nn = (1 << n);
      if (k != 0 && k % nn == (nn - 1))
         printf("Case #%d: ON\n", iCas++);
      else
         printf("Case #%d: OFF\n", iCas++); 
   }
}
