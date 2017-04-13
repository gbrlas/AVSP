#include <iostream>
#include <iomanip>

using namespace std;

int T;

int N;
char m[100][100];
double wp[100];
double owp[100];
double oowp[100];

void solve() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      m[i][j] = ' ';
      while (m[i][j] != '0' && m[i][j] != '1' && m[i][j] != '.') {
        cin >> m[i][j];
      }
    }
  }
  for (int i = 0; i < N; i++) {
    int nbplayer = 0;
    int nbwin = 0;
    for (int j = 0; j < N; j++) {
      if (m[i][j] == '0' || m[i][j] == '1') nbplayer++;
      if (m[i][j] == '1') nbwin++;
    }
    wp[i] = ((double) nbwin) / ((double) nbplayer);
  }
  for (int k = 0; k < N; k++) {
    double swp = 0;
    int nbopponent = 0;
    for (int i = 0; i < N; i++) {
      if (m[k][i] == '.') continue;
      nbopponent++;
      int nbplayer = 0;
      int nbwin = 0;
      for (int j = 0; j < N; j++) {
        if (j == k) continue;
        if (m[i][j] == '0' || m[i][j] == '1') nbplayer++;
        if (m[i][j] == '1') nbwin++;
      }
      swp += ((double) nbwin) / ((double) nbplayer);
    }
    owp[k] = swp / nbopponent;
  }
  for (int i = 0; i < N; i++) {
    oowp[i] = 0;
    int nbopponent = 0;
    for (int j = 0; j < N; j++) {
      if (m[i][j] == '.') continue;
      oowp[i] += owp[j];
      nbopponent++;
    }
    oowp[i] /= nbopponent;
  }
  cout << fixed << setprecision(8);
  for (int i = 0; i < N; i++) {
    cout << (0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp[i]) << endl;
  }
}

int main() {
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ":" << endl;
    solve();
  }
  return 0;
}

