#include <iostream>
#include <vector>
using namespace std;

int main() {
  cout.setf(ios::fixed);
  cout.precision(6);
  
  int t;
  cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    cout << "Case #" << cas << ":" << endl;
    int n;
    cin >> n;
    vector<vector<double> > v(n, vector<double>(3, 0));
    vector<vector<char> > matrix(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
      int g = 0;
      int j = 0;
      for (int k = 0; k < n; ++k) {
        cin >> matrix[i][k];
        if (matrix[i][k] == '1') {
          ++g;
          ++j;
        }
        else if (matrix[i][k] == '0') ++j;
      }
      v[i][0] = (double)g/(j-1);
      v[i][1] = (double)(g-1)/(j-1);
      v[i][2] = (double)g/j;
    }
    vector<double> owp(n);
    for (int i = 0; i < n; ++i) {
      double wp = 0;
      int j = 0;
      for (int k = 0; k < n; ++k) {
        if (matrix[k][i] == '0') {
          wp += v[k][0];
          ++j;
        }
        else if (matrix[k][i] == '1') {
          wp += v[k][1];
          ++j;
        }
      }
      owp[i] = (double)wp/j;
    }
    vector<double> oowp(n);
    for (int i = 0; i < n; ++i) {
      double aux = 0;
      int j = 0;
      for (int k = 0; k < n; ++k) {
        if (matrix[i][k] != '.') {
          aux += owp[k];
          ++j;
        }
      }
      oowp[i] = (double)aux/j;
    }
    for (int i = 0; i < n; ++i) {
      cout << 0.25*v[i][2] + 0.5*owp[i] + 0.25*oowp[i] << endl;
    }
  }
}







/*
2
3
.10
0.1
10.
4
.11.
0.00
01.1
.10.


	Case #1:
0.5
0.5
0.5
Case #2:
0.645833333333
0.368055555556
0.604166666667
0.395833333333
*/
