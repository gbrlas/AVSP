#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  int t;
  cin >> t;
  for(int i = 0; i != t; ++i) {
    int n, k;
    cin >> n >> k;
    int mask = (1 << n) - 1;
    bool on = (k & mask) == mask;
    cout << "Case #" << (i + 1) << ": " << (on ? "ON" : "OFF") << endl;
  }
}
