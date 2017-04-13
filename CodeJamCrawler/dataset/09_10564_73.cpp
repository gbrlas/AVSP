#include <iostream>
#include <vector>
#include <map>
using namespace std;


map<int, map<int, long> > m;

long process(int p, int q, const vector<int>& v)
{
  if (p > q) 
    return 0;

  long minbribe = 1000000000;
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] >p && v[i] <q) {
      long t = process(p, v[i] , v) + process(v[i], q ,v);
      if(t < minbribe) 
	minbribe = t;
    }
  }

  if (minbribe == 1000000000) {
    return 0;
  }
  return minbribe + (q -p -2);
}

int main()
{
  int n = 0;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int p, q;
    vector<int> v;
    cin >> p >> q;
    for (int j = 0; j < q; ++j) {
      int t;
      cin >> t;
      v.push_back(t);
      
    }
    cout << "Case #" << i + 1 << ": " << process(0, p+1, v) << endl;
  }


  return 0;
}
