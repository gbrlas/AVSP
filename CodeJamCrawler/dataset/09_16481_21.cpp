#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>


using namespace std;

typedef vector<int> VI;

#define For(i,n) for(int i=0;i<(n);++i)

double sol(VI x, VI y, VI R, int k1, int k2, int otro) {
  double s1 = (R[k1]+R[k2]+sqrt(double((x[k1]-x[k2])*(x[k1]-x[k2])+(y[k1]-y[k2])*(y[k1]-y[k2]))))/2.0;
  return max(s1, double(R[otro]));
}


int main() {
    cout.setf(ios::fixed);
  int NN;
  cin >> NN;
  For(caso, NN) {
    cout << "Case #" << (caso+1) << ": ";
    int N;
    cin >> N;
    vector<int> x(N), y(N), R(N);
    For(i, N) cin >> x[i] >> y[i] >> R[i];

    if (N == 1) cout << R[0] << endl;
    else if (N == 2) cout << max(R[0], R[1]) << endl;
    else {
      double s = min(sol(x,y,R,0,1,2),
                     min(sol(x,y,R,1,2,0),
                         sol(x,y,R,2,0,1)));
      //
      cout << setprecision(8) << s << endl;
      //cout << s << endl;
    }
  }

}
