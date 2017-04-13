#include <iostream>
#include <cmath>

using namespace std;

int leftMost(int n) {
  int ret = 1;
  while (n % 2) {
    n >>= 1;
    ret++;
  }
  //cout << " " << ret << endl;
  return ret;
}

int main() {
  int T, N, K;

  cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    cin >> N >> K;
    K %= (int)pow(2.0, N);
    //cout << N << " " << K << endl;
    if (leftMost(K) > N) cout << "ON";
    else cout << "OFF";
    cout << endl;
  }

  return 0;
}
