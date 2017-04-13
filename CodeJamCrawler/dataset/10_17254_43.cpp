#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    int N, K;
    cin >> N >> K;
    cout << "Case #" << i+1 << ": ";
    int a = 1<<N;
    a--;
    if (a > K) cout << "OFF" << endl;
    else {
      while (a < K) K -= (a+1);
      if (a == K) cout << "ON" << endl;
      else cout << "OFF" << endl;
    }
  }
}
