#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BigInt {
 public:
  BigInt();
  BigInt(string s);
  BigInt(const BigInt& bi);
  void Minus(const BigInt& num);
  void Mod(const BigInt& num);
  int Cmp(const BigInt& num);
  bool IsZero() const;
  void Print();
 private:
  vector<int> data;
};

BigInt::BigInt() {
  data.clear();
}
BigInt::BigInt(string s) {
  for (int pos = s.size() - 1; pos >= 0; --pos) {
    int num = s[pos] - '0';
    data.push_back(num);
  }
}
BigInt::BigInt(const BigInt& bi) {
  data = bi.data;
}
void BigInt::Minus(const BigInt& num) {
  int left = 0;
  for (int i = 0; i < data.size(); ++i) {
    int m;
    if (i >= num.data.size()) {
      m = 0;
    } else {
      m = num.data[i];
    }
    data[i] = data[i] - m + left;
    if (data[i] < 0) {
      data[i] += 10;
      left = -1;
    } else {
      left = 0;
    }
  }
  while (data.size() > 1 && data[data.size() - 1] == 0) data.pop_back();
}

bool BigInt::IsZero() const {
  if (data.size() == 1 && data[0] == 0) return true;
  return false;
}
void BigInt::Mod(const BigInt& num) {
  do {
    int c = Cmp(num);
    if (c == 0) {
      data.clear();
      data.push_back(0);
      return;
    }
    if (c < 0) return;
    if (data.size() <= num.data.size() + 1) {
      Minus(num);
    } else {
      BigInt bi;
      for (int i = 0; i < data.size() - num.data.size() - 1; ++i) {
        bi.data.push_back(0);
      }
      for (int i = 0; i < num.data.size(); ++i) bi.data.push_back(num.data[i]);
      Minus(bi);
    }
  } while(true);
}

int BigInt::Cmp(const BigInt& num) {
  if (data.size() != num.data.size()) {
    return data.size() - num.data.size();
  }
  for (int i = data.size() - 1; i >= 0; --i) {
    if (data[i] != num.data[i]) {
      return data[i] - num.data[i];
    }
  }
  return 0;
}


void BigInt::Print() {
  for (int i = data.size() - 1; i >= 0; --i) {
    cout << data[i];
  }
}

BigInt cal2(BigInt x, BigInt y) {
  do {
    int c = x.Cmp(y);
    if (c == 0) return x;
    if (c > 0) {
      x.Mod(y);
      if (x.IsZero()) {
        return y;
      }
    }
    else {
      y.Mod(x);
      if (y.IsZero()) {
        return x;
      }
    }
  } while(true);
}

BigInt cal(vector<BigInt>& timelist) {
  vector<BigInt> difflist;
  for (int i = 1; i < timelist.size(); ++i) {
    int c = timelist[i].Cmp(timelist[i-1]);
    if (c > 0) {
      BigInt bi(timelist[i]);
      bi.Minus(timelist[i-1]);
      difflist.push_back(bi);
    } else if (c < 0) {
      BigInt bi(timelist[i-1]);
      bi.Minus(timelist[i]);
      difflist.push_back(bi);
    }
  }
  for (int i = 1; i < difflist.size(); ++i) {
    difflist[0] = cal2(difflist[0], difflist[i]);
  }
  timelist[0].Mod(difflist[0]);
  BigInt& m = timelist[0];
  if (m.IsZero()) {
    return m;
  } else {
    difflist[0].Minus(m);
    return difflist[0];
  }
}

int main(int argc, char* argv[]) {
  ifstream in(argv[1]);
  int c;
  in >> c;
  for (int i = 0; i < c; ++i) {
    int n;
    in >> n;
    vector<BigInt> timelist;
    for (int j = 0; j < n; ++j) {
      string s;
      in >> s;
      timelist.push_back(BigInt(s));
    }
    BigInt bi = cal(timelist);
    cout << "Case #" << i+1 << ": ";
    bi.Print();
    cout << "\n";
  }
  return 0;
}
