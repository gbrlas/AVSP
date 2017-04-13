#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <queue>
#include <cstdlib>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<LD, LD> pdd;

#define dbg(x) {cerr << #x << " = " << (x) << endl;}
#define dbgv(x) {cerr << #x << " = {"; for (auto xit = (x).begin(); xit != (x).end(); ++ xit) cerr << *xit << ", "; cerr << "}" << endl;}

template<class T>
T gcd(T a, T b) {return a? gcd(b % a, a): b;}

template<class T>
T egcd(T a, T b, T& x, T& y)
{
  if (a == 0)
    {
      x = 0;
      y = 1;
      return b;
    }
  else
    {
      T g = egcd(b % a, a, y, x);
      x -= b / a * y;
      return g;
    }
}

template<class T>
T xabs(T a) {return a < 0? -a: a;}

template<class T>
T lpow(T a, int p)
{
  if (p <= 0)
    return T(1);
  else if (p & 1)
    return lpow(a * a, p >> 1) * a;
  else
    return lpow(a * a, p >> 1);
}

template<class T>
T lmpow(T a, int p, T mod)
{
  if (p <= 0)
    return T(1) % mod;
  else if (p & 1)
    return lmpow(a * a % mod, p >> 1, mod) * a % mod;
  else
    return lmpow(a * a % mod, p >> 1, mod);
}

int solve(int test)
{
  string res;
  int x, y;
  cin >> x >> y;
  bool xf = x < 0;
  bool yf = y < 0;
  x = xabs(x);
  y = xabs(y);
  // small
  if (xf)
    for (int i = 0; i < x; ++ i)
      res += "EW";
  else
    for (int i = 0; i < x; ++ i)
      res += "WE";
  if (yf)
    for (int i = 0; i < y; ++ i)
      res += "NS";
  else
    for (int i = 0; i < y; ++ i)
      res += "SN";
  
  cout << "Case #" << test << ": " << res << endl;
  return 0;
}

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; ++ i)
    solve(i + 1);
  return (EXIT_SUCCESS);
}








