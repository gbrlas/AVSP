#include<iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i++ < t; ) {
    int c;
    cin >> c;
    int *p = new int[c];
    int *z = new int[c];
    for (int j = 0; j < c; j++) {
      cin >> p[j];
      p[j]--;
      z[j] = 1;
    }
    int ans = 0;
    for (int j = 0; j < c; j++) {
      int ct = 0, f = j;
      while (z[f]) {
        z[f] = 0;
        ct++;
        f = p[f];
      }
      if (ct > 1)
        ans += ct;
    }
    cout << "Case #" << i << ": " << ans << ".000000" << endl;
    delete[] p;
    delete[] z;
  }
  return 0;
}