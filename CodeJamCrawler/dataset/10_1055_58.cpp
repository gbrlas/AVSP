#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
  int t;
  cin>>t;
  for (int tt = 1; tt <= t; ++tt)
  {
    int n;
    cin>>n;
    vector< pair< int, int > > v(n);
    for (int i = 0; i < n; ++i)
      cin>>v[i].first>>v[i].second;
    sort(v.begin(), v.end());
    int ct = 0, lct = 0;
    do
    {
      lct = 0;
      for (int i = 1; i < n; ++i)
      {
        if (v[i].second < v[i - 1].second)
        {
          ++lct;
          swap(v[i], v[i - 1]);
        }
      }
      ct += lct;
    }
    while (lct > 0);
    cout<<"Case #"<<tt<<": "<<ct<<endl;
  }
  return 0;
}
