#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    int total = 0;
    int min = 10000000;
    int troll = 0;
    for (int j = 1; j <= n; ++j) {
      int p;
      cin >> p;
      total += p;
      if (p < min) min = p;
      troll ^= p;
    }
    if (troll == 0) cout << "Case #" << i+1 << ": " << total-min << endl;
    else cout << "Case #" << i+1 << ": NO" << endl;
  }
}
