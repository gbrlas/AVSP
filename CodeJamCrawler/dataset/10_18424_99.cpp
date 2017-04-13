#include <fstream>
#include <iostream>

using namespace std;

bool cal(int n, int k) {
  for (int i = 0; i < n; ++i) {
    if (k & 1) {
      k = k >> 1;
    } else {
      return false;
    }
  }
  return true;
}

int main(int argc, char* argv[]) {
  ifstream in(argv[1]);
  int t;
  in >> t;
  for (int i = 0; i < t; ++i) {
    int n, k;
    in >> n >> k;
    bool b = cal(n, k);
    if (b) {
      cout << "Case #" << i+1 << ": ON\n";
    } else {
      cout << "Case #" << i+1 << ": OFF\n";
    }
  }
  return 0;
}
