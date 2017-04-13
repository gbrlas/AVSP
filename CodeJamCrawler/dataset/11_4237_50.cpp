#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  int cas = 1;
  while (t--) {
    int n;
    cin >> n;
    int a;
    int sum = 0;
    int min = 10000000;
    int x = 0;
    while (n--) {
      cin >> a;
      if (a < min) min = a;
      sum += a;
      x ^= a;
    }
    if (x == 0) {
      cout << "Case #"<< cas << ": " << sum - min<<endl; 
    } else {
      cout << "Case #"<< cas << ": NO"<<endl; 
    }
    cas++;

  }
  return 0;
}
