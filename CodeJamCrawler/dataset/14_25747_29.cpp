#include <iostream>
#include <vector>
#include <algorithm>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;

bool lessthan(pair<int, int> x, pair<int, int> y) {
  if(x.first != y.first) {
    return x.first <= y.first;
  }
  if(x.first == 0) {
    return x.second <= y.second;
  }
  if(x.first == 1) {
    throw "unko";
    cerr << x.second << ", " << y.second << endl;
    if(x.second != y.second) throw "unko";
    return true;
  }
  if(x.first == 2) {
    return x.second >= y.second;
  }
  throw "unko";
}

int mergecount(vector<pair<int, int> > &a) {
  int count = 0;
  int n = a.size();
  if (n > 1) {
    vector<pair<int, int> > b(a.begin(), a.begin() + n/2);
    vector<pair<int, int> > c(a.begin() + n/2, a.end());
    count += mergecount(b);
    count += mergecount(c);
    for (int i = 0, j = 0, k = 0; i < n; ++i)
      if (k == (int)c.size()) {
	a[i] = b[j++];
      }
      else if (j == (int)b.size()) {
	a[i] = c[k++];
      }
      else if (lessthan(b[j], c[k])) {
	a[i] = b[j++];
      }
      else { 
	a[i] = c[k++];
	count += n/2 - j;
      }
  }
  return count;
}

int solve(vector<int> A) {

  int ans = 1 << 27;
  int n = A.size();

  int maxIndex = 0;
  rep(i, n) {
    if(A[i] > A[maxIndex]) maxIndex = i;
  }

  rep(mask, 1 << n) {
    vector<pair<int, int> > B(n);
    rep(i, n) {
      int flg = (i == maxIndex) ? 1 : ((mask >> i) & 1) ? 2 : 0;
      B[i] = make_pair(flg, A[i]);
    }

    ans = min(ans, mergecount(B));

    //cerr << ans << endl;
  }

  return ans;
}

int main() {

  int T;
  cin >> T;

  rep(t, T) {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) {
      cin >> A[i];
    }

    cout << "Case #" << (t+1) << ": " << solve(A) << endl; 
  }

  return 0;
}
