#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

long long mcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a > b) return mcd(a%b, b);
  return mcd(a, b%a);
}

int main() {
  int c;
  cin >> c;
  for (int i = 0; i < c; ++i) {
    int n;
    cin >> n;
    vector<long long> v(n);
    for (int j = 0; j < n; ++j) cin >> v[j]; 
    long long m = v[0] - v[1];
    if (m < 0) m = -m;
    for (int j = 0; j < n; ++j) {
      for (int k = j+1; k< n; ++k) {
         if(v[j] > v[k]) m = mcd(m, v[j]-v[k]);
         else m = mcd(m, v[k]-v[j]);
      } 
    }
    long long q = m;
    while (m < v[0]) m += q;
    cout << "Case #" << i+1 << ": " << m - v[0] << endl;
  }
}
