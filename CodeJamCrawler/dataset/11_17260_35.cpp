#include <iostream>
#include <vector>

using namespace std;

int c, d;
vector<pair<double, int> > v;

double abs(double a) {
  if (a < 0) return -a;
  return a;
}

bool pot(double t) {
  double pos = -10000000;
  for (int i = 0; i < c; ++i) {
    for (int j = 0; j < v[i].second; ++j) {
      if (pos + d > v[i].first + t) return false;
      if (pos + d > v[i].first - t) pos += d;
      else pos = v[i].first - t;
    }
  }
  return true;
}

int main() {
  cout.setf(ios::fixed);
  cout.precision(6);
  int t;
  cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    cout << "Case #" << cas << ": ";
    cin >> c >> d;
    v = vector<pair<double, int> >(c);
    for (int i = 0; i < c; ++i) {
      cin >> v[i].first;
      cin >> v[i].second;
    }
    sort(v.begin(), v.end());
    double inft = 0;
    double supt = -1;
    double t = 10;
    while (abs(supt-inft) > 0.000001) {
      if (pot(t)) {
        supt = t;
        t = (inft+t)/2;
      }
      else {
        inft = t;
        if (supt == -1) t *= 2;
        else t = (supt+t)/2;
      }
    }
    cout << t << endl;
  }
}
