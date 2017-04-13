#include <iostream>
#include <string>
using namespace std;

int main()
{
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int N, K;
    cin >> N >> K;

    int v = 1 << N;
    K %= v;
    cout << "Case #" << i + 1 << ": " << (K == v - 1 ? "ON" : "OFF") << endl;
  }
  return 0;
}
