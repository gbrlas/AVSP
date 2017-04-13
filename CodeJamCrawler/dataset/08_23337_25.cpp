/*
 * =====================================================================================
 *
 *       Filename:  ga.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2008-7-27 16:43:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dr. Fritz Mehner (mn), mehner@fh-swf.de
 *        Company:  FH Südwestfalen, Iserlohn
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

long long a[1000];

int main()
{
  int cases;
  cin >> cases;
  for(int c = 1; c <= cases; c++)
  {
    int p, k, l;
    cin >> p >> k >> l;
    for(int i = 0; i < l; i++)
      cin >> a[i];
    sort(a, a + l);
    if (p * k < l)
    {
      cout << "Case #" << c << ": Impossible" << endl;
      continue;
    }
    int num = 0;
    long long tot = 0;
    int index = l - 1;
    while (index >= 0)
    {
      num++;
      for(int i = 0; i < k; i++)
      {
	tot += a[index--] * num;
	if (index < 0)
	  break;
      }
    }
    cout << "Case #" << c << ": " << tot << endl;;
  }
  return 0;
}

