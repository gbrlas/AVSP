#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  int t;
  cin>>t;
  for (int tt = 0; tt < t; ++tt)
  {
    string s;
    cin>>s;
    map< char, long long > sm;
    for (int i = 0; i < s.size(); ++i)
    {
      sm[s[i]] = -1;
    }
    sm[s[0]] = 1;
    long long ans = 1, base = max(int(sm.size()), 2);
    long long mn = 0;
    for (int i = 1; i < s.size(); ++i)
    {
      if (sm[s[i]] == -1)
      {
        sm[s[i]] = mn;
        ++mn;
        if (mn == 1)
        {
          ++mn;
        }
      }
      ans *= base;
      ans += sm[s[i]];
      //cout<<ans<<endl;
    }
    cout<<"Case #"<<(tt + 1)<<": "<<ans<<endl;
  }
  return 0;
}
