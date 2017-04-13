#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    int r, c;
    cin >> r >> c;
    vector<vector<char> > v(r+1, vector<char>(c+1, '.'));
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        cin >> v[i][j];
      }
    }
    bool impossible = false;
    for (int i = 0; !impossible and i < r; ++i) {
      for (int j = 0; !impossible and j < c; ++j) {
        if (v[i][j] == '#') {
          if (v[i+1][j] == '.' or v[i+1][j+1] == '.' or v[i][j+1] == '.') {
            impossible = true;
          }
          else {
            v[i][j] = '/';
            v[i+1][j] = '\\';
            v[i+1][j+1] = '/';
            v[i][j+1] = '\\';
          }
        }
      }
    }
    cout << "Case #" << cas << ":" << endl;
    if (impossible) cout << "Impossible" << endl;
    else {
      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
          cout << v[i][j];
        }
        cout << endl;
      }
    }
  }
}
