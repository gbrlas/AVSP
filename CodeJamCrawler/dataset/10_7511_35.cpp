#include <stdio.h>
#include <string.h>
#define MAX 58

int n, k;
char mp[MAX][MAX];
int dir[8][2] = {-1, -1, -1, 0, -1, 1, 0, 1,
                 1, 1, 1, 0, 1, -1, 0, -1};

void rotate()
{
   int i, j, k, pos;
   char tmp;
   for (i = 0; i < n; ++i)
   {
     
      for (j = n - 2; j >= 0; --j)
      {
         tmp = mp[i][j];
         pos = j;
         for (k = j + 1; k < n; ++k)
            if (mp[i][k] == '.')
               pos = k;
            else
               break;
         mp[i][j] = '.';
         mp[i][pos] = tmp;     
      }
   }
}

int bfs(int x, int y, char color)
{
   int i, tx, ty, sum;
   sum = 1;
   for (i = 0; i < 4; ++i)
   {
      sum = 1;
      tx = x; ty = y;
      while (1)
      {
         tx = tx + dir[i][0];
         ty = ty + dir[i][1];
         if (tx >= 0 && tx < n && ty >= 0 && ty < n)
         {
            if (mp[tx][ty] == color)
               sum++;
            else
               break;
         }
         else
            break;
      }
      if (sum >= k)
         return 1;
   }
   if (sum >= k)
      return 1;
   else
      return 0;
}

int main()
{
   freopen("A-small-attempt0 (1).in", "r", stdin);
   freopen("A-small-attempt0 (1).out", "w", stdout);
   int t, i, cntRed, cntBlue, iCas = 1, j;
   scanf("%d", &t);
   while (t--)
   {
      scanf("%d%d", &n, &k);
      for (i = 0; i < n; ++i)
         scanf("%s", &mp[i]);
   
      rotate();
    //  for (i = 0; i < n; ++i)
     //    printf("%s\n", mp[i]);
     // printf("\n");
      cntRed = cntBlue = 0;
      for (i = 0; i < n; ++i)
      {
         for (j = 0; j < n; ++j)
         {
         //   printf("%d %d\n", i, j);
            if (mp[i][j] == 'R' && cntRed == 0)
               cntRed = bfs(i, j, 'R');
            else if (mp[i][j] == 'B' && cntBlue == 0)
               cntBlue = bfs(i, j, 'B');
            if (cntRed && cntBlue)
               break;
         }
         if (cntRed && cntBlue)
               break;
       }
       if (cntRed && cntBlue)
          printf("Case #%d: Both\n", iCas++);
       else if (cntRed)
          printf("Case #%d: Red\n", iCas++);
       else if (cntBlue)
          printf("Case #%d: Blue\n", iCas++);
       else
          printf("Case #%d: Neither\n", iCas++);
   }
  // while(1);
}
