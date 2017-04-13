#include <stdio.h>
#include <string.h>
#define MAX 108
#define N 608
#define INF 0x1f1f1f1f
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) > (b) ? (b) : (a))
#define abs(x) ((x) > 0 ? (x) : -(x))

int num[MAX];
int dp[MAX][N];

int main()
{
  freopen("B-small-attempt5.in", "r", stdin);
  freopen("B-small-attempt5.out", "w", stdout);
   int i, t, iCas = 1, D, I, M, n, mm, ans, j, k, mmMin, gap, r;
   int tmp, cost;
   scanf("%d", &t);
   while (t--)
   {
      scanf("%d%d%d%d", &D, &I, &M, &n);
      mm = 0; mmMin = INF;
      for (i = 1; i <= n; ++i)
      {
         scanf("%d", &num[i]);
         mm = max(mm, num[i]);
         mmMin = min(mmMin, num[i]);
      }
   
      memset(dp, 0x1f, sizeof(dp));
      for (i = mmMin; i <= mm; ++i)
         dp[0][i] = 0;
      for (i = mmMin; i <= mm; ++i)
         dp[1][i] = abs(num[1] - i);
      for (i = 2; i <= n; ++i)
      {
         for (r = 0; r < i; ++r)
         for (j = mmMin; j <= mm; ++j)
         {
            cost = abs(j - num[i]);
            for (k = mmMin; k <= mm; ++k)     //i - 1 ---> i
            {
               if (abs(j - k) <= M)
                  tmp = 0;
               else {
                  if (M != 0)
                  {
                     gap = abs(j - k);
                     tmp = gap / M;
                     if (tmp * M == gap)
                        tmp--;
                     tmp *= I;
                  }
                  else
                     tmp = INF;
               }
               dp[i][j] = min(dp[i][j], dp[r][k] + tmp + cost + D * (i - r - 1));
            }
         }
      }
      ans = INF;
      for (i = mmMin; i <= mm; ++i)
      {
         ans = min(ans, dp[n][i]);
         ans = min(ans, dp[n - 1][i] + D);
      }
      printf("Case #%d: %d\n", iCas++, ans);
   }
}
