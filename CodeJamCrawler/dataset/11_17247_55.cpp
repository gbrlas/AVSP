#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    int total = 0;
    for (int i = 1; i <= n; ++i) {
      int p;
      cin >> p;
      if (p != i) ++total;
    }
    cout << "Case #" << i+1 << ": " << total << endl;
  }
}
