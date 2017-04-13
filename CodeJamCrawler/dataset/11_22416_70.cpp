#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

pair<int, int> actions[500];

vector<pair<int, int> > blue;
vector<pair<int, int> > orange;

int main() {
  int test = 0, tc;
  int n;
  string s;
  int b;
  for (cin >> tc; test < tc; ++test) {
    blue.clear();
    orange.clear();
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> s >> b;
      if (s == "B") {
        actions[i] = make_pair(0, b);
      } else {
        actions[i] = make_pair(1, b);
      }
    }
    int t[2] = {0, 0};
    int p[2] = {1, 1};
    for (int i = 0; i < n; ++i) {
      int dt = abs(actions[i].second - p[actions[i].first]) + 1;
      t[actions[i].first] = max(t[1 - actions[i].first] + 1, t[actions[i].first] + dt);
      p[actions[i].first] = actions[i].second;
    }
    cout << "Case #" << test + 1 << ": " << max(t[0], t[1]) << endl;
  }
  return 0;
}
