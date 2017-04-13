#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++)
  {
    int x, s, r, m, n;
    scanf("%d %d %d %d %d", &x, &s, &r, &m, &n);
    vector<pair<int, int> > v;
    while(n--)
    {
      int b, e, w;
      scanf("%d %d %d", &b, &e, &w);
      v.push_back(make_pair(s+w, e-b));
      x -= e-b;
    }
    v.push_back(make_pair(s, x));
    r -= s;
    sort(v.begin(), v.end());
    
    double res = 0;
    double rem = m;
    for (vector<pair<int, int> >::const_iterator i = v.begin(); i != v.end(); ++i)
    {
      double torun = min(rem*(r + i->first), (double)i->second);
      rem -= torun / (r + i->first);
      res += torun / (r + i->first) + (i->second - torun) / (i->first);
    }
    printf("Case #%d: %f\n", t, res);
  }
  return 0;
}
