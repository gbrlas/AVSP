#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <iterator>
#include <algorithm>
#include <queue>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <string>
using namespace std;

#define MAX 1000008

struct Node
{
   int x, y;
   Node(){}
   Node(int _x, int _y):
      x(_x), y(_y){}
}nn[2][MAX];
int cnt[2];
int flag[108][108];
int ans;

void solve()
{
   ans++;
   int tans = 0, i, j;
   for (i = 100; i >= 1; --i)
      for (j = 100; j >= 1; --j)
         if (flag[i][j] == 0)
         {
            if (flag[i - 1][j] && flag[i][j - 1])
            {
               flag[i][j] = 1;
               tans = 1;
         //      printf("%d %d\n", i, j);
            }
         }
         else if (flag[i][j] == 1)
         {
            if (flag[i - 1][j] == 0 && flag[i][j - 1] == 0)
               flag[i][j] = 0;
            else
               tans = 1;
         }
  // system("pause");
   if (tans == 1)
      solve();
}

int main()
{
   freopen("C-small-attempt1.in", "r", stdin);
   freopen("C-small-attempt1.out", "w", stdout);
   int t, x1, x2, y1, y2, n, iCas = 1, f, i, j, k;
   scanf("%d", &t);
   while (t--)
   {
      memset(flag, 0, sizeof(flag));
      scanf("%d", &n);
      f = 0;
      for (i = 0; i < n; ++i)
      {
         scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
         for (j = x1; j <= x2; ++j)
            for (k = y1; k <= y2; ++k)
            {
             //  nn[0][cnt[0]++] = Node(j, k);
               flag[j][k] = 1;
               f = 1;
            }
      }
      ans = 0;
      if (f)
         solve();
      printf("Case #%d: %d\n", iCas++, ans); 
   }
  // system("pause");
   return 0;
}

