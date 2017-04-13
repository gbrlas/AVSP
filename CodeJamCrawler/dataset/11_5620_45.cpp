#include <iostream>
using namespace std;

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int n; cin >> n;
    string who;
    int b, w, ftime = 0, last[2], time[2];
    last[0] = last[1] = 1;
    time[0] = time[1] = 0;
    for (int i = 0; i < n; i++) {
      int b, w;
      cin >> who >> b;
      if (who[0] == 'O') w = 0;
      else w = 1;
      int ct = max(abs(b - last[w]) - time[w], 0);
      ftime += ct + 1;
      time[1 - w] += ct + 1;
      time[w] = 0;
      last[w] = b;
    }
    cout << "Case #" << t << ": " << ftime << endl;
  }
  return 0;
}
