#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< long long > sc;
vector< vector< long long > > v;

int solve(int a, int b)
{
  if ((b - a) == 1)
  {
    return 0;
  }
  if (v[a][b] > -1)
  {
    return v[a][b];
  }
  if ((b - a) == 2)
  {
    return v[a][b] = sc[b] - sc[a] - 2;
  }
  long long ans = (sc[b] - sc[a] - 2) + solve(a, a + 1) + solve(a + 1, b);
  for (int i = a + 2; i < b; ++i)
  {
    ans = min(ans, (sc[b] - sc[a] - 2) + solve(a, i) + solve(i, b));
  }
  return v[a][b] = ans;
}

int main()
{
  int n;
  cin>>n;
  for (int nn = 0; nn < n; ++nn)
  {
    int p, q;
    cin>>p>>q;
    sc.clear();
    sc.push_back(0);
    for (int i = 0; i < q; ++i)
    {
      long long tmp;
      cin>>tmp;
      sc.push_back(tmp);
    }
    sc.push_back(p + 1);
    v.resize(sc.size());
    for (int i = 0; i < v.size(); ++i)
    {
      v[i].resize(v.size());
      fill(v[i].begin(), v[i].end(), -1);
    }
    cout<<"Case #"<<(nn + 1)<<": "<<solve(0, v.size() - 1)<<endl;
  }
  return 0;
}
