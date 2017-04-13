#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

#define ll long long 

ll n, p, T;
ll ans_1, ans_2;


int main()
{
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  
  cin >> T;
  
  for (int t = 0; t < T; t++)
  {
    cin >> n >> p;
    
    cout << "Case #" << t + 1 << ": ";
    
    ll l = 0;
    ll r = (1LL << n);
    
    while (l + 1 < r)
    {
      ll m = (l + r) / 2;
      
      ll x = m + 1;
      ll k = (1LL << (n - 1));
      ll u = 1;
      
      while (x >= 2)
      {
        x >>= 1;
        u += k;
        k >>= 1;
      }
      
      if (u <= p)
        l = m;
      else
        r = m;
    }
    
    ans_1 = l;
    
    l = 0;
    r = (1LL << n);
    
    while (l + 1 < r)
    {
      ll m = (l + r) / 2;
      
      ll x = (1LL << n) - m;
      ll k = (1LL << n);
      
      while (x >= 2)
      {
        x >>= 1;
        k >>= 1;
      }
      
      if (k <= p)
        l = m;
      else
        r = m;
    }
    
    ans_2 = l;

    cout << ans_1 << ' ' << ans_2 << endl;
  }
}
