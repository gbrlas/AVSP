#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    int n;
    cin >> n;
    vector< vector<int> > v(2, vector<int> (n));
    int intersections = 0;
    for (int j = 0; j < n; ++j) {
      int a, b;
      cin >> a >> b;
      for (int k = 0; k < j; ++k) {
        if ((a < v[0][k] and b > v[1][k]) or (a > v[0][k] and b < v[1][k])) ++intersections;
      }
      v[0][j] = a;
      v[1][j] = b;
    }
    cout << "Case #" << i << ": " << intersections << endl;
  }
}
