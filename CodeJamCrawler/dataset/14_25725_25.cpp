#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;

typedef long long ll;

template<class T> ostream& operator<<(ostream& os, vector<T> v) {
  for(T x : v) os << x << ", ";
  return os;
}

double solve(double C, double F, double X) {

  double t = 0;
  double power = 2;

  double ans = 1e100;

  rep(_, 100000) {
    double time_no_buy = X / power;
    ans = min(ans, t + time_no_buy);

    double to_next_time_buy = C / power;
    t += to_next_time_buy;
    power += F;
  }

  return ans;

}

int main() {

  int T;
  cin >> T;

  rep(t, T) {

    double C, F, X;
    cin >> C >> F >> X;

    cout << fixed << setprecision(8) << "Case #" << (t+1) << ": " << solve(C, F, X) << endl;
  }

  return 0;
}
