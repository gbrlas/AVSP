#include <iostream>
#include <gmpxx.h>

using namespace std;

mpz_class euclid(mpz_class a, mpz_class b) {
  if (b == 0)
    return a;
  mpz_class r;
  while ((r = a % b) != 0) {
    a = b;
    b = r;
  }
  return b;
}

int main(int argc, char** argv) {
  int c;
  cin >> c;
  for (int i = 0; i != c; ++i) {
    int n;
    string a, b;
    mpz_class s, t;
    cin >> n >> a >> b;
    s = a; t = b;
    mpz_class hcf = abs(s - t);
    for (int j = 2; j != n; ++j) {
      s = t;
      cin >> b;
      t = b;
      hcf = euclid(hcf, abs(s - t));
    }
    mpz_class y = hcf - t % hcf;
    if (y == hcf)
      y = 0;
    cout << "Case #" << (i + 1) << ": " << y.get_str() << endl;
  }
}
