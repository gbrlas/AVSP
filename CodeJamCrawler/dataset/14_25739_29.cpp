#include <iostream>
#include <vector>
#include <algorithm>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;

int solve(int X, vector<int> S) {
  int ans = 0;
  int n = S.size();

  sort(S.begin(), S.end());

  vector<bool> used(n, false);

  int r = n - 1;

  for(int i = 0; i < n; i++) {
    if(used[i]) continue;
    while(r > i && (used[r] || S[i] + S[r] > X)) r--;
    if(r <= i) {
      ans++;
      continue;
    }
    used[r] = true;
    ans++;
  }

  //rep(i, n) cerr << used[i] << ", " << endl;

  return ans;
}

int main() {

  int T;
  cin >> T;

  rep(t, T) {
    int N, X;
    cin >> N >> X;
    vector<int> S(N);
    rep(i, N) {
      cin >> S[i];
    }

    cout << "Case #" << (t+1) << ": " << solve(X, S) << endl; 
  }

  return 0;
}
