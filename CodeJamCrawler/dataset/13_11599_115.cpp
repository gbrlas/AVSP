#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

#define ll long long 


bool pal(ll n)
{
  ll m = 0;
  ll z = n;
  
  while (z)
  {
    m = m * 10 + z % 10;
    z /= 10;
  }
  
  if (m == n)
    return 1;
  return 0;
}

int main()
{
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  
  for (int i = 1; i <= 10000000; i++)
  {
    if (!pal(i))
      continue;
      
    if (!pal((ll)(i) * (ll)(i)))
      continue;
      
    printf("%d, ", i);
  }
}
