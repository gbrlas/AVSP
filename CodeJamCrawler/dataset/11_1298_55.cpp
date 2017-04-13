#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin>>t;
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin>>n;
    vector< int > v(n);
    for (int i = 0; i < n; ++i) {
      cin>>v[i];
    }
    int ans = -1;
    for (int i = 1; (i + 1) < (1 << n); ++i) {
      int sum1 = 0, sum2 = 0, csum = 0;
      for (int j = 0; j < n; ++j) {
        if (i & (1 << j)) {
          sum1 ^= v[j];
          csum += v[j];
        } else {
          sum2 ^= v[j];
        }
      }
      if ((sum1 == sum2) && (csum > ans)) {
        ans = csum;
      }
    }
    cout<<"Case #"<<tt<<": ";
    if (ans < 0) {
      cout<<"NO"<<endl;
    } else {
      cout<<ans<<endl;
    }
  }
  return 0;
}
