#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
  int t, n, m;
  cin>>t;
  for (int tt = 1; tt <= t; ++tt)
  {
    cin>>n>>m;
    set< string > tree;
    for (int i = 0; i < n; ++i)
    {
      string s;
      cin>>s;
      while (!s.empty())
      {
        tree.insert(s);
        while (s[s.size() - 1] != '/')
          s.erase(s.size() - 1);
        s.erase(s.size() - 1);
      }
    }
    int ct = tree.size();
    for (int i = 0; i < m; ++i)
    {
      string s;
      cin>>s;
      while (!s.empty())
      {
        tree.insert(s);
        while (s[s.size() - 1] != '/')
          s.erase(s.size() - 1);
        s.erase(s.size() - 1);
      }
    }
    cout<<"Case #"<<tt<<": "<<(tree.size() - ct)<<endl;
  }
}
