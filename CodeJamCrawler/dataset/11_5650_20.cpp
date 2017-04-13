#include <iostream>
using namespace std;

bool replace (int r, int c, string v[]) {
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
      if (v[i][j] == '#') {
        if (j + 1 < c && i + 1 < r &&
            v[i][j + 1] == '#' && v[i + 1][j] == '#' && v[i + 1][j + 1] == '#') {
            v[i][j] = '/';
            v[i][j + 1] = '\\';
            v[i + 1][j] = '\\';
            v[i + 1][j + 1] = '/';
          }
        else return false;
      }
  return true;
}

int main() {
  int T; cin >> T;
  for (int t = 0; t < T; t++) {
    int r, c; cin >> r >> c;
    string v[r];
    for (int i = 0; i < r; i++)
      cin >> v[i];
    cout << "Case #" << t + 1 << ":\n";
    if (!replace(r, c, v))
      cout << "Impossible" << endl;
    else
      for (int i = 0; i < r; i++)
        cout << v[i] << endl;
  }
  return 0;
}
