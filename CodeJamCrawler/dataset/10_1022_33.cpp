#include <iostream>

using namespace std;

int main()
{
  int t;
  cin>>t;
  for (int i = 1; i <= t; ++i) {
    long long n, k;
    cin>>n>>k;
    cout<<"Case #"<<i<<": ";
    long long p = 1 << n;
    if ((k % p) == (p - 1)) {
      cout<<"ON"<<endl;
    } else {
      cout<<"OFF"<<endl;
    }
  }
  return 0;
}
