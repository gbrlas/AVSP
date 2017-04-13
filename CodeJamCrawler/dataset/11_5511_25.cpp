#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    char lp;
    vector<int> d;
    int x = 0;
    int sum = 0;
    for (int j = 0; j < n; ++j) {
      int y;
      cin >> y;
      x ^= y;
      sum += y;
      d.push_back(y);
    }
    int minel = *(min_element(d.begin(), d.end()));
    if (x == 0) {
      cout << "Case #" << i+1 << ": " << sum-minel << endl;
    } else {
      cout << "Case #" << i+1 << ": NO" << endl;
    }

  }
  return 0;
}
