/*
 * =====================================================================================
 *
 *       Filename:  gb.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2008-7-27 17:26:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */

#include <iostream>
#include <cmath>
#include <list>
using namespace std;

long long ans;
string s;
int a[1000];
long long array[100][100];

long long solve(const string &s)
{
  long long tot = 0;
  for(int i = 0; i < s.size(); i++)
    tot = tot * 10 + (s[i] - '0');
  return tot;
}

void dfs(int dep, int maxDep)
{
  if (dep == maxDep)
  {
    long long tot = 0;
    int start = 0;
    int op = 1;
    for(int i = 0; i < s.size() - 1; i++)
      if (a[i])
      {
	if (op == 1)
	  tot += array[start][i - start + 1];
	else
	  tot -= array[start][i - start + 1];
	op = a[i];
	start = i + 1;
      }
    if (op == 1)
      tot += array[start][s.size()];
    else
      tot -= array[start][s.size()];
    long long absT = abs(tot);
    if ((absT % 2 == 0) || (absT % 3 == 0) || (absT % 5 == 0) || (absT % 7 == 0))
	ans++;
    return;
  }
  for(int i = 0; i < 3; i++)
  {
    a[dep] = i;
    dfs(dep + 1, maxDep);
  }
}

int main()
{
  int cases;
  cin >> cases;
  for(int c = 1; c <= cases; c++)
  {
    ans = 0;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
      for(int j = 1; j <= s.size(); j++)
	array[i][j] = solve(s.substr(i, j));
    dfs(0, s.size() - 1);
    cout << "Case #" << c << ": " << ans << endl;
  }
  return 0;
}
