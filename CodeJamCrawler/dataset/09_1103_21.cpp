#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

vector< int > v;
vector< vector < vector< long long > > > mp;

/*long long solve(int a, int b, int start)
{
  if (mp[a][b][start] >= 0)
  {
    return mp[a][b][start];
  }
  for (int i = a; i <= b; ++i)
  {
  }
}*/

int main()
{
  int t;
  cin>>t;
  for (int tt = 0; tt < t; ++tt)
  {
    int n;
    cin>>n;
    v.resize(n);
    mp.resize(n);
    for (int i = 0; i < n; ++i)
    {
      string s;
      cin>>s;
      v[i] = 0;
      mp[i].resize(n);
      for (int j = 0; j < s.size(); ++j)
      {
        mp[i][j].resize(n);
        fill(mp[i][j].begin(), mp[i][j].end(), -1);
        if (s[j] == '1')
        {
          v[i] = j;
        }
      }
    }
    int x = 0;
    for (int i = 0; i < n; ++i)
    {
      if (v[i] > i)
      {
        for (int j = i + 1; j < n; ++j)
        {
          if (v[j] <= i)
          {
            rotate(v.begin() + i, v.begin() + j, v.begin() + j + 1);
            /*for (int k = 0; k < n; ++k)
            {
              cout<<v[k]<<" ";
            }
            cout<<endl;*/
            x += j - i;
            --i;
            break;
          }
        }
      }
    }
    cout<<"Case #"<<(tt + 1)<<": "<<x<<endl;
  }
  return 0;
}
