#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <math.h>
#include <limits.h>
#include <iomanip>
using namespace std;

long int p, q;
int ans;


int solve()
{
  string s, s2;

  scanf("%ld/%ld", &p, &q);
  //  cout << p << endl;
  //  cout << q << endl;
  for(long int i = 2; i <= p; i++)
    {
      if(p % i == 0 && q % i == 0)
	{
	  p /= i;
	  q /= i;
	}
    }
  ans = 0;
  for(int i = 1;i <= 40; i++)
    {
      if(q == 1)
	{
	  break;
	}
      if(q % 2 == 1)
	{
	  cout << "impossible" << endl;
	  return 0;
	}
      q /= 2;
      if(ans == 0 && p >= q)
	{
	  ans = i;
	  p -= q;
	}
      if(p >= q)
	{
	  p -= q;
	}
    }
  if(p != 0 || q != 1)
    {
      cout << "impossible" << endl;
      return 0;
    }
  cout << ans << endl;
  
  return 0;
}



int main()
{
  int m;
  string s;

  cin >> s;
  istringstream istr(s);
  istr >> m;

  for(int i = 0; i < m; i++)
    {

      cout << "Case #" << (i + 1) << ": ";
      solve();
    }
  return 0;
}
