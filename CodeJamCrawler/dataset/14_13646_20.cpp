#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 28;

struct BIT {
  int n;
  vector<int> a;
  BIT(int n) : n(n), a(n + 1, 0) {};
  void add(int k, int v) {
    while (k <= n) {
      a[k] += v;
      k += k & -k;
    }
  }
  int sum(int k) {
    int s = 0;
    while (k > 0) {
      s += a[k];
      k -= k & -k;
    }
    return s;
  }
};

int N;

int compress_l(vector<int> &a) {
  vector<int> s = a;
  sort(s.begin(), s.end());
  for (int i = 0; i < (int)a.size(); i++) {
    a[i] = lower_bound(s.begin(), s.end(), a[i]) - s.begin() + 1;
  }
  return s.size();
}

int compress_g(vector<int> &a) {
  vector<int> s = a;
  sort(s.begin(), s.end(), greater<int>());
  for (int i = 0; i < (int)a.size(); i++) {
    a[i] = lower_bound(s.begin(), s.end(), a[i], greater<int>()) - s.begin() + 1;
  }
  return s.size();
}

int solve(const vector<int> &a) {
  int m = a.size();
  int r = 0;
  BIT bit(m);
  for (int i = 0; i < m; i++) {
    r += i - bit.sum(a[i]);
    bit.add(a[i], 1);
  }
  return r;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    compress_l(a);
    int r = INF;
    for (int k = 0; k < (1 << N); k++) {
      vector<int> a1;
      for (int i = 0; i < N; i++) {
        a1.push_back((k & (1 << i)) ? a[i] : N + (N + 1 - a[i]));
      }
      compress_l(a1);
      r = min(r, solve(a1));
    }
    cout << r << endl;
  }
}