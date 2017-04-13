#include <vector>
#include <set>
#include <iostream>
#include <string>

using namespace std;

int main()
{
  int l, d, n;
  cin>>l>>d>>n;
  vector< string > v(d);
  for (int i = 0; i < d; ++i)
  {
    cin>>v[i];
  }
  for (int i = 0; i < n; ++i)
  {
    vector< set< char > > m(n, set< char >());
    string s;
    cin>>s;
    int ct = 0;
    for (int j = 0; j < l; ++j)
    {
      if (s[ct] == '(')
      {
        ++ct;
        while (s[ct] != ')')
        {
          m[j].insert(s[ct]);
          ++ct;
        }
        ++ct;
      }
      else
      {
        m[j].insert(s[ct]);
        ++ct;
      }
    }
    ct = 0;
    for (int j = 0; j < d; ++j)
    {
      int lct = 0;
      for (int k = 0; k < l; ++k)
      {
        if (m[k].find(v[j][k]) != m[k].end())
        {
          ++lct;
        }
      }
      if (lct == l)
      {
        ++ct;
      }
    }
    cout<<"Case #"<<(i + 1)<<": "<<ct<<endl;
  }

  return 0;
}
