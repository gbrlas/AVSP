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
#define MAX 2050

int num[MAX];
int price[MAX][MAX];
int n, ans, p;

void dfs(int s, int d)
{
   int f, i, j;
 //  printf("%d %d\n", s, d);
 //  for (i = s; i <= d; ++i)
 //     printf("%d ", num[i]);
  // printf("\n");
   f = 0;
   for (i = s; i <= d; ++i)
      if (num[i] < p)
      {
         f = 1;
         break;
      }
   if (f)
   {
      for (i = s; i <= d; ++i)
         num[i]++;
      ans++;
      dfs(s, (s + d) / 2);
      dfs((s + d) / 2 + 1, d);
   }
}


int main()
{
   freopen("B-small-attempt0.in", "r", stdin);
   freopen("B-small-attempt0.out", "w", stdout);

   int i, t, iCas = 1, j;
   scanf("%d", &t);
   while (t--)
   {
      scanf("%d", &p);
      n = (1 << p);
      for (i = 0; i < n; ++i)
         scanf("%d", &num[i]);
      for (i = 1; i <= p; ++i)
         for (j = 0; j < (1 << (p - i)); ++j)
            scanf("%d", &price[i][j]);
      ans = 0;
      dfs(0, n - 1); 
      
      
      printf("Case #%d: %d\n", iCas++, ans); 
      
   }
  // system("pause");
   return 0;
}

