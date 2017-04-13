#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct W {
  double l;
  double s;
};

bool operator < (const W &a, const W &b) {
  return a.s < b.s;
}

int C;
double X;
double S;
double R;
double T;
int N;

W a[1001];

double walk(const W &w, double &T) {
  if (T * (w.s + R) < w.l) {
    double time = T + (w.l - T * (w.s + R)) / (w.s + S);
    T = 0;
    return time;
  }
  double time = w.l / (w.s + R);
  T -= time;
  return time;
}

void solve() {
  cin >> X >> S >> R >> T >> N;
  for (int i = 0; i < N; i++) {
    double B;
    double E;
    double speed;
    cin >> B >> E >> speed;
    a[i].l = E - B;
    a[i].s = speed;
    X -= a[i].l;
  }
  a[N].l = X;
  a[N].s = 0;
  N++;
  sort(a, a + N);
  double ret = 0;
  for (int i = 0; i < N; i++) {
    ret += walk(a[i], T);
  }
  cout << ret;
}

int main() {
  cout << fixed << setprecision(16);
  cin >> C;
  for (int i = 1; i <= C; i++) {
    cout << "Case #" << i << ": ";
    solve();
    cout << endl;
  }
}

