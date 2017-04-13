#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

#define ll long long 

int a_best[1024], a_worst[1024];
int n, p, T;

int main()
{
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  
  cin >> T;
  
  for (int t = 0; t < T; t++)
  {
    cin >> n >> p;
    
    cout << "Case #" << t + 1 << ": ";
    
    for (int i = 0; i < (1 << n); i++)
    {
      int x = i + 1;
      int k = (1 << (n - 1));
      int u = 1;
      
      while (x >= 2)
      {
        x /= 2;
        u += k;
        k /= 2;
      }
      
      a_worst[i] = u;
    }
    
    for (int i = 0; i < (1 << n); i++)
    {
      int x = (1 << n) - i;
      int k = (1 << n);
      
      while (x >= 2)
      {
        x /= 2;
        k /= 2;
      }
      
      a_best[i] = k;
    }

    int x, y;
    
    for (int i = 0; i < (1 << n); i++)
    {
      if (a_best[i] <= p)
        y = i;
      if (a_worst[i] <= p)
        x = i;
    }
    
    cout << x << ' ' << y << endl;
  }
}
