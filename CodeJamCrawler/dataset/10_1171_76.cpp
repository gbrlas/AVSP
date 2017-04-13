#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

#define WIDTH 9

using namespace std;

class BigNum {
  public:
    string stringNum;
    int subNum[6];
    int subN;

    BigNum() {
      clear();
      subN = 0;
    }

    void clear() {
      memset(subNum, 0, sizeof(subNum));
    }

    void setSubN() {
      subN = 5;
      while (subN && !subNum[subN]) subN--;
    }

    void toSubNum() {
      clear();

      int len = stringNum.length();
      int start = len % WIDTH;
      subN = len / WIDTH;
      if (start == 0) {
        start = WIDTH;
        subN--;
      }

      string tmp = stringNum.substr(0, start);
      subNum[subN] = atoi(tmp.c_str());
      for (int i = subN - 1; i >= 0; --i) {
        tmp = stringNum.substr(start, WIDTH);
        start += WIDTH;
        subNum[i] = atoi(tmp.c_str());
      }
    }

    bool isZero() {
      for (int i = subN; i >= 0; --i)
        if (subNum[i]) return false;
      return true;
    }

    bool operator>=(const BigNum& b) {
      if (subN > b.subN) return true;
      else if (subN < b.subN) return false;
      else {
        for (int i = subN; i >= 0; --i) {
          if (subNum[i] > b.subNum[i]) return true;
          else if (subNum[i] < b.subNum[i]) return false;
        }
        return true;
      }
    }

    void minus(const BigNum& b) {
      for (int i = 0; i <= subN; ++i) {
        subNum[i] -= b.subNum[i];
        if (subNum[i] < 0) {
          subNum[i] += (int) pow(10.0, WIDTH);
          subNum[i+1]--;
        }
      }
      setSubN();
    }

    void dump() {
      printf("%d", subNum[subN]);
      for (int i = subN - 1; i >= 0; --i)
        printf("%09d", subNum[i]);
    }
};

void gcd(BigNum& a, BigNum& b) {
  while (!b.isZero()) {
    while (a >= b) {
      a.minus(b);
      if (a.isZero()) break;
    }
    swap(a, b);
  }
}

int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

void difference(BigNum& a, BigNum& b, BigNum& result) {
  if (a >= b) {
    result = a;
    result.minus(b);
  } else {
    result = b;
    result.minus(a);
  }
  /*
     a.dump(); cout << " - ";
     b.dump(); cout << " = ";
     result.dump(); cout << endl;*/
}

int main() {
  int caseN, N;
  cin >> caseN;

  for (int i = 1; i <= caseN; ++i) {
    cout << "Case #" << i << ": " ;
    cin >> N;

    BigNum a, b, gcdNum, tmp;

    // first 1
    cin >> a.stringNum;
    a.toSubNum();

    cin >> b.stringNum;
    b.toSubNum();

    difference(a, b, gcdNum);

    // remain
    for (int i = 2; i < N; ++i) {
      a = b;
      cin >> b.stringNum;
      b.toSubNum();

      difference(a, b, tmp);
      gcd(gcdNum, tmp);
    }

    while (b >= gcdNum) {
      b.minus(gcdNum);
      if (b.isZero()) break;
    }

    if (b.isZero()) cout << "0";
    else {
      gcdNum.minus(b);
      gcdNum.dump();
    }

    cout << endl;
  }

  return 0;
}

