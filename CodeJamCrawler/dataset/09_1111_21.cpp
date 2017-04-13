#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double solve(vector< double > a, vector< double > b)
{
  return (sqrt(pow(a[0] - b[0], 2.0) + pow(a[1] - b[1], 2.0)) + a[2] + b[2]) / 2.0;
}

int main()
{
  int c;
  cin>>c;
  for (int cc = 0; cc < c; ++cc)
  {
    int n;
    cin>>n;
    vector< vector< double > > v(n, vector< double >(3));
    for (int i = 0; i < n; ++i)
    {
      cin>>v[i][0]>>v[i][1]>>v[i][2];
    }
    double minr = 10000.0;
    if (n == 1)
    {
      cout<<"Case #"<<(cc + 1)<<": "<<v[0][2]<<endl;
    }
    if (n == 2)
    {
      cout<<"Case #"<<(cc + 1)<<": "<<max(v[0][2], v[1][2])<<endl;
    }
    if (n == 3)
    {
      cout<<"Case #"<<(cc + 1)<<": "<<min(min(max(solve(v[0], v[1]), v[2][2]), max(solve(v[0], v[2]), v[1][2])), max(solve(v[2], v[1]), v[0][2]))<<endl;
    }
  }
  return 0;
}
