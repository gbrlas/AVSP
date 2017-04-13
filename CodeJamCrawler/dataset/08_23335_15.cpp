/*
 * =====================================================================================
 *
 *       Filename:  gcb.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2008-7-26 9:40:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstdio>
using namespace std;

struct nodeType
{
  int size;
  int index[2000], color[2000];
};
nodeType favour[2000];
int t[2000];
int ans[2000], best[2000];
int bestSum;
int n, m;

bool comp(const nodeType &node1, const nodeType &node2)
{
  return node1.size <= node2.size;
}

bool check()
{
  for(int i = 0; i < m; i++)
  {
    bool ok = false;
    for(int j = 0; j < favour[i].size; j++)
      if (ans[favour[i].index[j]] == favour[i].color[j])
      {
	ok = true;
	break;
      }
    if (!ok)
      return false;
  }
  return true;
}

void dfs(int dep, int maxDep, int sum)
{
  if (sum >= bestSum)
    return;
  if (dep == maxDep)
  {
    if (check())
    {
      bestSum = sum;
      memcpy(best, ans, sizeof(ans));
    }
    return;
  }
  for(int i = 0; i < 2; i++)
  {
    ans[dep] = i;
    if (i == 1)
      dfs(dep + 1, maxDep, sum + 1);
    else
      dfs(dep + 1, maxDep, sum);
  }
}

int main()
{
  int cases;
  scanf("%d", &cases);
  for(int c = 1; c <= cases; c++)
  {
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
      scanf("%d", &favour[i].size);
      for(int j = 0; j < favour[i].size; j++)
      {
	scanf("%d%d", &favour[i].index[j], &favour[i].color[j]);
	favour[i].index[j]--;
      }
    }
    bestSum = 1 << 30;
    dfs(0, n, 0);
    printf("Case #%d: ", c);
    if (bestSum != 1 << 30)
    {
      for(int i = 0; i < n; i++)
	if (i != n - 1)
	  printf("%d ", best[i]);
	else
	  printf("%d\n", best[i]);
    }
    else
      printf("IMPOSSIBLE\n");
  }
  return 0;
}
