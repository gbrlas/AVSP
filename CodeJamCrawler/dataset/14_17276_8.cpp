#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<bool> e;
const int T = 1e6 + 10;

void era() {
  e = vector<bool>(T, 1);
  e[0] = e[1] = 0;
  for (int i = 2; i < e.size(); ++i) {
    if (e[i]) {
      for (int j = i+i; j < e.size(); j += i) e[j] = 0;
    }
  }
}

int main2(int p, int q) {
  if (p > q) return -1;
  
  for (int i = 2; i*i <= p; ++i) {
    if (e[i]) {
      while (p%i == 0 and q%i == 0) {
        p /= i;
        q /= i;
      }
    }
  }
  if (q%p == 0) {
    q /= p;
    p /= p;
  }
  
  int aux = q;
  while (aux%2 == 0) {
    aux /= 2;
  }
  if (aux != 1) return -1;
  
//   cout << p << ' '  << q << endl;
  
  int k = 1;
  double r = (double)p/(double)q;
  while (r < 0.5) {
    ++k;
    r*=2;
  }
  return k;
}

void read() {
  int p, q;
  char c;
  cin >> p >> c >> q;
  int a = main2(p, q);
  if (a == -1) cout << "impossible" << endl;
  else cout << a << endl;
}

int main() {
  era();
  int casos;
  cin >> casos;
  for (int cas = 1; cas <= casos; ++cas) {
    cout << "Case #" << cas << ": ";
    read();
  }
}
