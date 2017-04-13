#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int T;

double D;
int C;
int N;

double a[1000000];
double q[1000000];

void solve() {
  cin >> C;
  cin >> D;
  N = 0;
  for (int i = 0; i < C; i++) {
    int P, V;
    cin >> P >> V;
    for (int j = 0; j < V; j++) {
      a[N] = (double) P;
      N++;
    }
  }
  sort(a, a + N);
  double l = 0.;
  double r = ((double) D) * ((double) N);
  while (l + 1E-6 < r) {
    double t = (l + r) / 2;
    q[0] = a[0] - t;
    bool bj = true;
    for (int i = 1; i < N; i++) {
      if (q[i - 1] + D < a[i] - t)
        q[i] = a[i] - t;
      else
        q[i] = q[i - 1] + D;
      if (q[i] > a[i] + t) {
        bj = false;
        break;
      }
    }
    if (bj) r = t; else l = t;
  }
  cout << fixed << setprecision(8);
  cout << l << endl;
}

int main() {
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}

